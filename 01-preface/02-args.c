/*
 *  02-args.c: code for a simple process
 *
 *  Un.Austral - Sistemas Operativos - 2020
 *  EAM
 */

#include <stdio.h>
#include <stdlib.h>


int
main( int argc, char *argv[] )
{
    int i;

    printf( "Program invocation - arg_qty: \"%d\"\tname: \"%s\"\n", argc, *argv );
    printf( "Arguments:\n" );
    for( i = 0; i < argc; ++i )
        printf( "[%d]->%s\t", i, argv[i] );
    putchar('\n');
    
    return EXIT_SUCCESS;
}


