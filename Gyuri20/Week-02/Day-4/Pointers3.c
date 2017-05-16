#include <stdio.h>

int main() {
    int number = 1234;
    int* number_pointer = &number;
    //TODO:
    (*number_pointer) = 42;
    printf("%d", number);
    // update the value of number variable to 42 using the "number_pointer"

    return 0;
}
