#include <stdio.h>
#include <stdint.h>

int main() {
    int16_t x = 30000;
    // range for int16_t: -2^15 to 2^15 - 1
    int16_t y = x + x; // 30000 + 30000 = 60000, which is beyond what an int16_t can store
    // explain what it prints out?
    printf("%d\n", y);
    return 0;
}