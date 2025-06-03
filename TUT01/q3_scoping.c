/*
 * Assuming we still want get_num_ptr to return a pointer, how can we fix this code?
 * How does fixing this code affect each variable's location in memory?
 */

#include <stdio.h>

int *get_num_ptr(void);

int main(void) {
    int *num = get_num_ptr();
    printf("%d\n", *num);
}

int *get_num_ptr(void) {
    // int x = 42; initially, local variable only exists for this function/scope and return a dangling pointer
    int x = malloc(4); 
    return &x;
}