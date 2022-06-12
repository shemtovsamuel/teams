/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** cmd.h
*/

#ifndef CMD_H
    #define CMD_H

    #include "myteams_server.h"
    #include "struct.h"

    #define FUNCS_NAME { \
        "/login", \
        "/logout", \
        "/user", \
        "/users", \
        "/send", \
        "/messages", \
        "/use", \
        "/info", \
        "/create", \
        "/list", \
        "/subscribe", \
        "/unsubscribe", \
        "/subscribed", \
        NULL \
    };
    #define FUNCS { \
        &login, \
        &logout, \
        &user, \
        &users, \
        &send_cmd, \
        &messages, \
        &use, \
        &info, \
        &create, \
        &list, \
        &subscribe, \
        &unsubscribe, \
        &subscribed, \
    };

void login(server_t *server, client_t *client, char *data);
void logout(server_t *server, client_t *client, char *data USELESS);
void user(server_t *server, client_t *client, char *data);
void users(server_t *server, client_t *client, char *data USELESS);
void send_cmd(server_t *server USELESS, client_t *client, char *data);
void messages(server_t *server, client_t *client, char *data);
void use(server_t *server USELESS, client_t *client, char *data);
void info(server_t *server USELESS, client_t *client, char *data USELESS);
void create(server_t *server, client_t *client, char *data);
void list(server_t *server, client_t *client, char *data USELESS);
void subscribe(server_t *server USELESS, client_t *client, char *data);
void unsubscribe(server_t *server, client_t *client, char *data);
void subscribed(server_t *server, client_t *client, char *data);

char *generate_uuid(void);

#endif