/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** check_file.c
*/

#include "stdbool.h"
#include "unistd.h"
#include "stdio.h"

bool is_file_exist(char const *filepath)
{
    return (access(filepath, F_OK) == 0);
}