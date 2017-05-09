#include <stdio.h>

int main() {
	float w = 24;
	int out = 0;
	// if w is even increment out by one
	if (((int)w % 2) == 0){

        printf("%d", ++out);

        }
        else
        {
           printf("%d", (int)w);
        }

	return 0;
}
