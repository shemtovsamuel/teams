/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** list.c
*/

#include "myteams_server.h"
#include "file.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void info_user(client_t *client)
{
    char *msg = malloc(sizeof(char) * (strlen(client->user_uuid) +
        strlen(client->user_name) + strlen("/info_user") + 1 + 10));

    if (msg == NULL)
        return;
    sprintf(msg, "/info_user;%s;%s;1;\r\n", client->user_uuid,
        client->user_name);
    add_to_client_queue(client, msg, false);
}

static void info_team(client_t *client)
{
    char ***csv = parse_csv_file(TEAMS_SAVE_FILE);
    char *msg = NULL;
    int index;

    for (int i = 0; csv[i] != NULL; i++)
        if (strcmp(csv[i][0], client->team_uuid) == 0)
            index = i;
    msg = malloc(sizeof(char) * (strlen(csv[index][0]) +
        strlen(csv[index][1]) + strlen(csv[index][2]) + strlen("/info_team")
        + 1 + 10));
    if (msg == NULL)
        return;
    sprintf(msg, "/info_team;%s;%s;%s;\r\n", csv[index][0], csv[index][1],
        csv[index][2]);
    add_to_client_queue(client, msg, false);
    free_csv_array(csv);
}

static void info_channel(client_t *client)
{
    char ***csv = parse_csv_file(CHANNELS_SAVE_FILE);
    char *msg = NULL;
    int index;

    for (int i = 0; csv[i] != NULL; i++)
        if (strcmp(csv[i][0], client->channel_uuid) == 0)
            index = i;
    msg = malloc(sizeof(char) * (strlen(csv[index][0]) +
        strlen(csv[index][1]) + strlen(csv[index][2]) + strlen("/info_channel")
        + 1 + 10));
    if (msg == NULL)
        return;
    sprintf(msg, "/info_channel;%s;%s;%s;\r\n", csv[index][0], csv[index][1],
        csv[index][2]);
    add_to_client_queue(client, msg, false);
    free_csv_array(csv);
}

static void info_thread(client_t *client)
{
    char ***csv = parse_csv_file(THREADS_SAVE_FILE);
    char *msg = NULL;
    int index;

    for (int i = 0; csv[i] != NULL; i++)
        if (strcmp(csv[i][0], client->thread_uuid) == 0)
            index = i;
    msg = malloc(sizeof(char) * (strlen(csv[index][0]) +
        strlen(csv[index][1]) + strlen(csv[index][2]) + strlen(csv[index][3])
        + strlen(csv[index][4]) + strlen("/info_thread") + 1 + 10));
    if (msg == NULL)
        return;
    sprintf(msg, "/info_thread;%s;%s;%s;%s;%s;\r\n", csv[index][0],
        csv[index][1], csv[index][2], csv[index][3], csv[index][4]);
    add_to_client_queue(client, msg, false);
    free_csv_array(csv);
}

void info(server_t *server USELESS, client_t *client, char *data USELESS)
{
    switch (client->context) {
        case USER_CONTEXT:
            info_user(client);
            break;
        case TEAM_CONTEXT:
            info_team(client);
            break;
        case CHANNEL_CONTEXT:
            info_channel(client);
            break;
        case THREAD_CONTEXT:
            info_thread(client);
            break;
        default:
            break;
    }
}
