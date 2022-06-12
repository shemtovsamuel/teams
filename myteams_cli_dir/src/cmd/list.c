/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi
** File description:
** list.c
*/

#include <stdio.h>
#include "myteams_cli.h"
#include "logging_client.h"

void list_team(client_t *client USELESS, char *message)
{
    char **cmd = my_str_to_word_array(message, ';');

    for (int i = 0; cmd[i]; i += 3) {
        if (!cmd[i + 1] || !cmd[i + 2])
            break;
        client_print_teams(cmd[i], cmd[i + 1], cmd[i + 2]);
    }
    free_array(cmd);
}

void list_channel(client_t *client USELESS, char *message)
{
    char **cmd = my_str_to_word_array(message, ';');

    for (int i = 0; cmd[i]; i += 3) {
        if (!cmd[i + 1] || !cmd[i + 2])
            break;
        client_team_print_channels(cmd[i], cmd[i + 1], cmd[i + 2]);
    }
    free_array(cmd);
}

void list_thread(client_t *client USELESS, char *message)
{
    char **cmd = my_str_to_word_array(message, ';');

    for (int i = 0; cmd[i]; i += 5) {
        if (!cmd[i + 1] || !cmd[i + 2] || !cmd[i + 3] || !cmd[i + 4])
            break;
        client_channel_print_threads(cmd[i], cmd[i + 1],
            convert_to_time_t(cmd[i + 2]), cmd[i + 3], cmd[i + 4]);
    }
    free_array(cmd);
}

void list_thread_replies(client_t *client USELESS, char *message)
{
    char **cmd = my_str_to_word_array(message, ';');

    for (int i = 0; cmd[i]; i += 4) {
        if (!cmd[i + 1] || !cmd[i + 2] || !cmd[i + 3])
            break;
        client_thread_print_replies(cmd[i], cmd[i + 1],
            convert_to_time_t(cmd[i + 3]), cmd[i + 2]);
    }
    free_array(cmd);
}
