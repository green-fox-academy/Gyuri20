#include <stdio.h>
void function();
/* Write a void function which has two float parameters. The function can do the
totoro operation on those parameters and it also prints out the result of the operation
on the screen.
The totoro operation does the following on two variables (let's say we have "a"
 and "b")
result = a*b+(a+b)+a*a*a+b*b*b+3.14159265358979
*/

int main(){

    function();

    return 0;
}

void function(){

    float a = 3;
    float b = 6;


        float result = a*b+(a+b)+a*a*a+b*b*b+3.14159265358979;


            printf("let's say we have %.1f and %.1f\n", a, b);

                printf("The result is: %f\n", result);


return;
}
