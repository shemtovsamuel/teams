/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi
** File description:
** send_user_message.c
*/

#include "myteams_cli.h"
#include "logging_client.h"
#include "cmd.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static void check_need_exit(client_t *client,
    char *message, char **cmd)
{
    if (message == NULL || cmd == NULL)
        logout_client(client, "/logout");
}

static char *create_message(char **cmd)
{
    char *message = NULL;
    int size = 3;

    for (int i = 0; cmd[i]; ++i) {
        size += strlen(cmd[i]);
        size += 1;
    }
    message = malloc(size * sizeof(char));
    if (message == NULL)
        return (NULL);
    message[0] = '\0';
    for (int i = 0; cmd[i]; ++i) {
        if (strcmp(cmd[i], " ") == 0)
            continue;
        strcat(message, cmd[i]);
        strcat(message, cmd[i + 1] ? ";" : "");
    }
    strcat(message, "\r\n");
    return (message);
}

void send_user_message(client_t *client, char *message)
{
    char **cmd = my_str_to_word_array(message, '"');

    logout_client(client, message);
    check_need_exit(client, message, cmd);
    if (strcmp(message, "") == 0)
        return;
    if (cmd[0][strlen(cmd[0]) - 1] == ' ')
        cmd[0][strlen(cmd[0]) - 1] = '\0';
    if (((!client->logged && strcmp(message, "/help") != 0) &&
        (!client->logged && strcmp(cmd[0], "/login") != 0)) ||
        strcmp(message, "/login") == 0) {
        client_error_unauthorized();
    } else if (client->logged && strcmp(cmd[0], "/login") == 0) {
        client_error_already_exist();
        return;
    }
    if (!client->logged && strcmp(message, "/help") == 0)
        printf("Usage: ...\n");
    else
        dprintf(client->socket, create_message(cmd), message);
}
