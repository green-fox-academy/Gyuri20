#include <stdio.h>
float pigenerator();

/* Write a non void function which returns the value of PI, so the following number:
3.14159
Try it out in the main function by printing out the result of the pi generator function!
*/

int main(){

   float a = pigenerator();

        printf("%.5f", a);

return 0;
}

float pigenerator(){

    float pi = 3.14159;

return pi;
}