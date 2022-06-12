/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myftp-william.karkegi
** File description:
** server.c
*/

#include "myteams_server.h"
#include "server_log.h"
#include <stdlib.h>
#include <stdio.h>

static void accept_client(server_t *server)
{
    socklen_t size;
    int client_sock;
    int index = server->nb_clients;
    struct sockaddr *client_addr;

    server->arr_clients = realloc(server->arr_clients,
        sizeof(client_t) * (index + 1));
    check_error(server->arr_clients == NULL, "realloc");
    server->nb_clients++;
    size = sizeof(server->arr_clients[index].client_addr);
    client_addr = (struct sockaddr *)&server->arr_clients[index].client_addr;
    client_sock = accept(server->fd, client_addr, &size);
    check_error(client_sock == -1, "accept");
    init_client(&server->arr_clients[index], client_sock);
}

static int reset_fd(server_t *server, fd_set *read_fds,
    fd_set *write_fds)
{
    int max_fd = server->fd;

    FD_ZERO(read_fds);
    FD_ZERO(write_fds);
    FD_SET(server->fd, read_fds);
    for (int i = 0; i < server->nb_clients; i++) {
        FD_SET(server->arr_clients[i].fd, read_fds);
        if (server->arr_clients[i].queue != NULL)
            FD_SET(server->arr_clients[i].fd, write_fds);
        if (server->arr_clients[i].fd > max_fd)
            max_fd = server->arr_clients[i].fd;
    }
    return (max_fd + 1);
}

static void parse(server_t *server, fd_set *read_fds, fd_set *write_fds)
{
    for (int i = 0; i < server->nb_clients; ++i)
        if (FD_ISSET(server->arr_clients[i].fd, read_fds))
            handle_client(server, i);
    for (int i = 0; i < server->nb_clients; ++i)
        if (FD_ISSET(server->arr_clients[i].fd, write_fds))
            send_message_to_client(server, i);
}

void start_server(server_t *server)
{
    fd_set read_fds;
    fd_set write_fds;
    int max_fd = 0;
    int nb_fd = 0;

    while (true) {
        max_fd = reset_fd(server, &read_fds, &write_fds);
        nb_fd = select(max_fd, &read_fds, &write_fds, NULL, NULL);
        check_error(nb_fd == -1, "select");
        if (FD_ISSET(server->fd, &read_fds)) {
            accept_client(server);
            FD_CLR(server->fd, &read_fds);
            nb_fd--;
        }
        parse(server, &read_fds, &write_fds);
    }
}
