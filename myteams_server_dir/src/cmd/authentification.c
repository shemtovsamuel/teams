/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myftp-william.karkegi
** File description:
** authentification.c
*/

#include "myteams_server.h"
#include <stdlib.h>
#include <string.h>

void reset_client_security(client_t *client)
{
    if (client->user_name)
        free(client->user_name);
    client->user_name = NULL;
}

void verify_user(client_t *client, user_t *user USELESS)
{
    if (true) {
        client->logged = true;
        add_to_client_queue(client, "230 User logged in, proceed.\r\n", false);
    } else {
        reset_client_security(client);
        add_to_client_queue(client, "530 Login incorrect.\r\n", false);
    }
}

void authentification(client_t *client, user_t *users, int index)
{
    for (int i = 0; i < index; ++i)
        if (!strcasecmp(client->user_name, users[i].user_name)) {
            verify_user(client, &users[i]);
            return;
        }
    reset_client_security(client);
    add_to_client_queue(client, "530 Login incorrect.\r\n", false);
}