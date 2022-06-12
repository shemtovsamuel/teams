/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myftp-william.karkegi
** File description:
** handle_cmd.c
*/

#include "myteams_server.h"
#include "cmd.h"
#include <stdlib.h>
#include <string.h>

static cmd_t index_in_array(char const **funcs_name, cmd_t *funcs, char *cmd)
{
    cmd_t temp = NULL;

    for (int i = 0; funcs_name[i] != NULL; i++) {
        if (!strcasecmp(funcs_name[i], cmd)) {
            temp = funcs[i];
            break;
        }
    }
    free(cmd);
    return (temp);
}

void handle_cmd(server_t *server, client_t *client, char *cmd, char *data)
{
    char const *funcs_name[] = FUNCS_NAME;
    cmd_t funcs[] = FUNCS;
    cmd_t func = NULL;

    if (client->logged == false && strcasecmp("/login", cmd)) {
        add_to_client_queue(client,
            "/not_logged\r\n", false);
        free(cmd);
        return;
    }
    func = index_in_array(funcs_name, funcs, cmd);
    if (func == NULL)
        add_to_client_queue(client, "/unknown_command\r\n", false);
    else
        (func)(server, client, data);
}