#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>
#include <conio.h>
#include <math.h>
#include <process.h>
#include <windows.h>
#include "server.h"

void display_help_info()
{
    printf("\nTOTORO CHAT\n");
    printf("====================\n");
    printf("Commands:\n");
    printf("h   Display this help info\n");
    printf("e   Exit\n");
    printf("n   Set user name\n");
    printf("l   List known users\n");
    printf("d   Send discovery request\n");
    printf("m   Send message\n\n");
    printf("Enter a command:\n");
}
