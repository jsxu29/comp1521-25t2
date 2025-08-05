// Write a C program that creates a thread that infinitely prints some message provided by main
// (eg. "Hello\n"), while the main (default) thread infinitely prints a different message
// (eg. "there!\n").

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// function that calls hello!\n indefinitely
void *func(void *arg) {
    while (1) {
        printf("Hello!\n");
    }
    return NULL;
}

int main() {
    // create a thread - calls hello!
    pthread_t thread_id;
    int status = pthread_create(&thread_id, NULL, &func, NULL);
    if (status != 0) {
        perror("error in pthread_create");
        exit(1);
    }

    // call there!\n indefinitely
    while (1) {
        printf("there!\n");
    }
    return 0;
}