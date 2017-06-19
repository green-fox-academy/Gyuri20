#include <stdio.h>
/* Write a function which is called "get_fibonacci_number". It returns the "N"th
 * Fibonacci number, where "N" is received as a paramter.
 * For example:
 *  - get_fibonacci_number(1) returns 0
 *  - get_fibonacci_number(2) returns 1
 *  - get_fibonacci_number(3) returns 1
 *  - get_fibonacci_number(4) returns 2
 *  - get_fibonacci_number(5) returns 3
 *  - get_fibonacci_number(6) returns 5
 *
 *  If the function gets invalid parameter it returns -1.
 */

/*
Using that function create a program, which gets a number from the user, and
prints out the "N"th Fibonacci number, where "N" is the user given number.
Alert the user if he/she entered invalid value.
*/
int get_fibonacci_number() {

    int number = 0;
    int first_number = 0;
    int second_number = 1;
    int next = 0;
    int n;

    printf("Please write a number: ");
    scanf("%d", &number);

    if(number == 0){
        return -1;
    } else if (number == 1){
        return 0;
    } else {
        for(n = 0; n < number -2 ; n++) {
            next = first_number + second_number;
            first_number = second_number;
            second_number = next;
        }
    }
return next;
}

int main() {

   int a = get_fibonacci_number();
   printf("%d", a);

   return 0;
}
