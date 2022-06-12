/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi
** File description:
** event_reply.c
*/

#include <stdio.h>
#include "myteams_cli.h"
#include "logging_client.h"

void event_reply(client_t *client USELESS, char *message)
{
    char **cmd = my_str_to_word_array(message, ';');

    client_event_thread_reply_received(cmd[0], cmd[1], cmd[2], cmd[3]);
    free_array(cmd);
}
