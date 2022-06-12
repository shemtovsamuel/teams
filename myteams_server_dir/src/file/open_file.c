/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** open_file.c
*/

#include "file.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int open_file(const char *file_path)
{
    fd_set readfds;
    fd_set writefds;
    int fd = open(file_path, O_RDWR | O_NONBLOCK | O_CREAT, 0777);

    if (fd == -1)
        return -1;
    FD_ZERO(&readfds);
    FD_ZERO(&writefds);
    FD_SET(fd, &readfds);
    FD_SET(fd, &writefds);
    if (select(fd + 1, &readfds, &writefds, NULL, NULL) == -1)
        return (-1);
    return fd;
}

int open_append_file(char *file_path)
{
    fd_set readfds;
    fd_set writefds;
    int fd = open(file_path, O_RDWR | O_APPEND | O_NONBLOCK | O_CREAT, 0777);

    if (fd == -1)
        return -1;
    FD_ZERO(&readfds);
    FD_ZERO(&writefds);
    FD_SET(fd, &readfds);
    FD_SET(fd, &writefds);
    if (select(fd + 1, &readfds, &writefds, NULL, NULL) == -1)
        return (-1);
    return fd;
}
