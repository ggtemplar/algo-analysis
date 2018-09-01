#include "bubble_sort.c"
#include "selection_sort.c"
#include "insertion_sort.c"
#include "count_sort.c"
#include "merge_sort.c"
#include "quick_sort.c"


int main ( void )
{
    int t = 0;
    FILE *fptr;

    while ( t < 3 )
    {
        char fname [ 128 ];

        switch ( t )
        {
            case AVG:   sprintf ( fname, "results_random.csv"   );
                        break;

            case BEST:  sprintf ( fname, "results_ascending.csv"  );
                        break;

            case WORST: sprintf ( fname, "results_descending.csv" );
                        break;
        }


        fptr = fopen ( fname, "w" );
        fprintf ( fptr, "iterations, bubble sort, selection sort, insertion sort, count sort, merge sort, quick sort\n" );

        for ( unsigned int n = 5000, i = 0; n <= 60000; n += 5000, i++ )
        {
            fprintf ( fptr, "%d,", n );

            time_sort ( bubble_sort,    n, t, fptr );
            time_sort ( selection_sort, n, t, fptr );
            time_sort ( insertion_sort, n, t, fptr );
            time_sort ( count_sort,     n, t, fptr );
            time_sort ( merge_sort,     n, t, fptr );
            time_sort ( quick_sort,     n, t, fptr );

            fprintf ( fptr,"\n" );
        }

        fclose ( fptr );
        t ++;
    }

    return 0;
}
