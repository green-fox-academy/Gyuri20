/* Includes ------------------------------------------------------------------*/

#include "socket_server.h"
#include "lcd_log.h"
#include "cmsis_os.h"
#include "app_ethernet.h"
#include "lwip/sockets.h"
#include <string.h>

#define _WIN32_WINNT 0x0501
#define QUEUE_SIZE 1
#define SERVER_IP           "10.27.6.58"
//#define SERVER_PORT         1234
#define DATA_BUFFER_SIZE    1024


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

// TODO:
// Implement this function!
void socket_server_thread(void const *argument)
{

	// Server address structure initialization
	struct sockaddr_in addr_in;                                 // Inet address structure definition
	addr_in.sin_family = AF_INET;                               // This address is an internet address
	addr_in.sin_port = htons(54545);                      // Server port
	addr_in.sin_addr.s_addr = INADDR_ANY;             // Server IP
	struct sockaddr *addr = (struct sockaddr *)&addr_in;        // Make a struct sockaddr pointer, which points to the address stucture

	// Creating the socket
	int master_sock = socket(AF_INET, SOCK_STREAM, 0);
	// Check if socket is ok
	if (master_sock < 0)
		LCD_ErrLog("socket() ");

	// Start binding the socket to the previously set address
	int flag = bind(master_sock, addr, sizeof(*addr));
	// Check if the binding is ok
	if (flag < 0)
		LCD_ErrLog("bind() ");

	// Start listening on with the set socket with a predefined queue size
	flag = listen(master_sock, QUEUE_SIZE);
	// Check is listening is ok
	if (flag < 0)
		LCD_ErrLog("listen() ");

	LCD_UsrLog("Server is initialized, waiting for connections at %s:%d\n", SERVER_IP, SERVER_PORT);

	// Create variables which will be used in the while loop
	struct sockaddr client_addr;    // Client address structure
	int slave_sock;              // Slave socket definition, this will be used to store the incoming socket
	char buff[DATA_BUFFER_SIZE];                // Buffer for incoming and outgoing data
	int cntr = 1;                   // Counter for incoming connections
	while (1) {
		// Accept the connection and save the incoming socket
		slave_sock = accept(master_sock, &client_addr, NULL);
		// Check if the socket is valid
		if (slave_sock < 0)
			LCD_ErrLog("accept()");

		LCD_UsrLog("%d. connection accepted\n", cntr);

		// Receive the data sent by the client
		int received_bytes;
		do {
			received_bytes = recv(slave_sock, buff, DATA_BUFFER_SIZE, 0);
			if (received_bytes == 0) {
				LCD_UsrLog("Connection closed, waiting for an other connection!\n");
			} else if (received_bytes < 0) {
				LCD_UsrLog("Something went wrong with the client socket, trying to close it...\n");
				break;
			} else {
				// Terminate the string with zero
				buff[received_bytes] = '\0';
				// Print out the received data
				LCD_UsrLog("Received string: %s \n", buff);
				// Send back the received string
				send(slave_sock, buff, received_bytes, 0);
			}
		} while (received_bytes > 0);

		closesocket(slave_sock);
		LCD_UsrLog("%d. client socket closed\n\n", cntr);
		cntr++;
	}

	// Cleaning up used memory
	LCD_UsrLog("Closing server socket\n");
	closesocket(master_sock);
	LCD_UsrLog("Cleaning up WSA\n");
	//WSACleanup();
	//return 0;
}


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
