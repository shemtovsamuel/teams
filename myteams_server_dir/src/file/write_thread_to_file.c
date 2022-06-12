/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi
** File description:
** write_message_to_file.c
*/

#include "myteams_server.h"
#include "file.h"
#include "utils.h"
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

static void create_thread_file(void)
{
    int fd = open_file(THREADS_SAVE_FILE);
    char *data = "Thread_uuid;User_uuid;Thread_timestamp;Thread_title;"
        "Thread_body;Channel_uuid;Team_uuid;";

    if (fd == -1)
        return;
    write(fd, data, strlen(data));
    write(fd, "\n", strlen("\n"));
    close(fd);
}

static void write_in(int fd, thread_t thread, time_t timestamp)
{
    write(fd, thread.thread_uuid, strlen(thread.thread_uuid));
    write(fd, ";", strlen(";"));
    write(fd, thread.user_uuid, strlen(thread.user_uuid));
    write(fd, ";", strlen(";"));
    write(fd, ld_to_string(timestamp), strlen(ld_to_string(timestamp)));
    write(fd, ";", strlen(";"));
    write(fd, thread.thread_title, strlen(thread.thread_title));
    write(fd, ";", strlen(";"));
    write(fd, thread.thread_body, strlen(thread.thread_body));
    write(fd, ";", strlen(";"));
    write(fd, thread.channel_uuid, strlen(thread.channel_uuid));
    write(fd, ";", strlen(";"));
    write(fd, thread.team_uuid, strlen(thread.team_uuid));
    write(fd, "\n", strlen("\n"));
    close(fd);
}

void write_thread_to_file(thread_t thread)
{
    int fd = -1;
    time_t timestamp = time(NULL);

    if (is_file_exist(THREADS_SAVE_FILE) == false ||
        is_file_empty(THREADS_SAVE_FILE) == true)
        create_thread_file();
    fd = open_append_file(THREADS_SAVE_FILE);
    if (fd == -1)
        return;
    write_in(fd, thread, timestamp);
}