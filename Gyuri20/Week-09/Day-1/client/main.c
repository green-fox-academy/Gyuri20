#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>

// Create Server and Client Applications that send and receive messages.

int send_message(SOCKET *socket)
{
	// Get the message from the user
	char msg[4096];
	printf("\nEnter the message to send: ");
	gets(msg);
	// Send the message to the servers
	int sent_bytes = send(*socket, msg, strlen(msg), 0);
	if (sent_bytes < 0) {
		printf("Error");
        WSACleanup();
        exit(EXIT_FAILURE);
	}

	return sent_bytes;
}

int main(int argc , char *argv[])
{
    WSADATA wsa;
    SOCKET s;
    struct sockaddr_in server;
    char *message , server_reply[4096];
    int recv_size;

    printf("\nInitialising Winsock...");
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        printf("Failed. Error Code : %d",WSAGetLastError());
        return 1;
    }

    printf("Initialised.\n");

    //Create a socket
    if((s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
    {
        printf("Could not create socket : %d" , WSAGetLastError());
    }

    printf("Socket created.\n");


    server.sin_addr.s_addr = inet_addr("10.27.6.113");
    server.sin_family = AF_INET;
    server.sin_port = htons( 8888 );

    //Connect to remote server
    if (connect(s , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        puts("connect error");
        return 1;
    }

    puts("Connected");

    //Send some data

    int sent_bytes = 0;
    int received_bytes = 0;
    char recv_buffer[4096];
    do {
		// Send data to the server
		sent_bytes = send_message(&s);
		// Receive the answer if message was sent
		if (sent_bytes > 0) {
			received_bytes = recv(s, recv_buffer, 4096, 0);
			// Error handling
			if (received_bytes < 0) {
				printf("Error");
                WSACleanup();
                exit(EXIT_FAILURE);
			} else {
				// Printing out received string
				recv_buffer[received_bytes] = '\0';
				printf("Received string: %s\n", recv_buffer);
			}
		}
	} while (sent_bytes > 0);

    /*message = "GET / HTTP/1.1\r\n\r\n";
    if( send(s , message , strlen(message) , 0) < 0)
    {
        puts("Send failed");
        return 1;
    }
    puts("Data Send\n");*/

    //Receive a reply from the server
    if((recv_size = recv(s , server_reply , 4096 , 0)) == SOCKET_ERROR)
    {
        puts("recv failed");
    }

    puts("Reply received\n");

    //Add a NULL terminating character to make it a proper string before printing
    //server_reply[recv_size] = '\0';
    //puts(server_reply);
    printf("Closing the socket...\n");
	closesocket(s);
	printf("Cleaning up memory...\n");
	WSACleanup();

    return 0;
}
