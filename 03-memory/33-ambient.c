/*
 *  33-ambient.c
 *      Shows inherited  process ambient
 *
 *      Program produces same listing as $ env
 */

#include <stdio.h>
#include <stdlib.h>

int 
main(int argc, char *argv[], char *envp[])
{
    int i;

    for( i = 0; envp[i] != NULL; ++i )
        printf("%s\n", envp[i]);
    return EXIT_SUCCESS;
}



