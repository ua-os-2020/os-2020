/*
 *  01-hello.c: a simple program 
 *
 *  Un.Austral - Sistemas Operativos - 2020
 *  EAMartinez
 */

/*
 *  IMPORTANT: don't try to execute in your normal Unix/Linux account
 *      Minimum first limit user limit process to another valu with
 *          $ ulimit -u 200
 *      Another solution is to execute ina virtaul machine
 *
 *      NEVER NEVER NEVER execute it as root
 */

#include <stdlib.h>
#include <unistd.h>

#define forever() for(;;)

int
main( void )
{
    forever()
        fork();
    return EXIT_FAILURE;
}
