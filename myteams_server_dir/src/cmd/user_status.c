/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** user_status.c
*/

#include "struct.h"
#include <stdbool.h>
#include <string.h>

bool is_user_online(user_t user, server_t *server)
{
    for (int i = 0; i < server->nb_clients; i++)
        if (server->arr_clients[i].logged &&
            strcmp(server->arr_clients[i].user_uuid, user.user_uuid) == 0)
            return (server->arr_clients[i].logged);
    return (false);
}