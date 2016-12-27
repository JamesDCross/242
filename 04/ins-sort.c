#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 30000 /*1000*/ /*100*/ /*10*/

/**
 * Lab 04
 *
 * Implementation of insertion sort algorithm.
 * 
 *
 * @author James Cross
 *
 */

void insertion_sort(int* a, int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
        {
            temp = a[i];
            j = i - 1;
            while ((temp < a[j]) && (j >= 0))
                {
                    a[j + 1] = a[j];
                    j = j - 1;
                }
            a[j + 1] = temp;
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
    insertion_sort(my_array, count);
    end = clock();
    for (i = 0; i < count; i++) {
        printf("%d\n", my_array[i]);
    }
    fprintf(stderr, "%d %f\n", count, (end - start) / (double)CLOCKS_PER_SEC);
    return EXIT_SUCCESS;
}
