/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi
** File description:
** messages.c
*/

#include "myteams_server.h"
#include "struct.h"
#include "file.h"
#include "utils.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static char *create_message(char *messages)
{
    char *message = calloc(strlen("/messages") + 1 + strlen(messages) + 3,
        sizeof(char));

    if (message == NULL)
        return (NULL);
    sprintf(message, "/messages%s;\r\n", messages);
    return (message);
}

static char *concat_message(char ***csv, char *message, int i)
{
    strcat(message, ";");
    strcat(message, csv[i + 1][0]);
    strcat(message, ";");
    strcat(message, csv[i + 1][2]);
    strcat(message, ";");
    strcat(message, csv[i + 1][3]);
    return (message);
}

static char *find_messages(char *user_one, char *user_two)
{
    char ***csv = parse_csv_file(USERS_MESSAGES_FILE);
    char *message = calloc(1, sizeof(char));

    if (csv == NULL || message == NULL)
        return (NULL);
    for (int i = 0; csv[i + 1]; i++) {
        if ((strcmp(csv[i + 1][0], user_one) == 0 &&
            strcmp(csv[i + 1][1], user_two) == 0) || (strcmp(csv[i + 1][0],
            user_two) == 0 && strcmp(csv[i + 1][1], user_one) == 0)) {
            message = realloc(message, sizeof(char) * (strlen(message) +
                strlen(csv[i + 1][0]) + strlen(csv[i + 1][2]) +
                strlen(csv[i + 1][3]) + 10));
            message = concat_message(csv, message, i);
        }
    }
    free_csv_array(csv);
    return (create_message(message));
}

void messages(server_t *server USELESS, client_t *client, char *data)
{
    char **message = my_str_to_word_array(data, ';');
    char ***csv = parse_csv_file(USERS_MESSAGES_FILE);

    if (csv == NULL)
        return;
    add_to_client_queue(client, find_messages(client->user_uuid, message[0]),
        false);
    free_array(message);
}