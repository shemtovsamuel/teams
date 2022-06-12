/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myftp-william.karkegi
** File description:
** signal_handler.c
*/

#include "myteams_server.h"
#include <stdlib.h>
#include <stdio.h>

void signal_handler(int sig USELESS)
{
    free_server();
    exit(0);
}