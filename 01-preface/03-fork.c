/*
 *  03-fork.c: creating a new process through fork
 *
 *  Un.Austral - Sistemas Operativos - 2020
 *  EAMartinez
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    int rc;

    printf("hello world (pid:%d)\n", (int)getpid());
    if( ( rc = fork() ) < 0)
    {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        return 1;
    }
    else if( rc == 0 )      // child (new process)
        printf("hello, I am child (pid:%d)\n", (int)getpid());
    else                    // parent goes down this path (main)
        printf("hello, I am parent of %d (pid:%d)\n", rc, (int)getpid());

    return 0;
}
