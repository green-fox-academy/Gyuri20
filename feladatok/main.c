#include <stdio.h>

int main() {
    int n,
    times = 100;

   for( n = 0; n <= times; n++ ){

        if ( n % 3 == 0 && n % 5 == 0)
                printf("Fizbuzz\n", n);

        if ( n % 3 == 0 )
                printf("fizz\n", n);

        if ( n % 5 == 0 )
                printf("buzz\n", n);


        if ( n % 3 != 0 || n % 5 != 0)
            printf("%d\n", n);
   }
	// print the even numbers till 20
	// Write a program that prints the numbers from 1 to 100.
	// But for multiples of three print "Fizz" instead of the number
	// and for the multiples of five print "Buzz".
	// For numbers which are multiples of both three and five print "FizzBuzz".
	return 0;
}
