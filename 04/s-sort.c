#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_MAX 30000 /*1000*/ /*100*/ /*10*/

/**
 * Lab 04
 *
 * Implementation of selection sort algorithm.
 * 
 *
 * @author James Cross
 *
 */



void selection_sort(int* a, int n)
{
    int c, d, position, swap;
    for (c = 0; c < (n - 1); c++)
        {
            position = c;

            for (d = c + 1; d < n; d++)
                {
                    if (a[position] > a[d])
                        position = d;
                }
            if (position != c)
                {
                    swap = a[c];
                    a[c] = a[position];
                    a[position] = swap;
                }
        }
}

int main(void) {
    int my_array[ARRAY_MAX];
    clock_t start, end;
    int i, count = 0;
    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])) {
        count++;
    }
    start = clock();
    selection_sort(my_array, count);
    end = clock();
    for (i = 0; i < count; i++) {
        printf("%d\n", my_array[i]);
    }
    fprintf(stderr, "%d %f\n", count, (end - start) / (double)CLOCKS_PER_SEC);
    return EXIT_SUCCESS;
}
