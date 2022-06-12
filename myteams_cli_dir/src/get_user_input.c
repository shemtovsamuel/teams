/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi
** File description:
** get_user_input.c
*/

#include "myteams_cli.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

static char *get_buffer(void)
{
    char *buffer = calloc(4096 + 1, sizeof(char));
    int res = 0;

    if (buffer == NULL)
        return NULL;
    res = read(0, buffer, 4096);
    if (res == -1)
        return NULL;
    buffer[res] = '\0';
    return buffer;
}

static int init_user_input(char **user_input, char **buffer)
{
    int i = 0;

    *user_input = calloc(4096 + 1, sizeof(char));
    if (*user_input == NULL)
        return -1;
    for (; **buffer != '\0' && (i == 0 || *(*buffer - 1) != '\n'); i++,
        (*buffer)++) {
        (*user_input)[i] = **buffer;
    }
    return i;
}

char *get_user_input(void)
{
    char *user_input = NULL;
    int size = 0;
    char *buffer = get_buffer();
    char *temp = NULL;

    if (buffer == NULL || buffer[0] == '\0')
        return NULL;
    size = init_user_input(&user_input, &buffer);
    if (size == -1)
        return NULL;
    user_input[size] = '\0';
    if (size != 0 && user_input[size - 1] == '\n')
        user_input[size - 1] = '\0';
    else {
        temp = get_user_input();
        user_input = strcat(user_input, temp ? temp : "");
    }
    return user_input;
}