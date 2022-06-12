/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi
** File description:
** use.c
*/

#include "myteams_server.h"
#include "utils.h"
#include "file.h"
#include <string.h>

static void change_context(client_t *client, char **message, int type)
{
    if ((type == TEAM_CONTEXT && !is_team_exist(message[0]))
        || (type == CHANNEL_CONTEXT && !is_team_exist(message[0])
            && !is_channel_exist(message[1]))
        || (type == THREAD_CONTEXT && !is_team_exist(message[0])
            && !is_channel_exist(message[1])
            && !is_thread_exist(message[2])))
        return;
    client->context = type;
    client->team_uuid = type != USER_CONTEXT ? strdup(message[0]) : NULL;
    client->channel_uuid = type > TEAM_CONTEXT ? strdup(message[1]) : NULL;
    client->thread_uuid = type == THREAD_CONTEXT ? strdup(message[2]) : NULL;
}

static void set_context(client_t *client, int len, char **message)
{
    switch (len) {
        case TEAM_CONTEXT:
            change_context(client, message, TEAM_CONTEXT);
            break;
        case CHANNEL_CONTEXT:
            change_context(client, message, CHANNEL_CONTEXT);
            break;
        case THREAD_CONTEXT:
            change_context(client, message, THREAD_CONTEXT);
            break;
        default:
            change_context(client, message, USER_CONTEXT);
            break;
    }
}

void use(server_t *server USELESS, client_t *client, char *data)
{
    char **message = my_str_to_word_array(data, ';');
    int len = get_array_size(message);

    if (message == NULL) {
        client->context = USER_CONTEXT;
        return;
    }
    set_context(client, len, message);
    free_array(message);
}