/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** check_exist_by_name.c
*/

#include "myteams_server.h"
#include "file.h"
#include <string.h>

bool is_team_exist_by_name(char *team_name)
{
    char ***csv_array = parse_csv_file(TEAMS_SAVE_FILE);

    if (csv_array == NULL)
        return (false);
    for (int i = 0; csv_array[i] != NULL; i++) {
        if (strcmp(csv_array[i][1], team_name) == 0) {
            free_csv_array(csv_array);
            return (true);
        }
    }
    free_csv_array(csv_array);
    return (false);
}

bool is_channel_exist_by_name(char *channel_name)
{
    char ***csv_array = parse_csv_file(CHANNELS_SAVE_FILE);

    if (csv_array == NULL)
        return (false);
    for (int i = 0; csv_array[i] != NULL; i++) {
        if (strcmp(csv_array[i][1], channel_name) == 0) {
            free_csv_array(csv_array);
            return (true);
        }
    }
    free_csv_array(csv_array);
    return (false);
}

bool is_thread_exist_by_name(char *thread_name)
{
    char ***csv_array = parse_csv_file(THREADS_SAVE_FILE);

    if (csv_array == NULL)
        return (false);
    for (int i = 0; csv_array[i] != NULL; i++) {
        if (strcmp(csv_array[i][1], thread_name) == 0) {
            free_csv_array(csv_array);
            return (true);
        }
    }
    free_csv_array(csv_array);
    return (false);
}