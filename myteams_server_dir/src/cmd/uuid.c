/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** uuid.c
*/

#include <uuid/uuid.h>
#include <stdlib.h>

char *generate_uuid(void)
{
    uuid_t binuuid;
    char *uuid = malloc(sizeof(char) * 37);

    uuid_generate_random(binuuid);
    uuid_unparse(binuuid, uuid);
    return (uuid);
}