/*
 * Given one command-line argument, the name of a file, read
 * a line from stdin, and write it to the specified file;
 * if the file exists, it should be overwritten
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // open file
    FILE *file = fopen(argv[1], "w");
    if (file == NULL) {
        perror("error opening file\n");
        return 1;
    }

    // read from stdin - FILE *
    // int c = fgetc(stdin);
    // while (c != EOF) {
    //     fputc(c, file);
    //     if (c == '\n') {
    //         break;
    //     }
    //     c = fgetc(stdin);
    // }

    int c;
    // (c = fgetc(stdin)) -> c
    while ((c = fgetc(stdin)) != EOF) {
        fputc(c, file);
        if (c == '\n') {
            break;
        }
    }

    // read a character
    // write char to file
    // read next char
    // write next char
    // ... 
    // EOF - end of file
    // stdin - control D -> end of input / end of file

    fclose(file);

    return 0;
}
