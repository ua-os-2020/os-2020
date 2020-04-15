/*
 *  13-race.c: shows two process in race condition
 *      Trying to write to same resource (stdout)
 *
 *  Un.Austral - Sistemas Operativos - 2020
 *  EAMartinez
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

#define PARENT_STRING   "Very long output from parent\n"
#define CHILD_STRING    "Very long ouptut from child\n"

static void
post(char *str)
{
    while( *str != '\0' )
        putc( *str++, stdout );
}

int
main(int argc, char *argv[])
{
    pid_t pid;
    int in_race;

    in_race = argc > 1;
    printf( in_race ? "In race\n" : "No race\n" );

    if( in_race )
        setvbuf(stdout,NULL,_IONBF,0);

    pid = fork();
    assert(pid >= 0);

    post( pid == 0 ? CHILD_STRING: PARENT_STRING );

    return EXIT_SUCCESS;
}
