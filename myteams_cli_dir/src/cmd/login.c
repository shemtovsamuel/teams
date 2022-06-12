/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi
** File description:
** login.c
*/

#include <stdio.h>
#include <string.h>
#include "logging_client.h"
#include "myteams_cli.h"

void login(client_t *client, char *message)
{
    char **cmd = my_str_to_word_array(message, ';');

    client->logged = true;
    client->uuid = strdup(cmd[0]);
    client->user_name = strdup(cmd[1]);
    client_event_logged_in(cmd[0], cmd[1]);
    free_array(cmd);
}

void event_login(client_t *client USELESS, char *message)
{
    char **cmd = my_str_to_word_array(message, ';');

    client_event_logged_in(cmd[0], cmd[1]);
    free_array(cmd);
}