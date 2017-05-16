#include <stdio.h>

int main() {
    char char_array[] = {'a', 'b', 'c', 'd'};
    char char_array_the_same[] = "abcd";

	//TODO:
	for(int i = 0; i < 4 ; i++){
        printf("%c\n", char_array [i]);
    }
    // Print out the two arrays character-by-character

	//TODO:
	for(int i = 0; i < 4 ; i++){
        printf("%c\n", char_array_the_same [i]);
    }
    // What is the difference between the arrays?
    //nothing

    return 0;
}
