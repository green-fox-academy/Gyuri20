#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    printf("write a number\n");
    scanf("%d", &number);


    if((number % 2) == 0) {
        printf("Even");
    } else {
        printf("Odd");
    }
   /*
Write a program that reads a number form the standard input,
than prints "Odd" if the number is odd, or "Even" it it is even.
*/
}
