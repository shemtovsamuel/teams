/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** write_reply_to_file.c
*/

#include "myteams_server.h"
#include "file.h"
#include "utils.h"
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

static void create_reply_file(void)
{
    int fd = open_file(REPLIES_SAVE_FILE);
    char *data = "Team_uuid;Thread_uuid;User_uuid;Reply_body;Reply_timestamp;";

    if (fd == -1)
        return;
    write(fd, data, strlen(data));
    write(fd, "\n", strlen("\n"));
    close(fd);
}

void write_reply_to_file(reply_t reply)
{
    int fd = -1;

    if (is_file_exist(REPLIES_SAVE_FILE) == false ||
        is_file_empty(REPLIES_SAVE_FILE))
        create_reply_file();
    fd = open_append_file(REPLIES_SAVE_FILE);
    if (fd == -1)
        return;
    write(fd, reply.team_uuid, strlen(reply.team_uuid));
    write(fd, ";", strlen(";"));
    write(fd, reply.thread_uuid, strlen(reply.thread_uuid));
    write(fd, ";", strlen(";"));
    write(fd, reply.user_uuid, strlen(reply.user_uuid));
    write(fd, ";", strlen(";"));
    write(fd, reply.reply_body, strlen(reply.reply_body));
    write(fd, ";", strlen(";"));
    write(fd, ld_to_string(reply.reply_timestamp),
        strlen(ld_to_string(reply.reply_timestamp)));
    write(fd, "\n", strlen("\n"));
    close(fd);
}