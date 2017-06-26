#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>

//Create a client app that ping the google.com to get than latency, and print it out.

int main()
{
    int i = 0;
    i = system ("ping 172.217.18.67");
    printf ("The value returned was: %d.\n",i);
    return 0;
}
