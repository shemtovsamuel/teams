/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL : Ubuntu-20.04]
** File description:
** file.h
*/

#ifndef FILE_H
    #define FILE_H

    #include "struct.h"

    #include <stdbool.h>

    #define USER_SAVE_FILE "./save/users.csv"
    #define USERS_MESSAGES_FILE "./save/messages.csv"
    #define TEAMS_SAVE_FILE "./save/teams.csv"
    #define CHANNELS_SAVE_FILE "./save/channels.csv"
    #define THREADS_SAVE_FILE "./save/threads.csv"
    #define REPLIES_SAVE_FILE "./save/replies.csv"
    #define SUBSCRIBE_SAVE_FILE "./save/subscribe.csv"

bool is_file_exist(char const *filepath);
void write_user_to_file(user_t user);
bool is_user_exist_in_file(char const *user_name);
user_t load_user_from_file_by_user_name(char const *user_name);
user_t load_user_from_file_by_uuid(char const *user_uuid);
user_t *load_users_from_file(void);
char ***parse_csv_file(char const *filepath);
void free_csv_array(char ***array);
void write_at_the_end_of_file(char *file_path, char *data);
void write_message_to_file(char *sender, char *receiver, char *message);
int get_nb_users_saved(void);
void write_team_to_file(char *team_uuid, char *team_name,
    char *team_description);
void write_channel_to_file(char *channel_uuid, char *channel_name,
    char *channel_description, char *team_uuid);
void write_thread_to_file(thread_t thread);
void write_reply_to_file(reply_t reply);
bool is_user_exist(char *user_uuid);
bool is_team_exist(char *team_uuid);
bool is_channel_exist(char *channel_uuid);
bool is_thread_exist(char *thread_uuid);
bool is_team_exist_by_name(char *team_name);
bool is_channel_exist_by_name(char *channel_name);
bool is_thread_exist_by_name(char *thread_name);
void remove_line_from_file(char *filepath, int line);
bool is_user_subscribe(char *user_uuid, char *team_uuid);
int open_file(const char *file_path);
int open_append_file(char *file_path);
ssize_t read_line(char *buffer, size_t size, int fd, off_t *offset);
bool is_file_empty(char const *file_name);

#endif