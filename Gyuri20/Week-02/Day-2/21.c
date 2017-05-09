#include <stdio.h>
#include <stdint.h>

int main() {
	uint8_t ab = 123;
	uint8_t credits = 100;
	uint8_t is_bonus = 0;	// This means "false"

	// if is_bonus is true ab should remain the same
	if (is_bonus != 0){
        printf("%d", ab);
	}
    // if credits are at least 50,
	// and is_bonus is false decrement ab by
	if (credits >= 50){
        if (is_bonus == 0)
        printf("%d", ab+2);
	}
	// if credits are smaller than 50,
	// and is_bonus is false decrement ab by 1
	if (credits < 50){
        if (is_bonus == 0)
        printf("%d", ab+1);
}
	// if is_bonus is true ab should remain the same

	return 0;
}
