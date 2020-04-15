/*
 *  common.c
 *      common routines for basic Unix/linux program examples
 *
 *  Un.Austral - Sistemas Operativos - 2020
 *  EAMartinez
 */

#include <assert.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <stdlib.h>

#include "common.h"

static double
get_time()
{
    struct timeval t;

    assert( gettimeofday(&t, NULL) == 0);

    return (double)t.tv_sec + (double)t.tv_usec / 1e6;
}

/*
 *  spin_time:
 *      waits 'howlong' seconds without busy waiting
 *      Uses main date system timer
 */

void
spin_time(int howlong)
{
    double t;

    t = get_time();
    while ((get_time() - t) < (double)howlong)
        ; // do nothing in loop
}

