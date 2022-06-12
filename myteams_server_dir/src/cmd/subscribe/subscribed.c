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

void subscribed(server_t *server, client_t *client, char *data)
{
    char **arr = my_str_to_word_array(data, ';');
    int size = get_array_size(arr);

    if (arr == NULL) {
        subscribed_user(client, data);
    } else if (size == 1) {
        subscribed_team(server, client, data);
    }
}