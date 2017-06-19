#include <stdio.h>
#include <stdlib.h>


int main()
{
    int number;
    int choice;
    printf("Please write a number: ");
    scanf("%d", &number);

    printf("\t**********\n\tHello User\n\t**********\nYou have an integer named 'number'\n");
    printf("- for it's memory address please press 1\n");
    printf("- for it's current value please press 2\n");
    printf("- to double it's value please press 3\n");

    scanf("%d", &choice);
    if (choice == 1) {
        printf("%d", &number);
    }
    else if (choice == 2) {
        printf("%d", number);
    }
    else if (choice == 3) {
        printf("%d", number * 2);
    }
}
