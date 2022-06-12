/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi
** File description:
** write_message_to_file.c
*/

#include "myteams_server.h"
#include "file.h"
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

static void create_channel_file(void)
{
    int fd = open_file(CHANNELS_SAVE_FILE);

    if (fd == -1)
        return;
    write(fd, "Channel_uuid;Channel_name;Channel_description;",
        strlen("Channel_uuid;Channel_name;Channel_description;"));
    write(fd, "\n", 1);
    close(fd);
}

void write_channel_to_file(char *channel_uuid, char *channel_name,
    char *channel_description, char *team_uuid)
{
    int fd = -1;

    if (!is_file_exist(CHANNELS_SAVE_FILE)
        || is_file_empty(CHANNELS_SAVE_FILE))
        create_channel_file();
    fd = open_append_file(CHANNELS_SAVE_FILE);
    if (fd == -1)
        return;
    write(fd, channel_uuid, strlen(channel_uuid));
    write(fd, ";", strlen(";"));
    write(fd, channel_name, strlen(channel_name));
    write(fd, ";", strlen(";"));
    write(fd, channel_description, strlen(channel_description));
    write(fd, ";", strlen(";"));
    write(fd, team_uuid, strlen(team_uuid));
    write(fd, "\n", 1);
    close(fd);
}