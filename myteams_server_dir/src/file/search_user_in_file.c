/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** search_user_in_file.c
*/

#include "struct.h"
#include "file.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

bool is_user_exist_in_file(char const *user_name)
{
    char ***csv_array = parse_csv_file(USER_SAVE_FILE);

    if (csv_array == NULL)
        return (false);
    for (int i = 0; csv_array[i] != NULL; i++) {
        if (strcmp(csv_array[i][0], user_name) == 0) {
            free_csv_array(csv_array);
            return (true);
        }
    }
    free_csv_array(csv_array);
    return (false);
}