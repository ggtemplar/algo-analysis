#include "sort_header.h"

int partition ( int arr [ ], int low, int high )
{
    int pivot = arr [ high ];
    int pidx = low - 1;

    for ( int i = low; i < high; ++ i )
    {
        if ( arr [ i ] <= pivot )
        {
            ++ pidx;
            swap_by_ref ( &arr [ pidx ], &arr [ i ] );
        }
    }

    swap_by_ref ( &arr [ ++ pidx ], &arr [ high ] );

    return pidx;
}


void q_sort ( int arr [ ], int low, int high)
{
    if ( low >= high ) return;

    int pidx = partition ( arr, low, high );

    q_sort ( arr, low, pidx - 1 );
    q_sort ( arr, pidx + 1, high );
}

void quick_sort ( int arr [ ], int len )
{
    q_sort ( arr, 0, len - 1 );
}
