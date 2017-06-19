#include <stdio.h>
#include <stdlib.h>

void function() {

    char sentece[] = "I won't cheat on the test!";
    int cntr = 0;

    for(int i = 0; i < 100; i++) {
        cntr++;
        printf("%d\t %s\n", cntr, sentece);
    }
}

int main() {

    function();

}
    /*
Create a program which writes down the following sentence 100 times:
"I won't cheat on the test!"
Do it with:
    - for loop
    - while loop
    - do while loop
Also create a funtion which does the same.
*/

