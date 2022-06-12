/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** remove_line_from_file.c
*/

#include "file.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

static void delete_line(int file, int temp, int line)
{
    char buffer[1024] = {0};
    int i = 0;
    off_t offset = 0;

    while (read_line(buffer, 1024, file, &offset) > 0) {
        if (i != line) {
            write(temp, buffer, strlen(buffer));
            write(temp, "\n", 1);
        }
        i++;
    }
}

void remove_line_from_file(char *filepath, int line)
{
    int file = open_file(filepath);
    int temp = open_file("./save/temp.csv");

    if (file == -1 || temp == -1)
        return;
    delete_line(file, temp, line);
    close(file);
    close(temp);
    remove(filepath);
    rename("./save/temp.csv", filepath);
}