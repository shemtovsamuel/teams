/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myftp-william.karkegi
** File description:
** check_error_input.c
*/

#include "myteams_server.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

static bool is_digit(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return (false);
    return (true);
}

void check_error_input(int ac, char **av)
{
    if (ac == 2 && (!strcmp(av[1], "-h") || !strcmp(av[1], "--help")))
        display_help(false);
    else if (ac == 2)
        is_digit(av[1]) == false ? display_help(true) : 0;
    else
        display_help(true);
}