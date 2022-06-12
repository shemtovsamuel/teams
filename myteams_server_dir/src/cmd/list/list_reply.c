/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** list_reply.c
*/

#include "myteams_server.h"
#include "file.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static char *create_message(char *messages)
{
    char *message = calloc(strlen("/list_thread_replies") + 1 +
        strlen(messages) + 4, sizeof(char));

    if (message == NULL)
        return (NULL);
    sprintf(message, "/list_thread_replies%s;\r\n", messages);
    return (message);
}

static char *concat_message(char ***csv, char *message, int i)
{
    strcat(message, ";");
    strcat(message, csv[i + 1][1]);
    strcat(message, ";");
    strcat(message, csv[i + 1][2]);
    strcat(message, ";");
    strcat(message, csv[i + 1][3]);
    strcat(message, ";");
    strcat(message, csv[i + 1][4]);
    return (message);
}

static char *find_replies(client_t *client, char ***csv)
{
    char *msg = calloc(1, sizeof(char));

    if (msg == NULL)
        return (NULL);
    for (int i = 0; csv[i + 1]; i++) {
        if (strcmp(csv[i + 1][0], client->team_uuid) != 0
            || strcmp(csv[i + 1][1], client->thread_uuid) != 0)
            continue;
        msg = realloc(msg, sizeof(char) * (strlen(msg) + strlen(csv[i + 1][1])
            + strlen(csv[i + 1][2]) + strlen(csv[i + 1][3])
            + strlen(csv[i + 1][4]) + 10));
        if (msg == NULL)
            return (NULL);
        msg = concat_message(csv, msg, i);
    }
    return (create_message(msg));
}

void list_reply(server_t *server USELESS, client_t *client)
{
    char ***csv = parse_csv_file(REPLIES_SAVE_FILE);

    if (csv == NULL)
        return;
    add_to_client_queue(client, find_replies(client, csv), false);
    free_csv_array(csv);
}
