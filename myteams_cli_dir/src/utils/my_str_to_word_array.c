/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi
** File description:
** my_str_to_word_array.c
*/

#include <stdbool.h>
#include <stdlib.h>

static bool c_separator(char c, char separator)
{
    if (c != separator)
        return (true);
    return (false);
}

static char **array_alloc(char const *str, char separator)
{
    char **array = NULL;
    int size = 1;

    for (int i = 0 ; str[i] ;) {
        for (; !c_separator(str[i], separator) && str[i] ; i++);
        if (str[i])
            size += 1;
        for (; c_separator(str[i], separator) && str[i] ; i++);
    }
    array = malloc(size * sizeof(char *));
    if (array == NULL)
        return (NULL);
    array[size - 1] = NULL;
    return (array);
}

static char *string_array(char const *str, char separator)
{
    char *array = NULL;
    int size = 0;

    for (; c_separator(str[size], separator) && str[size] ; size++);
    array = malloc((size + 2) * sizeof(char));
    if (array == NULL)
        return (NULL);
    array[size] = '\0';
    for (size = 0 ; c_separator(str[size], separator) && str[size] ; size++)
        array[size] = str[size];
    return (array);
}

char **my_str_to_word_array(char const *str, char separator)
{
    char **array = NULL;
    int ind = 0;

    if (str == NULL)
        return (NULL);
    array = array_alloc(str, separator);
    if (array == NULL)
        return (NULL);
    for (int i = 0 ; str[i] ; ind++) {
        for (; !c_separator(str[i], separator) && str[i] ; i++);
        array[ind] = string_array(str + i, separator);
        for (; c_separator(str[i], separator) && str[i] ; i++);
        for (; !c_separator(str[i], separator) && str[i] ; i++);
    }
    return (array);
}
