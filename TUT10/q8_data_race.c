#include <stdio.h>
#include <pthread.h>

int global_total = 0;

void *add_5000_to_counter(void *data) {
    for (int i = 0; i < 5000; i++) {
        // sleep for 1 nanosecond
        nanosleep (&(struct timespec){.tv_nsec = 1}, NULL);
        
        // increment the global total by 1
        /* 
        1. loading global total into a register
        2. adding 1 to this register
        3. storing register value back to global total
        
        global total: 1
        thread 1, step 1: loading global total into a register (1)
        thread 2, step 1-3: adds 1 to global total (2)
        thread 1, step 2: add 1 to 1 = 2
        thread 1, step 3: stores 2 back to global total 
        */
        global_total++;
    }

    return NULL;
}

int main(void) {
    pthread_t thread1;
    pthread_create(&thread1, NULL, add_5000_to_counter, NULL);

    pthread_t thread2;
    pthread_create(&thread2, NULL, add_5000_to_counter, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // if program works correctly, should print 10000
    printf("Final total: %d\n", global_total);
}
