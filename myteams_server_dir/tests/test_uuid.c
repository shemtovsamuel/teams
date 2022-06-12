/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** test_uuid.c
*/

#include <criterion/criterion.h>
#include "cmd.h"

Test(generate_uuid, test_generate_uuid)
{
    char *uuid = generate_uuid();

    cr_assert_str_not_empty(uuid);
    free(uuid);
}