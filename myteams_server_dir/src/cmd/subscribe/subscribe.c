/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** subscribe.c
*/

#include "myteams_server.h"
#include "logging_server.h"
#include "file.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static char *create_message(char *user_uuid, char *team_uuid)
{
    char *message = malloc(sizeof(char) * (strlen(user_uuid)
        + strlen(team_uuid) + strlen("/subscribe") + 6));

    if (message == NULL)
        return (NULL);
    sprintf(message, "/subscribe;%s;%s;\r\n", user_uuid, team_uuid);
    return (message);
}

static void create_subscribe_file(void)
{
    int fd = open_file(SUBSCRIBE_SAVE_FILE);
    char *data = "User_uuid;Team_uuid;";

    if (fd == -1)
        return;
    write(fd, data, strlen(data));
    write(fd, "\n", strlen("\n"));
    close(fd);
}

static void write_in(int fd, char *user_uuid, char *team_uuid)
{
    write(fd, user_uuid, strlen(user_uuid));
    write(fd, ";", strlen(";"));
    write(fd, team_uuid, strlen(team_uuid));
    write(fd, ";", strlen(";"));
    write(fd, "\n", strlen("\n"));
    close(fd);
}

void subscribe(server_t *server USELESS, client_t *client, char *data)
{
    int fd = -1;
    char **arr = my_str_to_word_array(data, ';');

    if (arr == NULL)
        return;
    if (!is_team_exist(arr[0])) {
        add_to_client_queue(client, "/unknow_team;\r\n", false);
        return;
    }
    if (is_file_exist(SUBSCRIBE_SAVE_FILE) == false
        || is_file_empty(SUBSCRIBE_SAVE_FILE))
        create_subscribe_file();
    fd = open_append_file(SUBSCRIBE_SAVE_FILE);
    server_event_user_subscribed(arr[0], client->user_uuid);
    write_in(fd, client->user_uuid, arr[0]);
    add_to_client_queue(client, create_message(client->user_uuid, arr[0]),
        false);
    free_array(arr);
}