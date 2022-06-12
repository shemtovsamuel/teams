/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** check_exist.c
*/

#include "myteams_server.h"
#include "file.h"
#include <string.h>

bool is_user_exist(char *user_uuid)
{
    char ***csv_array = parse_csv_file(USER_SAVE_FILE);

    if (csv_array == NULL)
        return (false);
    for (int i = 0; csv_array[i] != NULL; i++) {
        if (strcmp(csv_array[i][1], user_uuid) == 0) {
            free_csv_array(csv_array);
            return (true);
        }
    }
    free_csv_array(csv_array);
    return (false);
}

bool is_team_exist(char *team_uuid)
{
    char ***csv_array = parse_csv_file(TEAMS_SAVE_FILE);

    if (csv_array == NULL)
        return (false);
    for (int i = 0; csv_array[i] != NULL; i++) {
        if (strcmp(csv_array[i][0], team_uuid) == 0) {
            free_csv_array(csv_array);
            return (true);
        }
    }
    free_csv_array(csv_array);
    return (false);
}

bool is_channel_exist(char *channel_uuid)
{
    char ***csv_array = parse_csv_file(CHANNELS_SAVE_FILE);

    if (csv_array == NULL)
        return (false);
    for (int i = 0; csv_array[i] != NULL; i++) {
        if (strcmp(csv_array[i][0], channel_uuid) == 0) {
            free_csv_array(csv_array);
            return (true);
        }
    }
    free_csv_array(csv_array);
    return (false);
}

bool is_thread_exist(char *thread_uuid)
{
    char ***csv_array = parse_csv_file(THREADS_SAVE_FILE);

    if (csv_array == NULL)
        return (false);
    for (int i = 0; csv_array[i] != NULL; i++) {
        if (strcmp(csv_array[i][0], thread_uuid) == 0) {
            free_csv_array(csv_array);
            return (true);
        }
    }
    free_csv_array(csv_array);
    return (false);
}
