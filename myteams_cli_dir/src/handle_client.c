/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi
** File description:
** handle_client.c
*/

#include "myteams_cli.h"
#include "logging_client.h"
#include "cmd.h"
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>

char *str_append(char *str, char *to_append)
{
    char *res = malloc(sizeof(char) * (strlen(str) + strlen(to_append) + 1));
    int i = 0;
    int j = 0;

    if (res == NULL)
        return NULL;
    for (i = 0; str[i] != '\0'; i++)
        res[i] = str[i];
    for (j = 0; to_append[j] != '\0'; j++)
        res[i + j] = to_append[j];
    res[i + j] = '\0';
    return res;
}

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

char *delete_first_word(char *str)
{
    char *new_str;
    int len = strlen(str);

    if (str == NULL)
        return "";
    for (int i = 0; i < len; i++) {
        if (str[i] != ';')
            continue;
        new_str = strdup(str + i + 1);
        if (new_str[0] != ';' && new_str[0] != '\0')
            return (new_str);
        delete_first_word(new_str);
    }
    return "";
}

void handle_client(char *buffer, client_t *client)
{
    char **cmd = my_str_to_word_array(buffer, ';');
    char const *funcs_name[] = FUNCS_NAME;
    cmd_t funcs[] = FUNCS;
    cmd_t func = NULL;
    char *message = delete_first_word(buffer);

    if (client->logged == false && strcasecmp("/login", cmd[0]) != 0) {
        printf("error_not_logged\n");
        free(cmd);
        return;
    }
    func = index_in_array(funcs_name, funcs, cmd[0]);
    if (func == NULL)
        printf("error_unknown_command\n");
    else
        (func)(client, message);
}
