/*
 *  common.h
 *      common routines for basic Unix/linux program examples
 *
 *  Un.Austral - Sistemas Operativos - 2020
 *  EAMartinez
 */


/*
 *  spin_time:
 *      waits 'howlong' seconds without busy waiting
 *      Uses main date system timer
 */

void spin_time(int howlong);

