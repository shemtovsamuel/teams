/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** server_log.c
*/

#include "server_log.h"
#include <stdio.h>

void server_log(int id)
{
    char const *server_log_messages[] = SERVER_LOG_MESSAGES;

    printf("[SERVER] %s\n", server_log_messages[id]);
}