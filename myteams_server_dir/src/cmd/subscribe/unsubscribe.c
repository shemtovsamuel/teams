/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** unsubscribe.c
*/

#include "myteams_server.h"
#include "logging_server.h"
#include "file.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *create_message(char *user_uuid, char *team_uuid)
{
    char *message = malloc(sizeof(char) * (strlen(user_uuid)
        + strlen(team_uuid) + strlen("/unsubscribe") + 6));

    if (message == NULL)
        return (NULL);
    sprintf(message, "/unsubscribe;%s;%s;\r\n", user_uuid, team_uuid);
    return (message);
}

void unsubscribe(server_t *server USELESS, client_t *client, char *data)
{
    char **arr = my_str_to_word_array(data, ';');
    char ***csv = parse_csv_file(SUBSCRIBE_SAVE_FILE);

    if (arr == NULL)
        return;
    if (!is_team_exist(arr[0])) {
        add_to_client_queue(client, "/unknow_team;\r\n", false);
        return;
    }
    if (is_file_exist(SUBSCRIBE_SAVE_FILE) == false)
        return;
    for (int i = 0; csv[i] != NULL; i++)
        if (strcmp(csv[i][0], client->user_uuid) == 0 &&
            strcmp(csv[i][1], arr[0]) == 0) {
            server_event_user_unsubscribed(arr[0], client->user_uuid);
            remove_line_from_file(SUBSCRIBE_SAVE_FILE, i);
            add_to_client_queue(client, create_message(client->user_uuid,
                arr[0]), false);
            break;
        }
}