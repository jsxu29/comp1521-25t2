/*
Write a c program count_chars.c that uses getchar to read in characters until the user enters Ctrl-D and then prints
the total number of characters entered.
Use man 3 getchar to look at the manual entry.
*/

#include <stdio.h>

int main() {

    /*
    getchar()
    getchar()
    getchar() 
    ...
    user enters Ctrl-D -> getchar returns EOF

    print total number of characters entered
    */

    /*
    int c = getchar();
    int char_num = 0;
    while (c != EOF) {
        char_num++;
        c = getchar();
    }
    printf("total number of characters entered: %d\n", char_num);
    */

    int char_num = 0;
    int c;
    // (c = getchar()) -> is equal to c
    while ((c = getchar()) != EOF) {
        char_num++;
    }
    printf("total number of characters entered: %d\n", char_num);


    return 0;
}
