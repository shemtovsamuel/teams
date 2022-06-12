/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** parse_csv_file.c
*/

#include "file.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

static void get_nb_row_and_col(char const *filepath, int *nb_row, int *nb_col)
{
    int fd = open_file(filepath);
    char buffer[1024] = {0};
    char *token = NULL;
    off_t offset = 0;

    if (fd == -1)
        return;
    while (read_line(buffer, 1024, fd, &offset) > 0) {
        *nb_row += 1;
        *nb_col = 0;
        if (*nb_row == 1)
            continue;
        token = strtok(buffer, ";");
        while (token != NULL) {
            *nb_col += 1;
            token = strtok(NULL, ";");
        }
    }
    close(fd);
}

static char ***fill_array(int fd, char row[], int nb_row, int nb_col)
{
    char ***result = calloc(nb_row + 1, sizeof(char **));
    char *token;
    int j = 0;
    off_t of = 0;

    if (result == NULL)
        return (NULL);
    for (int i = 0; i < nb_row && read_line(row, 1024, fd, &of) > 0; ++i) {
        result[i] = calloc(nb_col + 1, sizeof(char *));
        if (result[i] == NULL)
            return (NULL);
        j = 0;
        token = strtok(row, ";");
        while (token != NULL) {
            result[i][j++] = strdup(token);
            token = strtok(NULL, ";");
        }
    }
    close(fd);
    return (result);
}

char ***parse_csv_file(char const *filepath)
{
    int fd = open_file(filepath);
    int nb_row = 0;
    int nb_col = 0;
    char row[1024] = {0};

    get_nb_row_and_col(filepath, &nb_row, &nb_col);
    if (fd == -1 || nb_row == 0 || nb_col == 0)
        return (NULL);
    return (fill_array(fd, row, nb_row, nb_col));
}

void free_csv_array(char ***array)
{
    for (int i = 0; array[i] != NULL; i++) {
        for (int j = 0; array[i][j] != NULL; j++)
            free(array[i][j]);
        free(array[i]);
    }
    free(array);
}
