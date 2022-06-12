/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi
** File description:
** event_channel
*/

#include <stdio.h>
#include "myteams_cli.h"
#include "logging_client.h"

void event_channel(client_t *client USELESS, char *message)
{
    char **cmd = my_str_to_word_array(message, ';');

    client_event_channel_created(cmd[0], cmd[1], cmd[2]);
    free_array(cmd);
}
