/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL: Ubuntu-20.04]
** File description:
** myteams_cli.h
*/

#ifndef MYTEAMS_CLI_H
    #define MYTEAMS_CLI_H

    #include <stdbool.h>
    #include <signal.h>
    #include <time.h>

    #define USELESS __attribute__((unused))

struct client {
    bool logged;
    int socket;
    char *uuid;
    char *user_name;
};
typedef struct client client_t;

typedef struct info_s {
    int port;
    char *ip;
} info_t;

static volatile sig_atomic_t client_loop = 1;

int check_args(int ac, char *av[]);
void helper(int ac, char *av[]);
char *get_user_input(void);
int launch_client(info_t info);
void read_server_message(client_t *client);
void send_user_message(client_t *client, char *message);
char **my_str_to_word_array(char const *str, char separator);
void handle_client(char *buffer, client_t *client);
void logout_client(client_t *client, char *message);
void free_array(char **array);
time_t convert_to_time_t(char *date);

#endif
