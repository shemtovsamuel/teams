/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** subscribed.c
*/

#include "myteams_server.h"
#include "logging_server.h"
#include "file.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *create_message(char *messages)
{
    char *message = calloc(strlen("/list_team") + 1 + strlen(messages) + 4,
        sizeof(char));

    if (message == NULL)
        return (NULL);
    sprintf(message, "/list_team%s;\r\n", messages);
    return (message);
}

static char *concat_message(char ***csv, char *message, int i)
{
    strcat(message, ";");
    strcat(message, csv[i + 1][0]);
    strcat(message, ";");
    strcat(message, csv[i + 1][1]);
    strcat(message, ";");
    strcat(message, csv[i + 1][2]);
    return (message);
}

static bool is_subscribed_to_team(char ***csv_sub, char *team_uuid,
    client_t *client)
{
    for (int i = 0; csv_sub[i + 1]; i++) {
        if (strcmp(csv_sub[i + 1][1], team_uuid) == 0
            && strcmp(csv_sub[i + 1][0], client->user_uuid) == 0)
            return (true);
    }
    return (false);
}

static char *find_teams(char ***csv_teams, char ***csv_sub, client_t *client)
{
    char *msg = calloc(1, sizeof(char));

    if (msg == NULL)
        return (NULL);
    for (int i = 0; csv_teams[i + 1]; i++) {
        if (!is_subscribed_to_team(csv_sub, csv_teams[i + 1][0], client))
            continue;
        msg = realloc(msg, sizeof(char) * (strlen(msg)
            + strlen(csv_teams[i + 1][0])
            + strlen(csv_teams[i + 1][1]) + strlen(csv_teams[i + 1][2]) + 10));
        if (msg == NULL)
            return (NULL);
        msg = concat_message(csv_teams, msg, i);
    }
    return (create_message(msg));
}

void subscribed_user(client_t *client, char *data)
{
    char **arr = my_str_to_word_array(data, ';');
    char ***csv_sub = parse_csv_file(SUBSCRIBE_SAVE_FILE);
    char ***csv_teams = parse_csv_file(TEAMS_SAVE_FILE);

    if (arr != NULL || csv_sub == NULL || csv_teams == NULL)
        return;
    add_to_client_queue(client, find_teams(csv_teams, csv_sub, client), false);
    free_csv_array(csv_teams);
    free_csv_array(csv_sub);
}
