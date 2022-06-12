/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** load_user_from_file.c
*/

#include "struct.h"
#include "file.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

user_t load_user_from_file_by_user_name(char const *user_name)
{
    user_t user = {0};
    char ***csv_array = parse_csv_file(USER_SAVE_FILE);

    if (csv_array == NULL)
        return (user);
    for (int i = 0; csv_array[i] != NULL; i++) {
        if (strcmp(csv_array[i][0], user_name) == 0) {
            user.user_name = strdup(csv_array[i][0]);
            user.user_uuid = strdup(csv_array[i][1]);
            free_csv_array(csv_array);
            return (user);
        }
    }
    free_csv_array(csv_array);
    return (user);
}

user_t load_user_from_file_by_uuid(char const *user_uuid)
{
    user_t user = {0};
    char ***csv_array = parse_csv_file(USER_SAVE_FILE);

    if (csv_array == NULL)
        return (user);
    for (int i = 0; csv_array[i] != NULL; i++) {
        if (strcmp(csv_array[i][1], user_uuid) == 0) {
            user.user_name = strdup(csv_array[i][0]);
            user.user_uuid = strdup(csv_array[i][1]);
            free_csv_array(csv_array);
            return (user);
        }
    }
    free_csv_array(csv_array);
    return (user);
}