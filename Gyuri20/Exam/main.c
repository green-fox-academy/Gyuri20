#include <stdio.h>
#include <stdlib.h>

int main()
{
    print();
    while (1) {
        if (kbhit()) {
            char choice;
            choice = getch();
            switch(choice) {
                case 'R':
                    registration();
                    printf("Please choose:\t(or Help: H)\n");
                    break;
                case 'L':
                    login();
                    printf("Please choose:\t(or Help: H)\n");
                    break;
                case 'E':
                    printf("You are OUT!\n");
                    return 0;
                case 'H':
                    print();
                    break;
                case 'P':
                    list();
                    break;
                default:
                    printf("Wrong choice, try again!\n");
                    printf("Please choose:\t(or Help: H)\n");
                    break;
            }
        }
    }
    return 0;
}
