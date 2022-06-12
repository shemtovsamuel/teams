/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi
** File description:
** logout.c
*/

#include "myteams_cli.h"
#include "logging_client.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void logout_client(client_t *client, char *message)
{
    if (message == NULL)
        return;
    if (strcmp(message, "/logout") != 0)
        return;
    if (client->logged == true)
        client_event_logged_out(client->uuid, client->user_name);
    client->logged = false;
    close(client->socket);
    exit(0);
}

void event_logout(client_t *client USELESS, char *message)
{
    char **cmd = my_str_to_word_array(message, ';');

    client_event_logged_out(cmd[0], cmd[1]);
    free_array(cmd);
}
