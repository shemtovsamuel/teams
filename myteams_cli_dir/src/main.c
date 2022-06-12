/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL: Ubuntu-20.04]
** File description:
** main.c
*/

#include "myteams_cli.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stdlib.h>
#include <stdbool.h>

info_t init_info(char *av[])
{
    info_t info = {
        .ip = strdup(av[1]),
        .port = atoi(av[2]),
    };

    return info;
}

int main(int ac, char *av[])
{
    check_args(ac, av) == 84 ? exit(84) : 0;
    return (launch_client(init_info(av)));
}
