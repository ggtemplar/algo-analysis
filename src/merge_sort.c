#include "sort_header.h"

void merge ( int arr [ ], int low, int mid, int high )
{
    unsigned int i, j, k;

    int lsize = mid - low + 1;
    int rsize = high - mid;

    int *larr = ( int * ) malloc ( sizeof ( int ) * lsize );
    for ( i = 0; i < lsize; ++ i )
        larr [ i ] = arr [ low + i ];

    int *rarr = ( int * ) malloc ( sizeof ( int ) * rsize );
    for ( j = 0; j < rsize; ++ j )
        rarr [ j ] = arr [ mid + j + 1 ];

    i = 0;
    j = 0;
    k = low;

    while ( i < lsize && j < rsize )
        arr [ k++ ] = ( larr [ i ] <= rarr [ j ] ) ? larr [ i ++ ] : rarr [ j ++ ];

    while ( i < lsize )
        arr [ k ++ ] = larr [ i ++ ];

    while ( j < rsize )
        arr [ k ++ ] = rarr [ j ++ ];
}


void m_sort ( int arr [ ], int low, int high )
{
    if ( low >= high ) return;

    int mid = low + ( high - low ) / 2;

    m_sort ( arr, low, mid );
    m_sort ( arr, mid + 1, high );

    merge ( arr, low, mid, high );
}


void merge_sort ( int arr [], int len )
{
    m_sort ( arr, 0, len - 1 );
}