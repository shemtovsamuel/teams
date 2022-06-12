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

static void create_message_file(void)
{
    int fd = open_file(USERS_MESSAGES_FILE);
    char *data = "Sender_uuid;Receiver_uuid;Message_timestamp;Message_body;";

    if (fd == -1)
        return;
    write(fd, data, strlen(data));
    write(fd, "\n", strlen("\n"));
    close(fd);
}

void write_message_to_file(char *sender, char *receiver, char *message)
{
    int fd = -1;
    time_t timestamp = time(NULL);

    if (is_file_exist(USERS_MESSAGES_FILE) == false ||
        is_file_empty(USERS_MESSAGES_FILE))
        create_message_file();
    fd = open_append_file(USERS_MESSAGES_FILE);
    if (fd == -1)
        return;
    write(fd, sender, strlen(sender));
    write(fd, ";", strlen(";"));
    write(fd, receiver, strlen(receiver));
    write(fd, ";", strlen(";"));
    write(fd, ld_to_string(timestamp), strlen(ld_to_string(timestamp)));
    write(fd, ";", strlen(";"));
    write(fd, message, strlen(message));
    write(fd, "\n", strlen("\n"));
    close(fd);
}