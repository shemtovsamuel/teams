/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myftp-william.karkegi
** File description:
** add_to_queue.c
*/

#include "myteams_server.h"
#include <stdlib.h>
#include <string.h>

static queue_t *new_element(char const *message, bool disconnection)
{
    queue_t *new = malloc(sizeof(queue_t));

    check_error(new == NULL, "malloc failed");
    new->data = strdup(message);
    check_error(new->data == NULL, "strdup failed");
    new->disconnect = disconnection;
    new->next = NULL;
    return (new);
}

void add_to_client_queue(client_t *client, char const *message,
    bool disconnection)
{
    queue_t *temp;

    if (client->queue == NULL)
        client->queue = new_element(message, disconnection);
    else {
        temp = client->queue;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_element(message, disconnection);
    }
}