/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** list.c
*/

#include "myteams_server.h"

void list(server_t *server, client_t *client, char *date USELESS)
{
    switch (client->context) {
        case USER_CONTEXT:
            list_team(server, client);
            break;
        case TEAM_CONTEXT:
            list_channel(server, client);
            break;
        case CHANNEL_CONTEXT:
            list_thread(server, client);
            break;
        case THREAD_CONTEXT:
            list_reply(server, client);
            break;
        default:
            break;
    }
}
