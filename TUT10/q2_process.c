/*
This program prints the following information:
    The current date.
    The current time.
    The current user.
    The current hostname.
    The current working directory.

Example:
    ./now
    29-02-2022
    03:59:60
    cs1521
    zappa.orchestra.cse.unsw.EDU.AU
    /home/cs1521/lab08

Useful commands:
    date +%d-%m-%Y
    date +%T
    whoami
    hostname -f
    realpath .
*/

#include <spawn.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

// extern - variable is defined elsewhere, in this case, environ is defined
// by the system environment
extern char **environ;

// creates a process, runs the command given (pass command via arguments), 
// wait for the process to finish executing
void spawn_process_and_wait(char **argv) {
}

int main(int argc, char *argv[]) {
    /*
    we call spawn_process_and_wait for each command:
    date +%d-%m-%Y
    date +%T
    whoami
    hostname -f
    realpath .
    */

    // we create a process that runs command "date +%d-%m-%Y"
    // we create a process that runs command "date +%T"
    // ... 
    return 0;
}