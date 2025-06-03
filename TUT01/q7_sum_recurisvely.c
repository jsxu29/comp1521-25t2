/*
This program scans in a number n and prints the sum of all integers up to and including n.

Rewrite the sum function so it uses recursion instead of a loop.

What happens in memory when this program runs? What is the difference between the loop and recursive versions?
*/

#include <stdio.h>

int sum(int n);

int main(int argc, char *argv[]) {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int result = sum(n);
    printf("Sum of all numbers up to %d = %d\n", n, result);

    return 0;
}

/*
int sum(int n) {
    int result = 0;
    for (int i = 0; i <= n; i++) {
        result += i;
    }
    return result;
}
*/

// n is a non-negative integer, i.e., it is 0 or larger
int sum(int n) {
    // base case
    if (n == 0) {
        return 0;
    }

    // recursive case - use sum(x) where x is something "smaller"
    /*
    sum(3) = 0 + 1 + 2 + 3
    sum(2) = 0 + 1 + 2
    sum(1) = 0 + 1
    sum(0) = 0
    */

    return n + sum(n - 1);
}

/* 
iterative (for loop) vs recursion (function calls itself)
- recursion requires a lot of stack memory for all the stack frames + local variables each function creates
- sometimes, time performance difference, but not in this case
*/