/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi
** File description:
** help.h
*/

#ifndef CMD_H
    #define CMD_H

    #include "myteams_cli.h"

    #define FUNCS_NAME { \
        "/help", \
        "/login", \
        "/user", \
        "/users", \
        "/send", \
        "/messages", \
        "/subscribe", \
        "/subscribed", \
        "/unsubscribe", \
        "/event_reply", \
        "/event_team", \
        "/event_channel", \
        "/event_thread", \
        "/create_reply", \
        "/create_team", \
        "/create_channel", \
        "/create_thread", \
        "/list_team", \
        "/list_channel", \
        "/list_thread", \
        "/list_thread_replies", \
        "/info_user", \
        "/info_team", \
        "/info_channel", \
        "/info_thread", \
        "/event_send", \
        "/event_login", \
        "/event_logout", \
        "/unknow_team", \
        "/unknow_channel", \
        "/unknow_thread", \
        "/unknow_user", \
        "/unauthorized", \
        "/already_exist", \
        NULL \
    };
    #define FUNCS { \
        &help, \
        &login, \
        &user, \
        &users, \
        &send_client, \
        &messages, \
        &subscribe, \
        &subscribed, \
        &unsubscribe, \
        &event_reply, \
        &event_team, \
        &event_channel, \
        &event_thread, \
        &create_reply, \
        &create_team, \
        &create_channel, \
        &create_thread, \
        &list_team, \
        &list_channel, \
        &list_thread, \
        &list_thread_replies, \
        &info_user, \
        &info_team, \
        &info_channel, \
        &info_thread, \
        &event_send, \
        &event_login, \
        &event_logout, \
    };

void help(client_t *client, char *message);
void login(client_t *client, char *message);
void user(client_t *client, char *message);
void users(client_t *client, char *message);
void send_client(client_t *client, char *message);
void messages(client_t *client, char *message);
void subscribe(client_t *client, char *message);
void subscribed(client_t *client, char *message);
void unsubscribe(client_t *client, char *message);
void event_reply(client_t *client, char *message);
void event_team(client_t *client, char *message);
void event_channel(client_t *client, char *message);
void event_thread(client_t *client, char *message);
void create_reply(client_t *client, char *message);
void create_team(client_t *client, char *message);
void create_channel(client_t *client, char *message);
void create_thread(client_t *client, char *message);
void list_team(client_t *client, char *message);
void list_channel(client_t *client, char *message);
void list_thread(client_t *client, char *message);
void list_thread_replies(client_t *client, char *message);
void info_user(client_t *client, char *message);
void info_team(client_t *client, char *message);
void info_channel(client_t *client, char *message);
void info_thread(client_t *client, char *message);
void event_send(client_t *client, char *message);
void event_login(client_t *client, char *message);
void event_logout(client_t *client, char *message);
void unknow_team(client_t *client USELESS, char *message);
void unknow_channel(client_t *client USELESS, char *message);
void unknow_thread(client_t *client USELESS, char *message);
void unknow_user(client_t *client USELESS, char *message);
void unauthorized(client_t *client USELESS, char *message USELESS);
void already_exist(client_t *client USELESS, char *message USELESS);

typedef void (*cmd_t)(client_t *, char *);

#endif