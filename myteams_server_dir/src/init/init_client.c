/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myftp-william.karkegi
** File description:
** init_client.c
*/

#include "myteams_server.h"
#include <stdlib.h>
#include <string.h>

void init_client(client_t *client, int client_sock)
{
    client->fd = client_sock;
    client->data_fd = -1;
    client->queue = NULL;
    client->context = USER_CONTEXT;
    client->user_name = NULL;
    client->user_uuid = NULL;
    client->req = NULL;
    client->logged = false;
}