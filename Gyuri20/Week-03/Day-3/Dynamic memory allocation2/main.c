#include <stdio.h>
#include <stdlib.h>

// TODO:
// Please create a program that asks for a count when it starts.
// It should ask for a number count times, then it shoud print the average of the numbers.
// It should delete any dynamically allocated resource before the program exits.

int main() {

    int num, i, *ptr, sum = 0;
        printf("Enter number of count: ");
        scanf("%d", &num);
        int average;

    ptr = (float*) calloc(num, sizeof(float));

    if(ptr == NULL){
        printf("Error! memory not allocated.");
        exit(0);
        }

    if(num > 0) {
        printf("Enter elements of array: ");
        for(i = 0; i < num; ++i){
            scanf("%d", ptr + i);
            sum += *(ptr + i);
            average = sum / num;
        }
        printf("Average = %d", average);
    } else {
        printf("Not bigger than 0!");
    }

    free(ptr);

  return 0;
}
