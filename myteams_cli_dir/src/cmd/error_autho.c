/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** error_autho.c
*/

#include "myteams_cli.h"
#include "logging_client.h"

void unauthorized(client_t *client USELESS, char *message USELESS)
{
    client_error_unauthorized();
}

void already_exist(client_t *client USELESS, char *message USELESS)
{
    client_error_already_exist();
}
