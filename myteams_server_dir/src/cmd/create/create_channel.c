/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** create_channel.c
*/

#include "myteams_server.h"
#include "logging_server.h"
#include "file.h"
#include "utils.h"
#include "cmd.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static char *create_event_message_for_client(char const *channel_uuid,
    char const *channel_name, char const *channel_description)
{
    char *msg = malloc(sizeof(char) * (strlen("/event_channel")
        + strlen(channel_uuid)
        + strlen(channel_name) + strlen(channel_description) + 4 + 2));

    if (msg == NULL)
        return (NULL);
    sprintf(msg, "/event_channel;%s;%s;%s;\r\n", channel_uuid, channel_name,
        channel_description);
    return (msg);
}

static char *create_message_for_client(char const *channel_uuid,
    char const *channel_name, char const *channel_description)
{
    char *msg = malloc(sizeof(char) * (strlen("/create_channel")
        + strlen(channel_uuid)
        + strlen(channel_name) + strlen(channel_description) + 4 + 2));

    if (msg == NULL)
        return (NULL);
    sprintf(msg, "/create_channel;%s;%s;%s;\r\n", channel_uuid, channel_name,
        channel_description);
    return (msg);
}

static void send_to_clients(server_t *server, client_t *client, char *uuid,
    char **arr)
{
    add_to_client_queue(client, create_message_for_client(uuid, arr[0],
        arr[1]), false);
    for (int i = 0; i < server->nb_clients; i++) {
        if (server->arr_clients[i].logged && is_user_subscribe(
            server->arr_clients[i].user_uuid, client->team_uuid))
            add_to_client_queue(&server->arr_clients[i],
                create_event_message_for_client(uuid,
                    arr[0], arr[1]), false);
    }
}

void create_channel(server_t *server, client_t *client, char *data)
{
    char **arr = my_str_to_word_array(data, ';');
    char *uuid = generate_uuid();

    if (arr == NULL || get_array_size(arr) < 2)
        return;
    if (!is_team_exist(client->team_uuid)) {
        add_to_client_queue(client, "/team_unknown\r\n", false);
        return;
    }
    if (is_channel_exist_by_name(arr[0])) {
        add_to_client_queue(client, "/channel_already_exist\r\n", false);
        return;
    }
    write_channel_to_file(uuid, arr[0], arr[1], client->team_uuid);
    server_event_channel_created(client->team_uuid, uuid, arr[0]);
    send_to_clients(server, client, uuid, arr);
    free_array(arr);
}