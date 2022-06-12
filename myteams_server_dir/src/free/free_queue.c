/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myftp-william.karkegi
** File description:
** free_queue.c
*/

#include "myteams_server.h"
#include <stdlib.h>

void free_queue(queue_t *queue)
{
    queue_t *temp = NULL;

    while (queue != NULL) {
        temp = queue;
        queue = queue->next;
        free(temp->data);
        free(temp);
    }
}