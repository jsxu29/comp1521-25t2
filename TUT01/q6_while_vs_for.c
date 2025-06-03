/*
How could we rewrite the above program using a for loop? What subtle difference would there be between the two programs?
*/

#include <stdio.h>

int main(void) {
    /*
    int i = 0; // INIT
    while (i < 10) { // COND
        printf("%d\n", i); // BODY
        i++; // INCREMENT/STEP
    }
    */

    /*
    for (INIT; COND; INCREMENT) {
        BODY
    }
    */

    for (int i = 0; i < 10; i++) {
        printf("%d\n", i);
    }

    return 0;
}
