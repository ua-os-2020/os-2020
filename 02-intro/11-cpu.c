/*
 *  11-cpu.c: used to show CPU virtualization
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
    char *str;
    int i, pid;

    if (argc != 2)
    {
        fprintf(stderr, "usage: cpu <string>\n");
        return EXIT_FAILURE;
    }

    pid = getpid();

    str = argv[1];

    for( i = 0; i < 10; ++i )
    {
        printf("(%d) -> %s\n", pid, str);
        spin_time(1);
    }
    fprintf( stderr, "(%d): Ends\n", pid );
    return EXIT_SUCCESS;
}
