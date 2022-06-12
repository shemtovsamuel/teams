##
## EPITECH PROJECT, 2021
## B-NWP-400-PAR-4-1-myteams-william.karkegi [WSL: Ubuntu-20.04]
## File description:
## Makefile
##

all:
	make all -s -C ./myteams_cli_dir
	make all -s -C ./myteams_server_dir

clean:
	make clean -s -C ./myteams_cli_dir
	make clean -s -C ./myteams_server_dir

fclean: clean
	make fclean -s -C ./myteams_cli_dir
	make fclean -s -C ./myteams_server_dir
	$(RM) myteams_cli
	$(RM) myteams_server

re:	fclean all

.PHONY: all clean fclean re
