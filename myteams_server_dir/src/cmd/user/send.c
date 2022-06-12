/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** send.c
*/

#include "struct.h"
#include "myteams_server.h"
#include "logging_server.h"
#include "utils.h"
#include "file.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static char *create_message(char *sender, char *message)
{
    char *msg = NULL;
    char *cmd = "/send";

    msg = malloc(sizeof(char) * (strlen(sender) + 1 + strlen(cmd) + 1 +
        strlen(message) + 4));
    if (msg == NULL)
        return (NULL);
    sprintf(msg, "%s;%s;%s;\r\n", cmd, sender, message);
    return (msg);
}

void send_cmd(server_t *server, client_t *client, char *data)
{
    char **message = my_str_to_word_array(data, ';');

    write_message_to_file(client->user_uuid, message[0], message[1]);
    for (int i = 0; i < server->nb_clients; ++i) {
        if (strcmp(server->arr_clients[i].user_uuid, message[0]) == 0) {
            add_to_client_queue(&server->arr_clients[i],
                create_message(client->user_uuid, message[1]), false);
            break;
        }
    }
    server_event_private_message_sended(client->user_uuid, message[0],
        message[1]);
    free_array(message);
}