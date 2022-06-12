/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** read_file_by_line.c
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

ssize_t read_line(char *buffer, size_t size, int fd, off_t *offset)
{
    ssize_t nchr = 0;
    ssize_t idx = 0;
    char *p = NULL;

    if ((nchr = lseek(fd, *offset, SEEK_SET)) != -1)
        nchr = read(fd, buffer, size);
    if (nchr == -1 || nchr == 0)
        return nchr == -1 ? nchr : -1;
    p = buffer;
    while (idx < nchr && *p != '\n') {
        p++;
        idx++;
    }
    *p = 0;
    if (idx == nchr) {
        *offset += nchr;
        return nchr < (ssize_t)size ? nchr : 0;
    }
    *offset += idx + 1;
    return idx;
}