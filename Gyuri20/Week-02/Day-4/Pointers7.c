#include <stdio.h>

int main() {
    int high_number = 6655;
    int low_number = 2;
    printf("low_number: %p \t high_number: %p",   &low_number, &high_number);

    int* high_number_pointer = &low_number;
    int* low_number_pointer = &high_number;
    //TODO:
    // Please fix the problem and swap where the pointers point,
    // without using the "&" operator.
    int p_high_number = low_number_pointer;
    low_number_pointer = high_number_pointer;
    high_number_pointer = p_high_number;

    printf("\nlow_number_pointer: %d \t high_number_pointer: %d",   *low_number_pointer, *high_number_pointer);


    return 0;
}
