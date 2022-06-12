/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myftp-william.karkegi
** File description:
** init_users.c
*/

#include "myteams_server.h"
#include <stdlib.h>
#include <string.h>

void init_users(server_t *server)
{
    user_t *arr_users = malloc(sizeof(user_t));

    check_error(arr_users == NULL, "malloc");
    arr_users[0].user_name = strdup("Anonymous");
    check_error(arr_users[0].user_name == NULL, "strdup");
    server->arr_users = arr_users;
    server->nb_users = 1;
}
