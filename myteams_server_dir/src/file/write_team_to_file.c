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

static void create_team_file(void)
{
    int fd = open_file(TEAMS_SAVE_FILE);
    char *data = "Team_uuid;Team_name;Team_description;";

    if (fd == -1)
        return;
    write(fd, data, strlen(data));
    write(fd, "\n", strlen("\n"));
    close(fd);
}

void write_team_to_file(char *team_uuid, char *team_name,
    char *team_description)
{
    int fd = -1;

    if (is_file_exist(TEAMS_SAVE_FILE) == false ||
        is_file_empty(TEAMS_SAVE_FILE))
        create_team_file();
    fd = open_append_file(TEAMS_SAVE_FILE);
    if (fd == -1)
        return;
    write(fd, team_uuid, strlen(team_uuid));
    write(fd, ";", strlen(";"));
    write(fd, team_name, strlen(team_name));
    write(fd, ";", strlen(";"));
    write(fd, team_description, strlen(team_description));
    write(fd, ";", strlen(";"));
    write(fd, "\n", strlen("\n"));
    close(fd);
}