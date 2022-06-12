/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myftp-william.karkegi
** File description:
** parse_cmd.c
*/

#include "myteams_server.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

static char *check_strcat(const char *str1, const char *str2)
{
    char *result = malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 1));
    int i = 0;
    int j = 0;

    check_error(result == NULL, "malloc failed");
    for (; i < (int)strlen(str1); i++)
        result[i] = str1[i];
    for (; j < (int)strlen(str2); j++)
        result[i + j] = str2[j];
    result[i + j] = '\0';
    return (result);
}

static char *check_strdup(const char *str)
{
    char *res = strdup(str);

    check_error(res == NULL, "strdup failed");
    return (res);
}

static void check(char *rqst, char **cmd, char **data)
{
    if (!(*cmd))
        return;
    if (!(*data) && !strlen(*cmd)) {
        free(*cmd);
        *cmd = NULL;
    }
    free(rqst);
}

static char *get_rqst(char **client_req, char const *req)
{
    char *temp = NULL;

    if (strstr(req, REQUEST_END) != NULL) {
        if (*client_req == NULL)
            return (check_strdup(req));
        temp = check_strcat(*client_req, req);
        free(*client_req);
        *client_req = NULL;
        return (temp);
    } else {
        if (*client_req == NULL)
            *client_req = check_strdup(req);
        else {
            temp = check_strcat(*client_req, req);
            free(*client_req);
            *client_req = temp;
        }
        return (NULL);
    }
}

void parse_cmd(char **client_req, char const *req, char **cmd, char **data)
{
    char *temp = NULL;
    char *temp2 = NULL;
    int diff;
    int size;
    char *rqst = get_rqst(client_req, req);

    if (rqst == NULL)
        return;
    temp2 = strstr(rqst, REQUEST_END);
    size = temp2 - rqst;
    temp = strchr(rqst, ';');
    if (temp != NULL) {
        diff = temp - rqst;
        *cmd = strndup(rqst, diff);
        *data = strndup(&rqst[diff + 1], size - diff - 1);
    } else
        *cmd = strndup(rqst, size);
    check(rqst, cmd, data);
}