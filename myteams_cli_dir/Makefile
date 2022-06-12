##
## EPITECH PROJECT, 2021
## B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL: Ubuntu-20.04]
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/check_args.c	\
		src/helper.c	\
		src/get_user_input.c	\
		src/launch_client.c	\
		src/read_server_message.c	\
		src/send_user_message.c	\
		src/utils/my_str_to_word_array.c \
		src/utils/free_array.c \
		src/utils/convert_time.c \
		src/cmd/create.c \
		src/cmd/help.c \
		src/cmd/info.c \
		src/cmd/list.c \
		src/cmd/login.c \
		src/cmd/logout.c \
		src/cmd/messages.c \
		src/cmd/send.c \
		src/cmd/subscribe.c \
		src/cmd/subscribed.c \
		src/cmd/unsubscribe.c \
		src/cmd/user.c \
		src/cmd/users.c \
		src/cmd/event_channel.c \
		src/cmd/event_reply.c \
		src/cmd/event_team.c \
		src/cmd/event_thread.c \
		src/cmd/event_send.c \
		src/cmd/error_autho.c \
		src/cmd/error_unknow.c \
		src/handle_client.c

OBJ	=	$(SRC:.c=.o)

NAME	=	myteams_cli

CC	=	gcc

CFLAGS	=	-W -Wall -Wextra -Werror

CPPFLAGS	=	-I./include -I../libs/myteams

LDFLAGS	=	-L./../libs/myteams -lmyteams

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
