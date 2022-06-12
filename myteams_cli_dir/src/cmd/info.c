/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi
** File description:
** info.c
*/

#include <stdio.h>
#include "myteams_cli.h"
#include "logging_client.h"

void info_user(client_t *client USELESS, char *message)
{
    char **cmd = my_str_to_word_array(message, ';');

    client_print_user(cmd[0], cmd[1], cmd[2][0] == '1' ? 1 : 0);
    free_array(cmd);
}

void info_team(client_t *client USELESS, char *message)
{
    char **cmd = my_str_to_word_array(message, ';');

    client_print_team(cmd[0], cmd[1], cmd[2]);
    free_array(cmd);
}

void info_channel(client_t *client USELESS, char *message)
{
    char **cmd = my_str_to_word_array(message, ';');

    client_print_channel(cmd[0], cmd[1], cmd[2]);
    free_array(cmd);
}

void info_thread(client_t *client USELESS, char *message)
{
    char **cmd = my_str_to_word_array(message, ';');

    client_print_thread(cmd[0], cmd[1], convert_to_time_t(cmd[2]), cmd[3],
        cmd[4]);
    free_array(cmd);
}
