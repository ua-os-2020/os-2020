/*
 *  14-race2: used to show concurrency problem (2nd. example)
 *      two threads incrementing the same counter
 *
 *  Un.Austral - Sistemas Operativos - 2020
 *  EAMartinez
 */

#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "common_threads.h"

volatile int counter = 0;
int loops;

void *
worker(void *arg)
{
    int i;

    for (i = 0; i < loops; i++)
        counter++;

    return NULL;
}

int
main(int argc, char *argv[])
{
    pthread_t p1, p2;

    if (argc != 2)
    {
        fprintf(stderr, "usage: threads <loops>\n");
        exit(1);
    }

    loops = atoi(argv[1]);
    printf("Initial value : %d\n", counter);

    Pthread_create(&p1, NULL, worker, NULL);
    Pthread_create(&p2, NULL, worker, NULL);
    Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);

    printf("Final value   : %d\n", counter);

    return 0;
}
