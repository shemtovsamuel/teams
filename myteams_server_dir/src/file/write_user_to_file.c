/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** write_to_file.c
*/

#include "stdio.h"
#include "struct.h"
#include "file.h"
#include "logging_server.h"
#include <unistd.h>
#include <string.h>

static void create_users_file(void)
{
    int fd = open_file(USER_SAVE_FILE);
    char *data = "User_name;User_uuid;";

    if (fd == -1)
        return;
    write(fd, data, strlen(data));
    write(fd, "\n", 1);
    close(fd);
}

void write_user_to_file(user_t user)
{
    int fd = -1;

    if (!is_file_exist(USER_SAVE_FILE) || is_file_empty(USER_SAVE_FILE))
        create_users_file();
    fd = open_append_file(USER_SAVE_FILE);
    if (fd == -1)
        return;
    write(fd, user.user_name, strlen(user.user_name));
    write(fd, ";", 1);
    write(fd, user.user_uuid, strlen(user.user_uuid));
    write(fd, ";", 1);
    write(fd, "\n", 1);
    close(fd);
    server_event_user_created(user.user_uuid, user.user_name);
};