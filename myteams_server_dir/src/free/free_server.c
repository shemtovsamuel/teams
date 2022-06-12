/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myftp-william.karkegi
** File description:
** free_server.c
*/

#include "myteams_server.h"
#include <stdlib.h>
#include <unistd.h>

static void free_users(user_t *arr_users, int nb_users)
{
    if (arr_users == NULL)
        return;
    for (int i = 0; i < nb_users; i++) {
        if (arr_users[i].user_name != NULL)
            free(arr_users[i].user_name);
    }
    free(arr_users);
}

static void free_clients(client_t *arr_clients, int nb_clients)
{
    if (arr_clients == NULL)
        return;
    for (int i = 0; i < nb_clients; i++) {
        arr_clients[i].user_name ? free(arr_clients[i].user_name) : 0;
        arr_clients[i].user_uuid ? free(arr_clients[i].user_uuid) : 0;
        arr_clients[i].req ? free(arr_clients[i].req) : 0;
        free_queue(arr_clients[i].queue);
    }
    free(arr_clients);
}

void free_server(void)
{
    server_t *server = get_server_address(NULL);

    free_users(server->arr_users, server->nb_users);
    free_clients(server->arr_clients, server->nb_clients);
    close(server->fd);
}