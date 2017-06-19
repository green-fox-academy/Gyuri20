#include <stdio.h>
#include <stdlib.h>

int main() {

    char name;
    int age;

    printf("Please write your name: \n");
        scanf("%s", &name);

    printf("Please write your age: \n");
        scanf("%d", &age);

#define CURRENT_YEAR 2017
    int hundred_years_old = CURRENT_YEAR - (age+1) + 100;

    printf("You will be 100 years old in: %d\n", hundred_years_old);

    /*
Create a program which ask for a name and an age.
From the age it tells the user when he or she will be 100 years old.
You should only take care of the years (don't bother with the months or days).
*/
}
