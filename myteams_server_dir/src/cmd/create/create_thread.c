/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** create_thread.c
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

static char *create_event_message_for_client(thread_t thread)
{
    char *msg = malloc(sizeof(char) * (strlen("/event_thread")
        + strlen(thread.thread_uuid) + strlen(thread.thread_body)
        + strlen(thread.user_uuid) + strlen(thread.thread_title) + 100 + 3));

    if (msg == NULL)
        return (NULL);
    sprintf(msg, "/event_thread;%s;%s;%ld;%s;%s;\r\n", thread.thread_uuid,
        thread.user_uuid, thread.thread_timestamp, thread.thread_title,
        thread.thread_body);
    return (msg);
}

static char *create_message_for_client(thread_t thread)
{
    char *msg = malloc(sizeof(char) * (strlen("/create_thread")
        + strlen(thread.thread_uuid) + strlen(thread.thread_body)
        + strlen(thread.user_uuid) + strlen(thread.thread_title) + 100 + 3));

    if (msg == NULL)
        return (NULL);
    sprintf(msg, "/create_thread;%s;%s;%ld;%s;%s;\r\n", thread.thread_uuid,
        thread.user_uuid, thread.thread_timestamp, thread.thread_title,
        thread.thread_body);
    return (msg);
}

static void send_to_clients(server_t *server, client_t *client,
    thread_t thread)
{
    write_thread_to_file(thread);
    add_to_client_queue(client, create_message_for_client(thread), false);
    for (int i = 0; i < server->nb_clients; i++) {
        if (server->arr_clients[i].logged && is_user_subscribe(
            server->arr_clients[i].user_uuid, client->team_uuid))
            add_to_client_queue(&server->arr_clients[i],
                create_event_message_for_client(thread), false);
    }
}

static int check_error_thread(client_t *client, char **arr)
{
    if (arr == NULL || get_array_size(arr) < 2)
        return (-1);
    if (!is_team_exist(client->team_uuid)) {
        add_to_client_queue(client, "/team_unknown\r\n", false);
        return (-1);
    }
    if (!is_channel_exist(client->channel_uuid)) {
        add_to_client_queue(client, "/channel_unknown\r\n", false);
        return (-1);
    }
    if (is_thread_exist_by_name(arr[0])) {
        add_to_client_queue(client, "/thread_already_exist\r\n", false);
        return (-1);
    }
    return (0);
}

void create_thread(server_t *server, client_t *client, char *data)
{
    char **arr = my_str_to_word_array(data, ';');
    char *uuid = generate_uuid();

    if (check_error_thread(client, arr) == -1)
        return;
    server_event_thread_created(client->channel_uuid, uuid, client->user_uuid,
        arr[0], arr[1]);
    send_to_clients(server, client, (thread_t){.thread_uuid = uuid,
        .user_uuid = client->user_uuid, .thread_timestamp = time(NULL),
        .thread_title = arr[0], .thread_body = arr[1],
        .channel_uuid = client->channel_uuid, .team_uuid = client->team_uuid});
    free_array(arr);
}