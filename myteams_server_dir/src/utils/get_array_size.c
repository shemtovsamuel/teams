/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** get_array_size.c
*/

#include "stddef.h"

int get_array_size(char **arr)
{
    int i = 0;

    if (arr == NULL)
        return (0);
    while (arr[i] != NULL)
        i++;
    return (i);
}