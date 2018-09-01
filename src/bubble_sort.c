#include "sort_header.h"

void bubble_sort ( int arr [ ], int n)
{
    for ( unsigned int i = 0 ; i < n; ++ i )
        for ( unsigned int j = 0; j < n - 1 - i; ++ j )
            if ( arr [ j ] > arr [ j + 1 ] )
                swap_by_ref ( &arr [ j ], &arr [ j + 1 ] );
}