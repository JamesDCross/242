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

void print_array(int *a, int n) {
    if (n > 0) {
        printf("%d\n", a[0]);
        print_array(a + 1, n - 1);
    }
}

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


int main(void)
{
    int my_array[ARRAY_MAX];
    int count = 0;
    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count]))
        {
            count++;
        }
    insertion_sort(my_array, count);
    
    print_array(my_array, count);
    return EXIT_SUCCESS;
}
