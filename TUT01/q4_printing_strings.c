/*
 * What will happen when the above program is compiled and executed?
 * In particular, what does this look like in memory?
 * How could we fix this program?
 */

#include <stdio.h>

int main(void) {
    char str[10]; // - - - - - - - - - - 
    str[0] = 'H'; // H - - - - - - - - - 
    str[1] = 'i'; // H i - - - - - - - -
    str[2] = '\0'; // only stops printing when it hits a null-terminating char
    printf("%s", str); 
    return 0;
}