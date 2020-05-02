/*
 *  34-locality.c
 *      Determines where in memory are variables
 *      Must be called pmap when program is in sleep
 *      Must be executed without ASLR
 *
 *  Un.Austral - Sistemas Operativos 2020
 *  EAMartinez
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int global_nin;
int global_in = 10;
const int global_kte = 30;

int
main( int argc, char *argv[] )
{
    int pid;
    int count = 20;
    static int gnin;
    static int gin = 10;
    static const int g_kte = 30;

    pid = getpid();

    printf( "(pid=%d) -> Automatic: &argv = %p, &argc = %p, &pid = %p, &count = %p\n", pid, &argv, &argc, &pid, &count);
    printf( "(pid=%d) -> Globals not init: &global_nin = %p, &gnin = %p\n", pid, &global_nin, &gnin );
    printf( "(pid=%d) -> Globals initted : &global_in = %p, &gin = %p\n", pid, &global_in, &gin );
    printf( "(pid=%d) -> Globals constants : &global_kte = %p, &g_kte = %p\n", pid, &global_kte, &g_kte );


    sleep( argc > 1 ? atoi(argv[1]): 2 );

    return 0;
}

