##
## EPITECH PROJECT, 2021
## B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL: Ubuntu-20.04]
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/helper.c	\
		src/utils/free_array.c	\
		src/utils/my_str_to_word_array.c	\
		src/utils/get_array_size.c	\
		src/utils/int_to_string.c	\
		src/signal/signal_handler.c	\
		src/server/server.c	\
		src/server/get_server_address.c	\
		src/server/handle_client.c	\
		src/queue/add_to_queue.c	\
		src/init/init_server.c	\
		src/init/init_client.c	\
		src/init/init_users.c	\
		src/free/free_server.c	\
		src/free/free_queue.c	\
		src/free/free_client.c	\
		src/error/check_error_input.c	\
		src/error/check_error.c	\
		src/send/send.c	\
		src/log/server_log.c	\
		src/file/check_file.c	\
		src/file/load_user_from_file.c	\
		src/file/parse_csv_file.c	\
		src/file/search_user_in_file.c	\
		src/file/write_user_to_file.c	\
		src/file/write_message_to_file.c	\
		src/file/load_users_from_file.c	\
		src/file/write_file.c	\
		src/file/check_exist.c	\
		src/file/check_exist_by_name.c	\
		src/file/write_channel_to_file.c	\
		src/file/write_team_to_file.c	\
		src/file/write_thread_to_file.c	\
		src/file/write_reply_to_file.c	\
		src/file/remove_line_from_file.c	\
		src/file/check_user_subscribe.c	\
		src/file/open_file.c	\
		src/file/read_file_by_line.c	\
		src/file/file_empty.c	\
		src/cmd/handle_cmd.c	\
		src/cmd/parse_cmd.c	\
		src/cmd/authentification.c \
		src/cmd/write.c	\
		src/cmd/get_line.c	\
		src/cmd/uuid.c	\
		src/cmd/user_status.c	\
		src/cmd/user/login.c	\
		src/cmd/user/logout.c	\
		src/cmd/user/user.c	\
		src/cmd/user/users.c	\
		src/cmd/user/send.c	\
		src/cmd/user/messages.c	\
		src/cmd/user/use.c	\
		src/cmd/info/info.c	\
		src/cmd/create/create.c	\
		src/cmd/create/create_team.c	\
		src/cmd/create/create_channel.c	\
		src/cmd/create/create_thread.c	\
		src/cmd/create/create_reply.c	\
		src/cmd/list/list.c	\
		src/cmd/list/list_team.c	\
		src/cmd/list/list_channel.c	\
		src/cmd/list/list_thread.c	\
		src/cmd/list/list_reply.c	\
		src/cmd/subscribe/subscribe.c	\
		src/cmd/subscribe/subscribed.c	\
		src/cmd/subscribe/subscribed_user.c	\
		src/cmd/subscribe/subscribed_team.c	\
		src/cmd/subscribe/unsubscribe.c	\

OBJ	=	$(SRC:.c=.o)

SRCTEST	=	src/cmd/uuid.c	\

TESTS	=	tests/test_uuid.c	\

NAME	=	myteams_server

CC	=	gcc

CFLAGS	=	-W -Wall -Wextra -Werror -g3

CPPFLAGS	=	-I./include -I../libs/myteams

LDFLAGS	=	-L./../libs/myteams -lmyteams -luuid

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
	mv $(NAME) ../

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
