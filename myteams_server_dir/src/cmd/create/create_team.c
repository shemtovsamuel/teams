/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** create_team.c
*/

#include "myteams_server.h"
#include "logging_server.h"
#include "file.h"
#include "utils.h"
#include "cmd.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static char *create_event_message_for_client(char const *team_uuid,
    char const *team_name, char const *team_description)
{
    char *msg = malloc(sizeof(char) * (strlen("/event_team") +
        strlen(team_uuid) + strlen(team_name) + strlen(team_description) + 6));

    if (msg == NULL)
        return (NULL);
    sprintf(msg, "/event_team;%s;%s;%s;\r\n", team_uuid, team_name,
        team_description);
    return (msg);
}

static char *create_message_for_client(char const *team_uuid,
    char const *team_name, char const *team_description)
{
    char *msg = NULL;

    msg = malloc(sizeof(char) * (strlen("/create_team") + strlen(team_name)
        + strlen(team_uuid) + strlen(team_description) + 4 + 2));
    if (msg == NULL)
        return (NULL);
    sprintf(msg, "/create_team;%s;%s;%s;\r\n", team_uuid, team_name,
        team_description);
    return (msg);
}

void create_team(server_t *server, client_t *client, char *data)
{
    char **arr = my_str_to_word_array(data, ';');
    char *uuid = generate_uuid();

    if (arr == NULL || get_array_size(arr) < 2)
        return;
    if (is_team_exist_by_name(arr[0])) {
        add_to_client_queue(client, "/team_already_exist\r\n", false);
        return;
    }
    write_team_to_file(uuid, arr[0], arr[1]);
    server_event_team_created(uuid, arr[0], client->user_uuid);
    add_to_client_queue(client, create_message_for_client(uuid, arr[0],
        arr[1]), false);
    for (int i = 0; i < server->nb_clients; i++) {
        if (server->arr_clients[i].logged == true)
            add_to_client_queue(&server->arr_clients[i],
                create_event_message_for_client(uuid,
                    arr[0], arr[1]), false);
    }
    free_array(arr);
}