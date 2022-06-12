/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** logout.c
*/

#include "myteams_server.h"
#include "logging_server.h"
#include "struct.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static char *create_message_for_client(char const *user_name, char const *uuid)
{
    char *message = NULL;

    message = malloc(sizeof(char) * (strlen("/event_logout")
        + strlen(user_name) + strlen(uuid) + 3 + 3));
    check_error(message == NULL, "malloc failed");
    sprintf(message, "/event_logout;%s;%s;\r\n", uuid, user_name);
    return (message);
}

void logout(server_t *server, client_t *client, char *data USELESS)
{
    if (client->logged == false) {
        add_to_client_queue(client, "/not_logged\r\n", false);
        return;
    }
    server_event_user_logged_out(client->user_uuid);
    for (int i = 0; i < server->nb_clients; ++i)
        if (server->arr_clients[i].logged &&
            server->arr_clients[i].fd != client->fd) {
            add_to_client_queue(&server->arr_clients[i],
            create_message_for_client(client->user_name, client->user_uuid),
            false);
        }
    add_to_client_queue(client, "/logout\r\n", false);
    client->logged = false;
}