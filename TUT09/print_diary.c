// print contents of $HOME/.diary to stdout

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // get env variable $HOME
    char *home_env = getenv("HOME");
    
    // build pathname $HOME/.diary
    if (home_env == NULL) {
        home_env = ".";
    }
    int diary_pathname_len = strlen(home_env) + strlen("/.diary") + 1;
    char *diary_pathname = malloc(diary_pathname_len);
    snprintf(diary_pathname, diary_pathname_len, "%s/%s", home_env, ".diary");

    // open file
    FILE *diary_file = fopen(diary_pathname, "r");
    if (diary_file == NULL) {
        perror("Can not open diary file\n");
        return 1;
    }

    // for every character in file, print to stdout 
    int c;
    while ((c = fgetc(diary_file)) != EOF) {
        fputc(c, stdout);
    }

    fclose(diary_file);
    
    return 0;
}
