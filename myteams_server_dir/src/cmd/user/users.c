/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi
** File description:
** users.c
*/

#include "myteams_server.h"
#include "struct.h"
#include "file.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static char *user_to_string(user_t user, server_t *server)
{
    char *str = calloc(1 + strlen(user.user_uuid) + 1 + strlen(user.user_name)
        + 1 + 1 + 1, sizeof(char));

    if (str == NULL)
        return (NULL);
    sprintf(str, ";%s;%s;%c", user.user_uuid, user.user_name,
        is_user_online(user, server) ? '1' : '0');
    return (str);
}

static char *create_message(char *users_str)
{
    char *message = calloc(strlen("/users") + 1 + strlen(users_str) + 3,
        sizeof(char));

    if (message == NULL)
        return (NULL);
    sprintf(message, "/users%s;\r\n", users_str);
    return (message);
}

static char *users_found(user_t *users, server_t *server)
{
    char *temp = NULL;
    char *users_str = calloc(1, sizeof(char));

    if (users_str == NULL)
        return (NULL);
    for (int i = 0; users[i].user_name; i++) {
        temp = user_to_string(users[i], server);
        if (temp == NULL)
            return (NULL);
        users_str = realloc(users_str, sizeof(char) * strlen(users_str)
            + strlen(temp) + 1);
        if (users_str == NULL)
            return (NULL);
        strcat(users_str, temp);
        free(temp);
    }
    return (create_message(users_str));
}

void users(server_t *server, client_t *client, char *data USELESS)
{
    user_t *users = load_users_from_file();

    if (users == NULL) {
        add_to_client_queue(client, "/users_not_found;null;\r\n", false);
        return;
    }
    add_to_client_queue(client, users_found(users, server), false);
}
