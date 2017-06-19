#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Print out the addresses with and without pointer
print out the values with and without pointer
 */


int main()
{
    int number = 2017;
    float Pi = 3.14;
    char letter = 't';
    int *number_pointer = &number;
    float *Pi_pointer = &Pi;
    char *letter_pointer = &letter;


    printf("%p\n", &number);
    printf("%p\n", &Pi);
    printf("%p\n", &letter);

    printf("%d\n", number);
    printf("%f\n", Pi);
    printf("%c\n", letter);

    printf("%d\n", *number_pointer);
    printf("%f\n", *Pi_pointer);
    printf("%c\n", *letter_pointer);

    printf("%p\n", number_pointer);
    printf("%p\n", Pi_pointer);
    printf("%p\n", letter_pointer);



    return 0;
}
