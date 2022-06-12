#!/bin/bash
make re; LD_LIBRARY_PATH=./libs/myteams ./myteams_cli ${1-127.0.0.1} ${2-4242}; make fclean