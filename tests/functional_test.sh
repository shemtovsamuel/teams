#!/bin/bash

echo "Test #1 (login)"

(echo -ne "/login"; sleep 0.05; echo -ne " \"william\"\n"; sleep 1) | LD_LIBRARY_PATH=../libs/myteams ../myteams_cli 127.0.0.1 4242 2>&1; echo $?

echo ""
echo "Test #2 (logout)"

(echo -ne "/login \"william\"\n"; sleep 0.05; echo -ne "/lo"; sleep 0.05; echo -ne "gout\n"; sleep 1) | LD_LIBRARY_PATH=../libs/myteams ../myteams_cli 127.0.0.1 4242 2>&1; echo $?

echo ""
echo "Test #3 (users)"
(echo -ne "/login \"william\"\n"; sleep 0.05; echo -ne "/users\n"; sleep 0.05; echo -ne "/logout\n"; sleep 1) | LD_LIBRARY_PATH=../libs/myteams ../myteams_cli 127.0.0.1 4242 2>&1; echo $?

echo ""
echo "Test Leandre"
(echo -ne "/login \"william\"\n/logout"; sleep 0.05; echo -ne "\n"; sleep 1) | LD_LIBRARY_PATH=../libs/myteams ../myteams_cli 127.0.0.1 4242; echo $?