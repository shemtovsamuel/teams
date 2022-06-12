/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** login.c
*/

#include "myteams_server.h"
#include "logging_server.h"
#include "cmd.h"
#include "file.h"
#include "utils.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static char *create_message_for_client(char const *user_name, char const *uuid)
{
    char *message = NULL;

    message = malloc(sizeof(char) * (strlen("/login ") + strlen(user_name)
        + strlen(uuid) + 3 + 2 + 1));
    check_error(message == NULL, "malloc failed");
    sprintf(message, "/login;%s;%s;\r\n", uuid, user_name);
    return (message);
}

static char *create_message_for_other_client(char const *user_name,
    char const *uuid)
{
    char *message = NULL;

    message = malloc(sizeof(char) * (strlen("/event_login") + strlen(user_name)
        + strlen(uuid) + 3 + 2 + 1));
    check_error(message == NULL, "malloc failed");
    sprintf(message, "/event_login;%s;%s;\r\n", uuid, user_name);
    return (message);
}

static void create_new_user(server_t *server, client_t *client,
    char const *user_name)
{
    user_t user = {
        .user_name = strdup(user_name),
        .user_uuid = generate_uuid(),
    };

    client->user_uuid = strdup(user.user_uuid);
    write_user_to_file(user);
    server_event_user_logged_in(user.user_uuid);
    add_to_client_queue(client,
        create_message_for_client(user.user_name, user.user_uuid), false);
    for (int i = 0; i < server->nb_clients; ++i)
        if (server->arr_clients[i].user_uuid == NULL ||
            server->arr_clients[i].fd != client->fd)
            add_to_client_queue(&server->arr_clients[i],
            create_message_for_other_client(client->user_name,
            client->user_uuid), false);
}

static void login_with_existing_user(server_t *server, client_t *client,
    char const *user_name)
{
    user_t user = load_user_from_file_by_user_name(user_name);

    client->user_uuid = strdup(user.user_uuid);
    server_event_user_logged_in(user.user_uuid);
    add_to_client_queue(client,
        create_message_for_client(user.user_name, user.user_uuid), false);
    for (int i = 0; i < server->nb_clients; ++i)
        if (server->arr_clients[i].logged &&
            server->arr_clients[i].fd != client->fd)
            add_to_client_queue(&server->arr_clients[i],
            create_message_for_other_client(client->user_name,
            client->user_uuid), false);
}

void login(server_t *server, client_t *client, char *data)
{
    char **arr = my_str_to_word_array(data, ';');

    if (client->logged == true) {
        add_to_client_queue(client, "/already_logged\r\n", false);
        return;
    }
    if (arr == NULL) {
        add_to_client_queue(client, "/missing_data\r\n",
            false);
        return;
    }
    client->user_name = strdup(arr[0]);
    client->logged = true;
    if (is_user_exist_in_file(arr[0]) == false)
        create_new_user(server, client, arr[0]);
    else
        login_with_existing_user(server, client, arr[0]);
    free_array(arr);
}
