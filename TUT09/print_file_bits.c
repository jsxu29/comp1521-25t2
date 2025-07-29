// read 32-bit hexadecimal numbers from a file
// and print low (least significant) byte
// as a signed decimal number (-128..127)

#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    // open file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("file can not be opened\n");
        return 1;
    }

    int32_t num;
    // read each 32-bit hexadecimal number
    while (fscanf(file, "%x", &num) == 1) {
        // for each, get lowest byte
        //   -------- -------- -------- --------
        // & 00000000 00000000 00000000 11111111
        //   00000000 00000000 00000000 --------   
        int32_t lowest_byte = num & 0xFF;

        // sign extension: check if leading sign bit is 1
        //   00000000 00000000 00000000 --------
        // & 00000000 00000000 00000000 10000000
        //   00000000 00000000 00000000 -0000000 != 0

        if (lowest_byte & (1 << 7)) { // default is: compare condition value with != 0
        // if ((lowest_byte & (1 << 7)) != 0) {
            // fill left 3 bytes with 1s
            //   00000000 00000000 00000000 --------
            // | 11111111 11111111 11111111 00000000
            //   11111111 11111111 11111111 --------
            lowest_byte = lowest_byte | 0xFFFFFF00;
        }

        // print the lowest byte
        printf("%d\n", lowest_byte);
    }
    
    fclose(file);

    return 0;
}