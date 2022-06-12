/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** utils.h
*/

#ifndef UTILS_H
    #define UTILS_H

char **my_str_to_word_array(char const *str, char separator);
void free_array(char **array);
int get_array_size(char **arr);
char *ld_to_string(long int nb);

#endif