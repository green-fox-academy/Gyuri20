#include <stdio.h>
#include <stdlib.h>
#define TOTORO 19

// Define the TOTORO macro which holds a number

int main()
{
    // Use the #if, #elif, #else macros

    // If the TOTORO macro is greater than 3 print out "Greater than 3"
        #if TOTORO > 3
        printf("Greater than 3");
            #elif TOTORO < 3
            printf("Greater than 3");
            #else TOTORO == 3
            printf("Greater is 3");
        #endif
        // TOTORO
        // TOTORO
        // If the TOTORO macro is lower than 3 print out "Lower than 3"
        // Else print out "TOTORO is 3"


    return 0;
}
