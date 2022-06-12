/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** create_reply.c
*/

#include "myteams_server.h"
#include "logging_server.h"
#include "file.h"
#include "utils.h"
#include "cmd.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

static char *create_event_message_for_client(reply_t reply)
{
    char *msg = malloc(sizeof(char) * (strlen("/event_reply")
        + strlen(reply.thread_uuid) + strlen(reply.reply_body)
        + strlen(reply.user_uuid) + strlen(reply.team_uuid) + 8 + 1));

    if (msg == NULL)
        return (NULL);
    sprintf(msg, "/event_reply;%s;%s;%s;%s;\r\n", reply.team_uuid,
        reply.thread_uuid, reply.user_uuid, reply.reply_body);
    return (msg);
}

static char *create_message_for_client(reply_t reply)
{
    char *msg = malloc(sizeof(char) * (strlen("/create_reply")
        + strlen(reply.thread_uuid) + strlen(reply.reply_body)
        + strlen(reply.user_uuid) + 100 + 2 + 1));

    if (msg == NULL)
        return (NULL);
    sprintf(msg, "/create_reply;%s;%s;%ld;%s;\r\n", reply.thread_uuid,
        reply.user_uuid, reply.reply_timestamp, reply.reply_body);
    return (msg);
}

static void send_to_clients(server_t *server, client_t *client,
    reply_t reply)
{
    write_reply_to_file(reply);
    add_to_client_queue(client, create_message_for_client(reply), false);
    for (int i = 0; i < server->nb_clients; i++) {
        if (server->arr_clients[i].logged && is_user_subscribe(
            server->arr_clients[i].user_uuid, client->team_uuid))
            add_to_client_queue(&server->arr_clients[i],
                create_event_message_for_client(reply), false);
    }
}

static int check_error_reply(client_t *client, char **arr)
{
    if (arr == NULL || get_array_size(arr) < 1)
        return (-1);
    if (!is_team_exist(client->team_uuid)) {
        add_to_client_queue(client, "/team_unknown\r\n", false);
        return (-1);
    }
    if (!is_channel_exist(client->channel_uuid)) {
        add_to_client_queue(client, "/channel_unknown\r\n", false);
        return (-1);
    }
    if (!is_thread_exist(client->thread_uuid)) {
        add_to_client_queue(client, "/thread_unknown\r\n", false);
        return (-1);
    }
    return (0);
}

void create_reply(server_t *server, client_t *client, char *data)
{
    char **arr = my_str_to_word_array(data, ';');

    if (check_error_reply(client, arr) == -1)
        return;
    server_event_reply_created(client->thread_uuid, client->user_uuid, arr[0]);
    send_to_clients(server, client, (reply_t){.thread_uuid =
        client->thread_uuid, .user_uuid = client->user_uuid,
        .team_uuid = client->team_uuid, .reply_body = arr[0],
        .reply_timestamp = time(NULL)});
    free_array(arr);
}