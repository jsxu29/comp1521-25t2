/*
 * Write a C program that reads a null-terminated UTF-8 string as a command line
 * argument and counts how many Unicode characters (code points) it contains.
 * Assume that all codepoints in the string are valid.
 * 
 * Examples:
 * ./count_utf8 "チョコミント、よりもあなた！"
    there are 14 codepoints in the string
 * ./count_utf8 "早上好中国现在我有冰淇淋"
    there are 12 codepoints in the string
 * ./count_utf8 "🤓🤓🤓🤓🤓🤓🤓🤓"
    there are 8 codepoints in the string
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        return 1;
    }

    // unicode string - argv[1] - char* or array that is null-terminated
    char *unicode_string = argv[1];

    int count = 0;
    // continue reading through char array until argv[1][index] = null-terminator
    for (int index = 0; unicode_string[index] != '\0'; ) {
        // read first byte of each unicode character
        char first_byte = unicode_string[index];
        // move forward by number of bytes for unicode character - given by the format of first byte
        // to reach the next unicode character
        int unicode_char_len = 0;
        
        // 0xxxxxxx - len = 1
        //   xxxxxxxx
        // & 10000000
        //   x0000000
        if ((first_byte & (1 << 7)) == 0) {
            unicode_char_len = 1;
        }

        // 110xxxxx - len = 2
        //   xxxxxxxx
        // & 11100000 = 0xE0
        //   xxx00000
        // 1100 0000 = 0xC0
        else if ( (first_byte & 0xE0) == 0xC0) {
            unicode_char_len = 2;
        }

        // 1110xxxx - len = 3
        //   xxxxxxxx
        // & 11110000 = 0xF0
        //   xxxx0000
        // 1110 0000 = 0xE0
        else if ( (first_byte & 0xF0) == 0xE0) {
            unicode_char_len = 3;
        }

        // 11110xxx - len = 4
        //   xxxxxxxx
        // & 1111 1000 = 0xF8
        //   xxxx0000
        // 1111 0000 = 0xF0
        else if ( (first_byte & 0xF8) == 0xF0) {
            unicode_char_len = 4;
        }

        count++;
        index += unicode_char_len;
    }
    
    printf("There are %d unicode characters in this string\n", count);

    return 0;
}