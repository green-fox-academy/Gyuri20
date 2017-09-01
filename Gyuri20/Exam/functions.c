#include <stdio.h>
#include <stdlib.h>

struct user_struct {
    char Username[30];
    char Password[30];
}user[6];

void list()
{
    printf("List the registrations:\n\n");
    for (int i = 0; i < 5; i++) {
        printf("%d Username: %s\n", i + 1, user[i].Username);
        printf("%d Password: %s\n\n", i + 1, user[i].Password);
    }
}

void login()
{
    printf("Login:\n");

    printf("Please enter your username:");
    scanf("%s", user[5].Username);
    printf("Please enter your password:");
    scanf("%s", user[5].Password);

    int cntr = 0;

    for(int i = 0; i < 5; i++) {
        if(strcmp(user[i].Username, user[5].Username) == 0) {
            if(strcmp(user[i].Password, user[5].Password) == 0) {
                printf("You are successfully logged in!\n");
                printf("Please press Q to Log out!\n");
                while (1) {
                    if (kbhit()) {
                        char choic;
                        choic = getch();
                        switch(choic) {
                            case 'Q':
                                printf("Logged out!\n");
                                return 0;
                            default:
                                printf("Wrong choice, try again!\n");
                                printf("Please choose Q if you want to quit!)\n");
                                break;
                        }//switch
                    }//if
                }//while
            } else {
                printf("Your password is incorrect!\n");
            }
        } else {
            cntr++;
            if (cntr == 5) {
                printf("Your username is incorrect!\n");
                break;
            }//if
        }//else
    }//for
}//void

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
