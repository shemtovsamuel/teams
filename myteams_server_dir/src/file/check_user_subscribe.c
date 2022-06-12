/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** check_user_subscribe.c
*/

#include "myteams_server.h"
#include "file.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_user_subscribe(char *user_uuid, char *team_uuid)
{
    char ***csv_sub = parse_csv_file(SUBSCRIBE_SAVE_FILE);

    if (csv_sub == NULL)
        return (false);
    for (int i = 0; csv_sub[i + 1]; i++) {
        if (strcmp(csv_sub[i + 1][0], user_uuid) == 0
            && strcmp(csv_sub[i + 1][1], team_uuid) == 0)
            return (true);
    }
    return (false);
}