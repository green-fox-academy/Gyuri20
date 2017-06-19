#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include "printer.h"

#define COMMAND_LIST_TODOS           "h"
#define COMMAND_EXIT_TODOS           "e"
#define COMMAND_LIST_AV_PORTS        "l"
#define COMMAND_SET_PORT_NAME        "p"
#define COMMAND_SET_WRITE_FILENAME   "w"
#define COMMAND_OPEN_PORT            "o"
#define COMMAND_START_STOP_LOGGING   "s"
#define COMMAND_CLOSE_PORT           "c"
#define COMMAND_SET_READ_FILENAME    "r"
#define COMMAND_CALC_AVG_IN_PERIOD   "a"


int main()
{
    print_usage();
    while (1) {
        printf ("Please Enter a command:\n");

        char command[1];
        gets(command);
        if (strstr(command, COMMAND_LIST_TODOS) != NULL) {
            print_usage();
        } else if (strstr(command, COMMAND_EXIT_TODOS) != NULL) {
            printf("The program exits!");
            return -1;
        } else if (strstr(command, COMMAND_LIST_AV_PORTS) != NULL) {

        }
    }
    return 0;
}
