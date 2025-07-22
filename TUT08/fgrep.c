// Write a C program, fgrep.c, which is given 1+ command-line arguments which is
// a string to search for.

// ./a.out <substring> 
// If there is only 1 command-line argument it should read lines from stdin and
// print them to stdout if they contain the string specified as the first 
// command line argument.

// ./a.out <substring> <file1> <file2> ... 
// If there are 2 or more command line arguments, it should treat arguments 
// after the first as filenames and print any lines in the files which contain
// the string specified as the first command line argument.
//
// When printing lines, preface them with their line number (indexed from 1).
//
// Print a suitable error message if there are not enough arguments, or there is
// an error opening a file.
//
// Example:
// ./fgrep hello nonexistentfile.txt
//  hello: nonexistentfile.txt: No such file or directory
//
// ./fgrep test testfile.txt
// line 1 from testfile.txt: This is a test
//
// Assume lines are 65536 bytes at most.

#include <stdio.h>
#include <string.h>

#define MAX_LINE 65536

void search_stream(FILE *stream, char stream_name[], char search_for[]);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <prefix> <files>\n", argv[0]);
        return 1;
    } else if (argc == 2) {
        // look through stdin for substring
        search_stream(stdin, "stdin", argv[1]);
    } else {
        // look through each file for substring
        for (int i = 2; i < argc; i++) {
            FILE *file = fopen(argv[i], "r");
            if (file == NULL) {
                fprintf(stderr, "%s: %s: No such file or directory", argv[1], argv[i]);
                continue;
            }
            search_stream(file, argv[i], argv[1]);
            fclose(file);
        }
    }
    return 0;
}

/*
 * Search through every line of the opened file / stream and look for the search string,
 * if it is apart of the line, we should print to standard output
 */
void search_stream(FILE *stream, char stream_name[], char search_for[]) {
    // TODO: complete this function
    // hint: look at `strstr(3)'
    
    /*
    similar to:
    int c;
    while ((c = fgetc(stdin)) != EOF) {
        fputc(c, file);
        if (c == '\n') {
            break;
        }
    }
    */

    // for every line in our file/stream
    int line_counter = 1;
    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, stream) != NULL) {
        // if substring in line, print to stdout
        if (strstr(line, search_for) != NULL) {
            printf("line %d from %s: %s", line_counter, stream_name, line);
        }
        line_counter++;
    }
}
