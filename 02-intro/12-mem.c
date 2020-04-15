/*
 *  11-mem.c: used to show memory virtualization
 *
 *  Un.Austral - Sistemas Operativos - 2020
 *  EAMartinez
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "common.h"

int
main(int argc, char *argv[])
{
    int c, pid;

    pid = getpid();

    printf( "(%d) main address = %p\n", pid, main );
    printf( "(%d) c address = %p\n", pid, &c );
    printf( "(%d) pid address = %p\n", pid, &pid );

    for( c = 1; c < 10; ++c )
    {
        printf("(%d) value of c: %d\n", pid, c );
        spin_time(2);
    }
    printf( "(%d) ends\n", pid );

    return EXIT_SUCCESS;
}
