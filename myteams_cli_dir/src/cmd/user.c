/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi
** File description:
** user.c
*/

#include <stdio.h>
#include "logging_client.h"
#include "myteams_cli.h"

void user(client_t *client USELESS, char *message)
{
    char **cmd = my_str_to_word_array(message, ';');

    client_print_user(cmd[0], cmd[1], cmd[2][0] == '1' ? 1 : 0);
    free_array(cmd);
}
