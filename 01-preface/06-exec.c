/*
 *  06-exec.c
 *  Implements a shell for one command, using exec system call
 *
 *  Un.Austral - Sistemas Operativos - 2020
 *  EAM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

static int
do_process( char *const argv[] )
{
    int pid;

    if( ( pid = fork() ) < 0 )
    {
        fprintf(stderr, "Can't fork\n");
        return EXIT_FAILURE;
    }

    if( pid == 0 )      //  Child
    {
        execvp( *argv, argv);
        fprintf(stderr, "No cmd \"%s\"\n", *argv );
        return EXIT_FAILURE;
    } else              
    {                   //  Parent
        wait(NULL);
        return EXIT_SUCCESS;
    }
}


int
main( int argc, char **argv )
{
    if( argc == 1 )
    {
        fprintf( stderr, "%s: no arguments\n", *argv );
        return EXIT_FAILURE;
    }

    return do_process( argv+1 );
}

