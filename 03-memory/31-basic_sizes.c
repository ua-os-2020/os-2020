/*
 *  31-basic_sizes.c
 *      Show C basic sizes
 *
 *  Un.Austral - Sistemas Operativos 2020
 *  EAMartinez
 */

#include <stdio.h>

/*
 *  Macro to print 'size' and 'type'
 *      To see macro expansion, please in shell type
 *          $ cpp 31-basic_sizes.c
 *      cpp is the command name of "C PreProcessor"
 */

#define show_size(type) printf("%2lu:\t%s\n", sizeof(type), #type)

int
main( void )
{
    printf( "---C basic sizes:\n" );

    show_size(char);
    show_size(short);
    show_size(int);
    show_size(long);
    show_size(long long);
    show_size(void *);
    show_size(float);
    show_size(double);
    show_size(long double);

    return 0;
}

