/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myftp-william.karkegi
** File description:
** handle_client.c
*/

#include "myteams_server.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

static void client_req(server_t *server, int id, int ret, char const *req)
{
    char *cmd = NULL;
    char *data = NULL;

    if (ret == 0)
        return (disconnect_client(server, id));
    parse_cmd(&server->arr_clients[id].req, req, &cmd, &data);
    if (cmd == NULL && data == NULL)
        return;
    handle_cmd(server, &server->arr_clients[id], cmd, data);
    if (data != NULL)
        free(data);
}

void handle_client(server_t *server, int id)
{
    char buf[BUFFER_READ_SIZE] = {0};
    int ret = 0;
    int err = 0;
    socklen_t len = sizeof(err);
    int ret_val = getsockopt(server->arr_clients[id].fd, SOL_SOCKET, SO_ERROR,
        &err, &len);

    if (ret_val != 0 || err != 0)
        return;
    ret = read(server->arr_clients[id].fd, buf, BUFFER_READ_SIZE);
    check_error(ret < 0, "read :(");
    client_req(server, id, ret, buf);
}