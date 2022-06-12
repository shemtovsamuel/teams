/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-william.karkegi
** File description:
** help.c
*/

#include "myteams_cli.h"
#include "stdio.h"

static void print_first(void)
{
    printf("Your client will handle the following command :\n\n");
    printf("• /help : show help\n");
    printf("• /login [user_name] : set the user_name used by client\n");
    printf("• /logout : disconnect the client from the server\n");
    printf("• /users : get the list of all users that exist on the domain\n");
    printf("• /user [user_uuid] : get information about a user\n");
    printf("• /send [user_uuid] [message] : send a message to a user\n");
    printf("• /messages : get all messages that exist on the domain\n");
}

static void print_second(void)
{
    printf("• /subscribe [team_uuid] : subscribe to the event of a team ");
    printf("and its sub directories\n");
    printf("• /subscribed : get the list of all subscribed teams\n");
    printf("• /unsubscribe [team_uuid] : unsubscribe from a team\n");
    printf("• /use ?[team_uuid] ?[channel_uuid] ?[thread_uuid] : ");
    printf("use specify a context team/channel/thread\n");
    printf(
        "• /create : based on what is being used create the sub resource\n");
    printf("• /list : based on what is being used list all sub resources\n");
    printf("• /info :  based on what is being used list the current\n");
}

void help(client_t *client USELESS, char *message USELESS)
{
    print_first();
    print_second();
}
