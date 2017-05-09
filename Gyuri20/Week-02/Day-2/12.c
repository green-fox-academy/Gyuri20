#include <stdio.h>
#include <stdint.h>

int main() {
    uint8_t a = 60;
    uint8_t b = 0b00111100;
    uint8_t c = 0x3C;
    uint8_t d = 0x3c;

    printf("------------------\n", d);
    printf("%x\n", a * 2);
    printf("%x\n", b << 1);
    printf("%x\n", c);
    printf("%x\n", d);
    printf("------------------\n", d);

    // Try with %x

    // Multiply a by 2


    // Shift left b by 1

    // Check their values
    printf("%x\n", a * 2);
    printf("%x\n", b << 1);
    printf("------------------\n", d);

    return 0;
}
