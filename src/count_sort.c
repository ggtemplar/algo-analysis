#include "sort_header.h"

void c_sort ( int iarr [ ], int oarr [ ], int len, int range )
{
	int *aux = (int *) calloc ( range + 1, sizeof ( int ) );

	for ( unsigned int i = 0; i < len; ++ i )
		aux [ iarr [ i ] ] += 1;

	for ( unsigned int i = 1; i < range + 1; ++ i )
		aux [ i ] += aux [ i - 1 ];

	for ( unsigned int i = len - 1; i > -1; -- i )
	{
		 oarr [ aux [ iarr [ i ] ] - 1 ] = iarr [ i ];
		 aux [ iarr [ i ] ] = aux [ iarr [ i ] ] - 1;
	}
}


void count_sort ( int arr [ ], int len )
{
    int *oarr = ( int * ) malloc ( sizeof ( int ) * len );
    int k = find_max ( arr, len );
    c_sort ( arr, oarr, len, k );
}