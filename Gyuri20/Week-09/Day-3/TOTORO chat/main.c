#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>
#include <conio.h>
#include <math.h>
#include <process.h>
#include <windows.h>
#include "server.h"

void handle_error(const char *error_string)
{
	printf("Error: %s\nError code: %d\n", error_string, WSAGetLastError());
	WSACleanup();
	printf("Press any key to exit from the program...");
	while (!kbhit());
	exit(EXIT_FAILURE);
}

void wsa_init()
{
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != NO_ERROR)
		handle_error("WSAStartup() ");
}

int main()
{
    wsa_init();

    printf("Hello world!\n");
    display_help_info();

    while (1) {
        if (kbhit()) {
            char userinput;
            userinput = getch();
            switch (userinput) {
                case 'h':
                    display_help_info();
                    break;
                case 'e':
                    printf("Exit:\n");
                    return 0;
                case 'n':
                    name();
                    break;
                case 'l':
                    printf("l\n");
                    break;
                case 'd':
                    printf("d\n");
                    break;
                case 'm':
                    printf("m\n");
                    break;
            }
        }
    }
    //_beginthread(threat_server1, 0, NULL);
    //_beginthread(threat_client, 0, NULL);

    return 0;
}
