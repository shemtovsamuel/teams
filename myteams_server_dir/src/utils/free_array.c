/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi
** File description:
** free_array.c
*/

#include <stdlib.h>

void free_array(char **array)
{
    int i = 0;

    while (array[i] != NULL) {
        free(array[i]);
        i++;
    }
    free(array);
}
