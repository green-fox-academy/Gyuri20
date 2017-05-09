#include <stdint.h>

int main() {
    uint8_t a = 60;
    uint8_t b = 0b00111100;
    uint8_t c = 0x3C;
    uint8_t d = 0x3c;

    a = a * 2;
    b = b << 1;

    printf("------------------\n", d);
    printf("%x\n", a);
    printf("%x\n", b);
    printf("%x\n", c);
    printf("%x\n", d);
    printf("------------------\n", d);

    // Try with %x

    // Multiply a by 2


    // Shift left b by 1

    // Check their values
    printf("%x\n", a );
    printf("%x\n", b );
    printf("------------------\n", d);

    return 0;
}