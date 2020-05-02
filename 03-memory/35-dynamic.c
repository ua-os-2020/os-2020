/*
 *  38-dynamic.c
 *      Shows how works malloc, realloc and free
 *      Experience with valgrind
 *
 *      
 *
 *  Un.Austral - Sistemas operativos 2020
 *  EAMartinez
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define INIT_SIZE   20LU
#define NEW_SIZE1   30LU
#define NEW_SIZE2   (1024LU*1024)

#define STRING      "Hello World"

int
main( int argc, char **argv )
{
    char *pinit, *pnew;
    size_t size;

    size = argc > 1 ? NEW_SIZE2: NEW_SIZE1;             //  Second size depends in the existence of an argument
    printf( "Size of buffers -> 1st: %lu, 2nd: %lu\n", INIT_SIZE, size );
    

    pinit = malloc(INIT_SIZE);                          //  Take dynamic memory with first size
    assert( pinit != NULL );

    strncpy( pinit, STRING, strlen(STRING) );           //  Copy string to dynamic memory

    printf( "Content of buffer = %s\n", pinit );

    pnew = realloc( pinit, size );                      //  Extend dynamic memory for greater size
    assert( pnew != NULL );

    printf( "pinit = %p, pnew = %p\n", pinit, pnew );   //  Show both pointers, old and new
    printf( "Pointers pinit and pnew are %s\n", pinit == pnew ? "same": "different" );      //  Same ?

    printf( "Content of buffer = %s\n", pnew );         //  Show that contents remain the same in any case

    free( pnew );                                       //  Now free dynamic memory
    printf( "pnew ok freed done\n" );

    free( pinit );                                      //  Bad free ! This pointer points to invalid memory (was freed)
    printf( "pinit bad freed done\n" );

    printf( "Content of buffer = %s\n", pnew );         //  print contents of a buffer that doesn't belog any more to process

    return 0;
}
    

