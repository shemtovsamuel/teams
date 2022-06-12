/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myftp-william.karkegi
** File description:
** helper.c
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void display_help(bool is_error)
{
    printf("USAGE: ./myteams_server port\n\tport is the port number on which"
        " the server socket listens.\n");
    exit(is_error ? 84 : 0);
}
