/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi
** File description:
** user.c
*/

#include "myteams_server.h"
#include "struct.h"
#include "file.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static char *user_not_found(char *user_uuid)
{
    char *msg = NULL;
    char *error = "/user_not_found";

    msg = malloc(sizeof(char) * (strlen(user_uuid) +
        strlen(error) + 1 + 4));
    if (msg == NULL)
        return (NULL);
    sprintf(msg, "%s;%s;\r\n", error, user_uuid);
    return (msg);
}

static char *user_found(user_t user, server_t *server)
{
    char *msg = NULL;
    char *cmd = "/user";
    char status = '0';

    msg = malloc(sizeof(char) * (strlen(user.user_uuid) +
        strlen(user.user_name) + strlen(cmd) + 1 + 6));
    if (msg == NULL)
        return (NULL);
    for (int i = 0; i < server->nb_clients; i++)
        if (strcmp(server->arr_clients[i].user_uuid, user.user_uuid) == 0)
            status = server->arr_clients[i].logged ? '1' : '0';
    sprintf(msg, "%s;%s;%s;%c;\r\n", cmd, user.user_uuid, user.user_name,
        status);
    return (msg);
}

void user(server_t *server, client_t *client, char *data)
{
    user_t user = {0};

    if (data == NULL) {
        add_to_client_queue(client, "/user_not_found;null;\r\n", false);
        return;
    }
    user = load_user_from_file_by_uuid(data);
    if (user.user_name == NULL) {
        add_to_client_queue(client, user_not_found(data), false);
        return;
    }
    add_to_client_queue(client, user_found(user, server), false);
}