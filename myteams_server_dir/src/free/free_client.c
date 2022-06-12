/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myftp-william.karkegi
** File description:
** free_client.c
*/

#include "myteams_server.h"
#include "server_log.h"
#include "logging_server.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

static char *create_message_for_client(char const *user_name, char const *uuid)
{
    char *message = NULL;

    message = malloc(sizeof(char) * (strlen("/event_logout")
        + strlen(user_name) + strlen(uuid) + 3 + 10));
    check_error(message == NULL, "malloc failed");
    sprintf(message, "/event_logout;%s;%s;\r\n", uuid, user_name);
    return (message);
}

static void log_and_message(server_t *server, int id)
{
    for (int i = 0; i < server->nb_clients; ++i)
        if (server->arr_clients[i].logged &&
            server->arr_clients[i].fd != server->arr_clients[id].fd) {
            add_to_client_queue(&server->arr_clients[i],
            create_message_for_client(server->arr_clients[id].user_name,
            server->arr_clients[id].user_uuid),
            false);
        }
    if (server->arr_clients[id].user_uuid != NULL)
        server_event_user_logged_out(server->arr_clients[id].user_uuid);
}

static void free_client(client_t *client)
{
    client->user_name ? free(client->user_name) : 0;
    client->user_uuid ? free(client->user_uuid) : 0;
    client->req ? free(client->req) : 0;
    free_queue(client->queue);
}

static bool empty(server_t *server)
{
    if (server->nb_clients != 0)
        return (false);
    free_client(&server->arr_clients[0]);
    free(server->arr_clients);
    server->arr_clients = NULL;
    return (true);
}

void disconnect_client(server_t *server, int id)
{
    int new_id = 0;
    client_t *arr_clients = NULL;

    log_and_message(server, id);
    server->nb_clients--;
    if (empty(server))
        return;
    arr_clients = malloc(sizeof(client_t) * server->nb_clients);
    check_error(arr_clients == NULL, "malloc");
    for (int i = 0; i < server->nb_clients + 1; i++) {
        if (i != id) {
            memcpy(&arr_clients[new_id], &server->arr_clients[i],
                sizeof(client_t));
            new_id++;
        } else
            free_client(&server->arr_clients[i]);
    }
    free(server->arr_clients);
    server->arr_clients = arr_clients;
}
