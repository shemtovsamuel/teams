/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** create.c
*/

#include "myteams_server.h"
#include "logging_server.h"
#include "file.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void create(server_t *server, client_t *client, char *data)
{
    switch (client->context) {
        case USER_CONTEXT:
            create_team(server, client, data);
            break;
        case TEAM_CONTEXT:
            create_channel(server, client, data);
            break;
        case CHANNEL_CONTEXT:
            create_thread(server, client, data);
            break;
        case THREAD_CONTEXT:
            create_reply(server, client, data);
            break;
        default:
            break;
    }
}