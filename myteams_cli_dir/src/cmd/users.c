/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi
** File description:
** users.c
*/

#include <stdio.h>
#include "myteams_cli.h"
#include "logging_client.h"

void users(client_t *client USELESS, char *message)
{
    char **cmd = my_str_to_word_array(message, ';');

    for (int i = 0; cmd[i]; i += 3) {
        if (!cmd[i + 1] || !cmd[i + 2])
            break;
        client_print_users(cmd[i], cmd[i + 1], cmd[i + 2][0] == '1' ? 1 : 0);
    }
    free_array(cmd);
}
