/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi
** File description:
** read_user_message.c
*/

#include "myteams_cli.h"
#include "logging_client.h"
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>

void read_server_message(client_t *client)
{
    size_t len = 0;
    char buffer[4096];
    char **arr = NULL;

    len = recv(client->socket, buffer, 1024 - 1, 0);
    buffer[len] = '\0';
    if (len == 0) {
        close(client->socket);
        exit(0);
    }
    if (strcmp(buffer, "/logout") == 0)
        logout_client(client, "/logout");
    arr = my_str_to_word_array(buffer, '\n');
    for (int i = 0; arr[i]; ++i)
        handle_client(arr[i], client);
}
