#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>
#include <conio.h>
#include <math.h>
#include <process.h>
#include <windows.h>
#include "server.h"

void name()
{
    printf("Please Enter your name:\n");
    char name[30];
    gets(&name);
    printf("From now your name is: %s\n", name);
}
