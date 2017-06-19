#include <stdio.h>

int main()
{
    char char_array[] = {'a', 'b', 'c', 'd'};
    char char_array_the_same[] = "abcd";

    //TODO:
    // Print out the two arrays character-by-character
    for (int i = 0; i < 4; i++)
        printf("%c", char_array[i]);
        printf("\n");
    //TODO:
    // What is the difference between the arrays?
    for (int j = 0; j < 4; j++)
        printf("%c", char_array_the_same[j]);

    return 0;
}
