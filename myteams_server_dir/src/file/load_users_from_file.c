/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** load_users_from_file.c
*/

#include "file.h"
#include "struct.h"
#include <stdlib.h>
#include <string.h>

int get_nb_users_saved(void)
{
    char ***csv_array = parse_csv_file(USER_SAVE_FILE);
    int nb_users = 0;

    if (csv_array == NULL)
        return (0);
    for (int i = 0; csv_array[i] != NULL; i++)
        nb_users++;
    free_csv_array(csv_array);
    return (nb_users - 1);
}

user_t *load_users_from_file(void)
{
    user_t *users = calloc(get_nb_users_saved() + 1, sizeof(user_t));
    char ***csv_array = parse_csv_file(USER_SAVE_FILE);

    if (csv_array == NULL || users == NULL)
        return (NULL);
    for (int i = 0; csv_array[i + 1] != NULL; i++) {
        users[i].user_name = strdup(csv_array[i + 1][0]);
        users[i].user_uuid = strdup(csv_array[i + 1][1]);
    }
    free_csv_array(csv_array);
    return (users);
}