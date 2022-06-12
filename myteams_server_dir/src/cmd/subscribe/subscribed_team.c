/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** subscribed_team.c
*/

#include "myteams_server.h"
#include "logging_server.h"
#include "file.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

static bool is_subscribed_to_team(char ***csv_sub, user_t user,
    char *team_uuid)
{
    for (int i = 0; csv_sub[i + 1]; i++) {
        if (strcmp(csv_sub[i + 1][0], user.user_uuid) == 0
            && strcmp(csv_sub[i + 1][1], team_uuid) == 0)
            return (true);
    }
    return (false);
}

static char *users_found(user_t *users, server_t *server, char ***csv_sub,
    char *team_uuid)
{
    char *temp = NULL;
    char *users_str = calloc(1, sizeof(char));

    if (users_str == NULL)
        return (NULL);
    for (int i = 0; users[i].user_name; i++) {
        if (!is_subscribed_to_team(csv_sub, users[i], team_uuid))
            continue;
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

void subscribed_team(server_t *server, client_t *client, char *data)
{
    char **arr = my_str_to_word_array(data, ';');
    int size = get_array_size(arr);
    char ***csv_sub = parse_csv_file(SUBSCRIBE_SAVE_FILE);
    user_t *users = load_users_from_file();

    if (size != 1 || csv_sub == NULL)
        return;
    if (!is_team_exist(arr[0])) {
        add_to_client_queue(client, "/unknow_team;\r\n", false);
        return;
    }
    add_to_client_queue(client, users_found(users, server, csv_sub, arr[0]),
        false);
    free_array(arr);
    free_csv_array(csv_sub);
}