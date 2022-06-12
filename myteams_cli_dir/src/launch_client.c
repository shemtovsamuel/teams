/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi
** File description:
** lauch_client.c
*/

#include "myteams_cli.h"
#include "cmd.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

static void sig_handler(int sig USELESS)
{
    client_loop = 0;
}

static void loop_client(client_t *client)
{
    fd_set fd_read;

    signal(SIGINT, sig_handler);
    while (client_loop) {
        FD_ZERO(&fd_read);
        FD_SET(STDIN_FILENO, &fd_read);
        FD_SET(client->socket, &fd_read);
        if (select(client->socket + 1, &fd_read, NULL, NULL, NULL) == -1)
            return;
        if (FD_ISSET(STDIN_FILENO, &fd_read))
            send_user_message(client, get_user_input());
        else if (FD_ISSET(client->socket, &fd_read))
            read_server_message(client);
    }
    printf("\n");
    logout_client(client, "/logout");
}

static void connect_to_server(client_t *client, info_t info)
{
    struct sockaddr_in server_addr;
    struct hostent *server;
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_fd < 0)
        exit(84);
    if ((server = gethostbyname(info.ip)) == NULL)
        exit(84);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(info.port);
    server_addr.sin_addr.s_addr = inet_addr(info.ip);
    if (connect(socket_fd, (struct sockaddr *)&server_addr,
        sizeof(server_addr)) < 0)
        exit(84);
    client->socket = socket_fd;
}

int launch_client(info_t info)
{
    client_t client = {0};

    connect_to_server(&client, info);
    loop_client(&client);
    return (0);
}
