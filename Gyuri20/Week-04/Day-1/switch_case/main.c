#include <stdio.h>
#include <stdlib.h>
 /*
Write a program which receives a number between 0-10 from the user.
It prints out the english word for that number on the screen.
For example if the user enters 8, the program prints out "Eight".
Use switch-case in this task!
Handle the invalid user input!
*/

int main()
{
    int number;
    printf("Write a number: ");
    scanf("%d", &number);

    switch(number) {
         case 0 :
         printf("null\n" );
         break;
         case 1 :
         printf("one\n" );
         break;
         case 2 :
         printf("two\n" );
         break;
         case 3 :
         printf("three\n" );
         break;
         case 4 :
         printf("four\n" );
         break;
         case 5 :
         printf("five\n" );
         break;
         case 6 :
         printf("six\n" );
         break;
         case 7 :
         printf("seven\n" );
         break;
         case 8 :
         printf("eight\n" );
         break;
         case 9 :
         printf("nine\n" );
         break;
         case 10 :
         printf("ten\n" );
         break;
        default :
             printf("Invalid number\n" );
       }
}
