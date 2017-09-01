#include <stdio.h>
#include <stdlib.h>
#include <main.h>

void registration()
{
  static int i = 0;
  printf("You have %d free places to do a registration.\n\n", (5-i));
  if (i < 6) {
    printf("Registration:\n");
    printf("Please enter your username:");
    scanf("%s", user[i].Username);
    printf("Please enter your password:");
    scanf("%s", user[i].Password);
    printf("Registration was successfull!\n");
  } else {
    printf("You can't regist.\n");
  }
i++;
}

void print()
{
    printf("Please choose:\n");
    printf("Registration: \t R\n");
    printf("Login: \t\t L\n");
    printf("List: \t\t P\n");
    printf("Exit: \t\t E\n");
}
