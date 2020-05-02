/*
 *  32-all_sizes.c
 *      Show (almost) all C sizes
 *
 *      It is nteresting to see what is the alignment that compilers
 *      do with structures, in order to get simplicity and
 *      time efficiency of processor
 *
 *      This example is partially taken from
 *
 *      https://www.geeksforgeeks.org/is-sizeof-for-a-struct-equal-to-the-sum-of-sizeof-of-each-member/
 *
 *      Sometimes, this optimization is contrary to what the programmer 
 *      want to do and then, it comes into help some special instructions to
 *      the compiler to take other ways; this the case of '__attribute__'
 *      a is exemplified in 'st4_t' declaration.
 */

#include <stdio.h>

#define show_size(type) printf("%2lu:\t%s\n", sizeof(type), #type)

/*
 *  structs
 */

typedef struct
{
    int x;                  // 4
    double z;               // 8
    short y;                // 2
} st1_t;

typedef struct
{
    double z;               // 8
    int x;                  // 4
    short y;                // 2
} st2_t;


typedef struct
{
    double z;               // 8
    short y;                // 2
    int x;                  // 4
} st3_t;

typedef struct
{
    char c;                 // 1
    short y;                // 2
    int x;                  // 4
} __attribute__((packed)) st4_t;

/*
 *  unions
 */

typedef union
{
    int x;                  // 4
    double z;               // 8
    short y;                // 2
} un1_t;

typedef union
{
    double z;               // 8
    int x;                  // 4
    short y;                // 2
} un2_t;


typedef union
{
    double z;               // 8
    short y;                // 2
    int x;                  // 4
} un3_t;


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
    printf( "---C structure sizes:\n" );
    show_size(st1_t);
    show_size(st2_t);
    show_size(st3_t);
    show_size(st4_t);
    printf( "---C union sizes:\n" );
    show_size(un1_t);
    show_size(un2_t);
    show_size(un3_t);
    return 0;
}

