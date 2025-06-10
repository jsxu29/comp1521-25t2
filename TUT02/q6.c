// A simple program demonstrating how to represent a implementing an && in an
// if-statement in MIPS.
// This version: C, but a slightly less nice approach.

#include <stdio.h>

int main(void) {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);

    if (x <= 100) goto small_or_big;
    if (x >= 1000) goto small_or_big;
    
    // converted if (A && B) {} else {}
    // if (!A) then goto else
    // if (!B) then goto else
    // if condition logic then jump to after else logic

    printf("medium\n");
    goto epilogue;

small_or_big:
    printf("small/big\n");

epilogue:



}
