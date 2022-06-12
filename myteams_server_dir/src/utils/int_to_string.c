/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** int_to_string.c
*/

#include <stdlib.h>

char *ld_to_string(long int nb)
{
    int len = 0;
    int is_neg = 0;
    char *str = malloc(sizeof(char) * 50);

    if (nb < 0) {
        nb *= -1;
        is_neg = 1;
        str[0] = '-';
    }
    for (int i = nb; i != 0; i /= 10)
        len++;
    for (int i = 0; i < len; i++) {
        str[len - (i + 1 - is_neg)] = (nb % 10) + '0';
        nb = nb / 10;
    }
    str[len + is_neg] = '\0';
    return (str[0] == '\0' ? "0" : str);
}