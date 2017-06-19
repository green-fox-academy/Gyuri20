#include <stdio.h>
#include <stdlib.h>

// TODO:
// Please create a program that asks for a count when it starts.
// It should ask for a number count times, then it shoud print the average of the numbers.
// It should delete any dynamically allocated resource before the program exits.

int main()
{
    int count;
    int sum = 0;
    int number = 0;
    int average;

    printf("Please write a count\n");
    scanf("%d", &count);

    int* pointer = (int*)calloc(count, sizeof(int));

    for (int i = 0; i < count; i++) {
        printf("please add numbers count times\n");
        scanf("%d", &number);
        sum = sum + number;
    }
    average = sum / count;
    printf("%d", average);

    free(*pointer);

    return 0;
}
