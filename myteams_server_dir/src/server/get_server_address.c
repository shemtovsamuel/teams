/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myftp-william.karkegi
** File description:
** get_server_address.c
*/

#include "myteams_server.h"
#include <stdlib.h>

server_t *get_server_address(server_t *server)
{
    static server_t *save;

    if (server == NULL)
        return (save);
    save = server;
    return (save);
}