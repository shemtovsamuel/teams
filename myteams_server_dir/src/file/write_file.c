/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi
** File description:
** write_file.c
*/

#include "file.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

static void create_file(char *file_name)
{
    int fd = open_file(file_name);

    if (fd == -1)
        return;
    close(fd);
}

void write_at_the_end_of_file(char *file_path, char *data)
{
    int fd = -1;

    if (is_file_exist(file_path) == false)
        create_file(file_path);
    fd = open_append_file(file_path);
    if (fd == -1)
        return;
    write(fd, data, strlen(data));
    write(fd, "\n", strlen("\n"));
    close(fd);
}