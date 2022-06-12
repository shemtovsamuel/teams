/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** server_log.h
*/

#ifndef SERVER_LOG_H_
    #define SERVER_LOG_H_

    #define SERVER_LOG_MESSAGES { \
        "Client connected", \
        "Client disconnected", \
        NULL \
    };

enum server_log_messages_enum {
    CLIENT_CONNECTED,
    CLIENT_DISCONNECTED,
};

void server_log(int id);

#endif
