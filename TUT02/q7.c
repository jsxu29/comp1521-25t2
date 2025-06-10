// Print every third number from 24 to 42.
#include <stdio.h>

int main(void) {
    // This 'for' loop is effectively equivalent to a while loop.
    // i.e. it is a while loop with a counter built in.
    // for (int x = 24; x < 42; x += 3) {
    //     printf("%d\n", x);
    // }

    // int x = 24; // INIT
    // while (x < 42) { // COND
        // printf("%d\n", x); // BODY
        // x += 3; // STEP
    // }

    int x = 24; // INIT

loop_cond:
    if (x >= 42) goto loop_post; // COND

loop_body:   
    // BODY
    printf("%d", x); // BODY
    printf("\n");
    
loop_step:
    // STEP
    x += 3;
    // jump to cond
    goto loop_cond;

loop_post:
    // EXIT WHILE LOOP
}
