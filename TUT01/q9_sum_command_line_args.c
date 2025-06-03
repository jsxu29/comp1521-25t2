/*
Why do we need the function atoi in the following program?

The program assumes that command-line arguments are integers. What if they are not integer values?
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int sum = 0;
    // i = 0, 1, 2, ..., argc - 1
    for (int i = 0; i < argc; i++) {
        sum += atoi(argv[i]); // we convert the INITIAL PORTION of the command-line argument to integer, if it is entirely letters, it gets converted to 0
    }
    printf("sum of command-line arguments = %d\n", sum);
    return 0;
}
