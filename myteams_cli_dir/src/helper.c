/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi
** File description:
** help.c
*/

#include "myteams_cli.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void helper(int ac, char *av[])
{
    if (ac == 2 && strcmp("-help", av[1]) == 0) {
        printf("USAGE: ./myteams_cli ip port\n");
        printf("\tip\tis the server ip address on which the server");
        printf(" socket listens\n");
        printf("\tport\tis the port number on which the server");
        printf(" socket listens\n");
        exit(0);
    }
}
