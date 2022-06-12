/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL: Ubuntu-20.04]
** File description:
** myteams_server.h
*/

#ifndef MYTEAMS_SERVER_H
    #define MYTEAMS_SERVER_H

    #include "struct.h"

    #include <sys/select.h>
    #include <stddef.h>

    #define MAX_NAME_LENGTH 32
    #define MAX_DESCRIPTION_LENGTH 255
    #define MAX_BODY_LENGTH 512

    #define MAX_CLIENTS 100
    #define BUFFER_READ_SIZE 4096
    #define REQUEST_END "\r\n"
    #define USELESS __attribute__((unused))

void handle_client(server_t *server, int id);
void disconnect_client(server_t *server, int id);
void send_message_to_client(server_t *server, int id);
void init_server(server_t *server, int port);
void init_users(server_t *server);
server_t *get_server_address(server_t *server);
void start_server(server_t *server);
void add_to_client_queue(client_t *client, char const *message,
    bool disconnection);
void init_client(client_t *client, int client_sock);
void check_error(bool condition, char const *message);
void free_server(void);
void free_queue(queue_t *queue);
void check_error_input(int ac, char **av);
void display_help(bool is_error);
void signal_handler(int sig USELESS);
char *get_path(char *home, char *wd, char *path);
char *get_relative_path(char *home, char *path);
void help(char *data USELESS, client_t *client USELESS, user_t *user USELESS,
    int id USELESS);
void reset_client_security(client_t *client);
void verify_user(client_t *client, user_t *user);
void authentification(client_t *client, user_t *users, int index);
char *get_line(char const *dir);
int accept_connection(int fd);
void write_to_client(int fd, char const *message);
void stor(client_t *client, char *data);

// cmd
void handle_cmd(server_t *server, client_t *client, char *cmd, char *data);
void parse_cmd(char **client_req, char const *req, char **cmd, char **data);
bool is_user_online(user_t user, server_t *server);
void create_team(server_t *server, client_t *client, char *data);
void create_channel(server_t *server, client_t *client, char *data);
void create_thread(server_t *server, client_t *client, char *data);
void create_reply(server_t *server, client_t *client, char *data);
void list_team(server_t *server, client_t *client);
void list_channel(server_t *server, client_t *client);
void list_thread(server_t *server, client_t *client);
void list_reply(server_t *server, client_t *client);
void subscribed_user(client_t *client, char *data);
void subscribed_team(server_t *server, client_t *client, char *data);

#endif
