#include <stdio.h>
#include <stdint.h>

int main() {
    int16_t x = 30000;
    int16_t y = x + x;
    // explain what it prints out?
    printf("%d\n", y);
    return 0;
}