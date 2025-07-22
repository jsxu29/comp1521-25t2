// Write a C program, fgrep.c, which is given 1+ command-line arguments which is
// a string to search for.
// If there is only 1 command-line argument it should read lines from stdin and
// print them to stdout if they contain the string specified as the first 
// command line argument.
//
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
    } else {
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
    
}
