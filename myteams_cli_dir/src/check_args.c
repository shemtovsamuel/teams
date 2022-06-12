/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi
** File description:
** check_args.c
*/

#include "myteams_cli.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static bool is_digit(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return (false);
    return (true);
}

static bool loop_validate_ip(char *str, int n, int point)
{
    if (str == NULL)
        return false;
    while (str) {
        if (is_digit(str) == false)
            return false;
        n = atoi(str);
        if (n >= 0 && n <= 255) {
            str = strtok(NULL, ".");
            if (str != NULL)
                point++;
            continue;
        }
        return false;
    }
    if (point != 3)
        return false;
    return true;
}

static bool validate_ip(char *ip)
{
    int n = 0;
    int point = 0;
    char *str = strdup(ip);
    char *temp = strdup(ip);

    str = strtok(temp, ".");
    if (loop_validate_ip (str, n, point) == false)
        return false;
    return true;
}

int check_args(int ac, char *av[])
{
    helper(ac, av);
    if (ac != 3) {
        printf("Wrongs arguments.\n");
        return 84;
    }
    if (is_digit(av[2]) == false) {
        printf("Incorrect port.\n");
        return 84;
    }
    if (validate_ip(av[1]) == false) {
        printf("Incorrect ip.\n");
        return 84;
    }
    return 0;
}
