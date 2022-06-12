/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myftp-william.karkegi
** File description:
** main.c
*/

#include "myteams_server.h"
#include <signal.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    server_t server = {0};

    signal(SIGPIPE, SIG_IGN);
    signal(SIGINT, &signal_handler);
    check_error_input(ac, av);
    init_server(&server, atoi(av[1]));
    start_server(&server);
    return (0);
}
