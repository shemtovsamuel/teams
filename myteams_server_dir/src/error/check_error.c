/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myftp-william.karkegi
** File description:
** check_error.c
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void check_error(bool condition, char const *message)
{
    if (condition == false)
        return;
    perror(message);
    exit(84);
}
