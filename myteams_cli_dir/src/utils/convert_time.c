/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi
** File description:
** convert_time.c
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "myteams_cli.h"

time_t convert_to_time_t(char *date)
{
    time_t t = (time_t)atoll(date);

    return (t);
}
