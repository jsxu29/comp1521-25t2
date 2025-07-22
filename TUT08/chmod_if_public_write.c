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

    struct stat s;
    for (int i = 1; i < argc; i++) {
        if (stat(argv[i], &s) != 0) {
            perror("unable to get file metadata\n");
            continue;
        }
        mode_t m = s.st_mode;
        // if publically (others permission group) writeable 

        if ((m & S_IWOTH) != 0) {
            // set not publically writeable
            //   0b ... --- --- -1-
            // &    ... 111 111 101
            //   0b ... --- --- -0-

            //      ... 000 000 010 = S_IWOTH
            //      ... 111 111 101 

            mode_t new_mode = m & ~S_IWOTH;

            // chmod(argv[i], new_mode) -> returns 0 upon success
            if (chmod(argv[i], new_mode) != 0) {
                perror("error changing mode\n");
            }
        }
    }

    return 0;
}
