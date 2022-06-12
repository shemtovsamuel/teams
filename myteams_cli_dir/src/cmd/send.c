/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi
** File description:
** send.c
*/

#include <stdio.h>
#include "logging_client.h"
#include "myteams_cli.h"

void send_client(client_t *client USELESS, char *message USELESS)
{
    char **cmd = my_str_to_word_array(message, ';');

    client_event_private_message_received(cmd[0], cmd[1]);
    free_array(cmd);
}
