/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** file_empty.c
*/

#include "file.h"
#include <unistd.h>

bool is_file_empty(char const *file_name)
{
    int fd = open_file(file_name);
    char buffer[1024] = {0};
    off_t offset = 0;

    if (fd == -1)
        return true;
    if (read_line(buffer, 1024, fd, &offset) <= 0)
        return true;
    close(fd);
    return false;
}