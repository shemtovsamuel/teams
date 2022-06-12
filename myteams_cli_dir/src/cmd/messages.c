/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi
** File description:
** messages.c
*/

#include <stdio.h>
#include "logging_client.h"
#include "myteams_cli.h"

void messages(client_t *client USELESS, char *message USELESS)
{
    char **cmd = my_str_to_word_array(message, ';');

    for (int i = 0; cmd[i]; i += 3) {
        if (!cmd[i + 1] || !cmd[i + 2])
            break;
        client_private_message_print_messages(cmd[i],
            convert_to_time_t(cmd[i + 1]), cmd[i + 2]);
    }
    free_array(cmd);
}
