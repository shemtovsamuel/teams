/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** struct.h
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #include <arpa/inet.h>
    #include <stdbool.h>

enum client_context {
    USER_CONTEXT,
    TEAM_CONTEXT,
    CHANNEL_CONTEXT,
    THREAD_CONTEXT
};

struct reply {
    char *team_uuid;
    char *thread_uuid;
    char *user_uuid;
    char *reply_body;
    time_t reply_timestamp;
};
typedef struct reply reply_t;

struct thread {
    char *thread_uuid;
    char *user_uuid;
    time_t thread_timestamp;
    char *thread_title;
    char *thread_body;
    char *channel_uuid;
    char *team_uuid;
};
typedef struct thread thread_t;

struct queue {
    char *data;
    bool disconnect;
    struct queue *next;
};
typedef struct queue queue_t;

struct client {
    int fd;
    int data_fd;
    char *user_name;
    char *user_uuid;
    char *team_uuid;
    char *channel_uuid;
    char *thread_uuid;
    int context;
    char *req;
    bool logged;
    struct sockaddr_in client_addr;
    struct sockaddr_in data_addr;
    int type;
    queue_t *queue;
};
typedef struct client client_t;

struct user {
    char *user_name;
    char *user_uuid;
};
typedef struct user user_t;

struct server {
    int fd;
    int port;
    int nb_clients;
    int nb_users;
    user_t *arr_users;
    client_t *arr_clients;
};
typedef struct server server_t;

typedef void (*cmd_t)(server_t *, client_t *, char *);

#endif