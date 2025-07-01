#include <stdio.h>

int main() {
    printf("%d = 0%3o = 0x%2x\n", 100, 100, 100);
    int num = 0144;
    printf("saved as octal, print as decimal: %d\n", num);
    return 0;
}
