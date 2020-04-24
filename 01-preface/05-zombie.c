/*
 *  05-zombie.c:  shows how to make a zombie process
 *
 *  Un.Austral Sistemas Operativos 2020
 *  EAMartinez
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define SLEEP_DEF   2

int
main( int argc, char *argv[])
{
    unsigned seconds;
    int ppid, chpid;

    ppid = getpid();
    seconds = argc == 1 ? SLEEP_DEF: atoi( argv[1] );

    if ( ( chpid = fork() ) > 0 )    //  Parent
    {
        int wpid;

        printf( "(pid:%d) child created from me (pid:%d)\n", ppid, chpid );
        printf( "(pid:%d) going to sleep for %u seconds\n", ppid, seconds );
        sleep(seconds);
        printf( "(pid:%d) waiting for a child... \n", ppid );
        wpid = wait(NULL);
        printf( "(pid:%d) child (pid:%d) terminates\n", ppid, wpid );
        printf( "(pid:%d) terminate\n", ppid );
    }
    return EXIT_SUCCESS;
}
