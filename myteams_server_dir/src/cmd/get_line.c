/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myftp-william.karkegi
** File description:
** get_line.c
*/

#include "myteams_server.h"
#include <stdlib.h>
#include <string.h>

char *get_line(char const *dir)
{
    char *cmd = malloc(sizeof(char) * (strlen(dir) + 7));

    check_error(cmd == NULL, "malloc failed");
    strcpy(cmd, "ls -l ");
    strcat(cmd, dir);
    return (cmd);
}