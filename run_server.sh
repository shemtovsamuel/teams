#!/bin/bash
make re; LD_LIBRARY_PATH=./libs/myteams ./myteams_server ${1-4242}; make fclean