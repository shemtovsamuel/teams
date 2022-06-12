/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** error.c
*/

#include "myteams_cli.h"
#include "logging_client.h"

void unknow_team(client_t *client USELESS, char *message)
{
    char **cmd = my_str_to_word_array(message, ';');

    if (cmd[0] == NULL)
        return;
    client_error_unknown_team(cmd[0]);
    free_array(cmd);
}

void unknow_channel(client_t *client USELESS, char *message)
{
    char **cmd = my_str_to_word_array(message, ';');

    if (cmd[0] == NULL)
        return;
    client_error_unknown_channel(cmd[0]);
    free_array(cmd);
}

void unknow_thread(client_t *client USELESS, char *message)
{
    char **cmd = my_str_to_word_array(message, ';');

    if (cmd[0] == NULL)
        return;
    client_error_unknown_thread(cmd[0]);
    free_array(cmd);
}

void unknow_user(client_t *client USELESS, char *message)
{
    char **cmd = my_str_to_word_array(message, ';');

    if (cmd[0] == NULL)
        return;
    client_error_unknown_user(cmd[0]);
    free_array(cmd);
}