/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myftp-william.karkegi
** File description:
** init_server.c
*/

#include "myteams_server.h"
#include "logging_server.h"
#include "file.h"
#include "struct.h"
#include <stdlib.h>
#include <stdio.h>

static struct sockaddr_in get_default_server_addr(int port)
{
    struct sockaddr_in server_addr = {0};

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    return (server_addr);
}

static int init_server_socket(int port)
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = get_default_server_addr(port);
    int ret = 0;

    check_error(fd == -1, "socket() failed");
    ret = setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &server_addr, sizeof(int));
    check_error(ret == -1, "setsockopt() failed");
    ret = bind(fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    check_error(ret == -1, "bind() failed");
    ret = listen(fd, MAX_CLIENTS);
    check_error(ret == -1, "listen() failed");
    return (fd);
}

static void display_all_saved_users(void)
{
    user_t *users = load_users_from_file();
    int nb_users = get_nb_users_saved();

    if (users == NULL)
        return;
    for (int i = 0; i < nb_users; ++i)
        server_event_user_loaded(users[i].user_uuid, users[i].user_name);
}

void init_server(server_t *server, int port)
{
    get_server_address(server);
    server->fd = init_server_socket(port);
    server->port = port;
    init_users(server);
    server->arr_clients = NULL;
    server->nb_clients = 0;
    display_all_saved_users();
}