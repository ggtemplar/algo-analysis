#ifndef _SORT_HEADER_H_
#define _SORT_HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float progress = 0.0;

typedef enum _type_
{
    AVG,
    BEST,
    WORST
} type;


void swap_by_ref ( int *a, int *b )
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


int find_max ( int arr [ ], int len )
{
    int max = 0;

    for ( unsigned int i = 0; i < len; ++ i )
        if ( arr [ i ] > max )
            max = arr [ i ];

    return max;
}


void print_arr ( int arr [ ], int len )
{
    printf ( "Array:\n" );

    for ( unsigned int i = 0; i < 40; ++ i )
    {
        if ( i % 10 == 0 )
            printf ( "\n" );

        printf ( "%5d  ", arr[i] );
    }

    printf ( "\n" );
}

void time_sort ( void ( *func ) ( int *, int ), int n ,type t, FILE *fptr )
{
    int  size_int = sizeof ( int );
    int *arr      = ( int * ) malloc ( size_int * n );

    for ( unsigned int i = 0; i < n; ++ i )
    {
        if      ( t == AVG   ) arr [ i ] = rand ( ) % n;
        else if ( t == BEST  ) arr [ i ] = i;
        else if ( t == WORST ) arr [ i ] = n - i;
    }

    clock_t start = clock ( );
    func ( arr, n );
    clock_t stop  = clock ( );

    fprintf ( fptr, "%f,", 1.0 * ( stop - start ) / CLOCKS_PER_SEC );
    printf  ( "Progress: %.2f\%\n", ++ progress * 100 / 216 );
}

#endif