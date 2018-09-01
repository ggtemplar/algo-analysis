#include "sort_header.h"

void selection_sort ( int arr[], int n )
{
    unsigned int key;

    for ( unsigned int i = 0; i < n; ++ i)
    {
        key = i;

        for ( unsigned int j = i + 1; j < n; ++ j )
            if ( arr [ j ] < arr [ key ] )
                key = j;

        swap_by_ref ( &arr [ i ], &arr [ key ] );
    }
}