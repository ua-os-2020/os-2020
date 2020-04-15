/*
 *  04-fork-wait.c: creating a new process with fork - waiting termination
 *
 *  Un.Austral - Sistemas Operativos - 2020
 *  EAMartinez
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define DEF_WAIT    5

int
main(int argc, char *argv[])
{
    int rc, wc;
    int ppid, chpid;
    int sec_wait;

    sec_wait = argc == 1 ? DEF_WAIT: atoi(argv[1]);

    ppid = getpid();

    printf("(pid:%d) *** hello world\n", ppid);

    if( ( rc = fork() ) < 0 )
    {
        // fork failed; exit
        fprintf(stderr, "(pid:%d) *** fork failed\n", ppid);
        return EXIT_FAILURE;
    }
    else if( rc == 0 ) // child (new process)
    {
        chpid = getpid();

        printf("(pid:%d) --- hello, I am child\n", chpid);
        printf("(pid:%d) --- child waiting %d seconds....\n", chpid, sec_wait);
        sleep(sec_wait);
        printf("(pid:%d) --- child terminates\n", chpid );
    }
    else                // parent
    {
        printf("(pid:%d) *** parent waiting for child to terminate....\n", ppid);
        wc = wait(NULL);
        printf("(pid:%d) *** I am parent of (pid:%d) who terminates\n", ppid, wc );
    }
    return EXIT_SUCCESS;
}
