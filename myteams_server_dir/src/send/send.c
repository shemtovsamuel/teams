/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myftp-william.karkegi
** File description:
** send.c
*/

#include "myteams_server.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void send_message_to_client(server_t *server, int id)
{
    client_t *client = &server->arr_clients[id];
    queue_t *next;
    bool disconnection = client->queue->disconnect;

    write(client->fd, client->queue->data, strlen(client->queue->data));
    next = client->queue->next;
    free(client->queue->data);
    free(client->queue);
    client->queue = next;
    if (disconnection)
        disconnect_client(server, id);
}