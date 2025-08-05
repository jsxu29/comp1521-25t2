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
    pid_t pid;
    int status = posix_spawn(&pid, argv[0], NULL, NULL, argv, environ);
    if (status != 0) {
        perror("error in posix_spawn");
        exit(1);
    }

    int spawn_exit_status;
    if (waitpid(pid, &spawn_exit_status, 0) == -1) {
        perror("wait_pid error\n");
        exit(1);
    }
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
    char *date_argv[] = {"/bin/date", "+%d-%m-%Y", NULL};
    spawn_process_and_wait(date_argv);

    char *time_argv[] = {"/bin/date", "+%T", NULL};
    spawn_process_and_wait(time_argv);

    char *user_argv[] = {"/usr/bin/whoami", NULL};
    spawn_process_and_wait(user_argv);

    char *hostname_argv[] = {"/bin/hostname", "-f", NULL};
    spawn_process_and_wait(hostname_argv);

    char *working_directory_argv[] = {"/bin/realpath", ".", NULL};
    spawn_process_and_wait(working_directory_argv);

    return 0;
}