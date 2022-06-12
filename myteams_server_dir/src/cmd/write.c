/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myftp-william.karkegi
** File description:
** write.c
*/

#include "myteams_server.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int accept_connection(int fd)
{
    fd_set read_set;
    struct timeval timeout;
    int ret = 0;

    timeout.tv_sec = 15;
    timeout.tv_usec = 0;
    FD_ZERO(&read_set);
    FD_SET(fd, &read_set);
    ret = select(fd + 1, &read_set, NULL, NULL, &timeout);
    if (ret == 0 || !FD_ISSET(fd, &read_set))
        return (-1);
    return (accept(fd, NULL, NULL));
}

void write_to_client(int fd, char const *message)
{
    fd_set write_set;
    struct timeval timeout;
    int ret = 0;

    timeout.tv_sec = 15;
    timeout.tv_usec = 0;
    FD_ZERO(&write_set);
    FD_SET(fd, &write_set);
    ret = select(fd + 1, NULL, &write_set, NULL, &timeout);
    if (ret == 0 || !FD_ISSET(fd, &write_set))
        exit(1);
    write(fd, message, strlen(message));
}