#include "sort_header.h"

void insertion_sort ( int arr [ ], int n )
{
    int j, key;

    for ( unsigned int i = 1; i < n; ++ i )
    {
        key = arr [ i ];
        j = i - 1;

        while ( j > -1 && arr [ j ] > key )
        {
            arr [ j + 1 ] = arr [ j ];
            j --;
        }

        arr [ j + 1 ] = key;
    }
}