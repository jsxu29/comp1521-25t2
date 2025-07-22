/*
 * Given 1+ command-line arguments which are the pathnames of files or directories
 * If the file or directory is publically-writeable, it should change it to be not
 * publically-writeable, leaving other permissions unchanged.
 */

#include <sys/stat.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        perror("Usage error\n");
        return 1;
    }

    return 0;
}
