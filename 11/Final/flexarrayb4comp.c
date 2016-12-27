#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

struct flexarrayrec {
    int capacity;
    int itemcount;
    int *items;
};

typedef struct flexarrayrec Flexarray;

void *erealloc(void *result, size_t s) {
    result = realloc(result, s);
    if (NULL == result) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}
flexarray flexarray_new() {
    flexarray result = erealloc(NULL, sizeof *result);
    result->capacity = 2;
    result->itemcount = 0;
    result->items = erealloc(NULL, result->capacity * sizeof result->items[0]);
    return result;
}
void flexarray_append(flexarray f, int num) {
    if (f->itemcount == f->capacity) {
        /* do the old "double the capacity" trick */
        f->capacity += f->capacity;
        f->items = erealloc(f->items, f->capacity * sizeof f->items[0]);
    }
    /* insert the item in the last free space */
    f->items[f->itemcount++] = num;
}



void flexarray_print(flexarray f) {
    /* a for loop to print out each cell of f->items */
    int i;
    for (i = 0; i<f->itemcount; i++) {
        printf("%d\n", f->items[i]);
    }
}

void flexarray_sort(Flexarray *a, int n) /*(int *a,int i)*/
{
    int i, j, p, t;
    int n = a->itemcount;
    /*int *a = f->items; //this is allowed and is infact quicker*/
    int a = a->items;
    if (n < 2)
        return;
    p =a[n / 2];
    for (i = 0, j = n - 1;; i++, j--) {
        while (a[i] < p)
            i++;
        while (p < a[j])
            j--;
        if (i >= j)
            break;
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    /*flexarray_sort(a, i);*/
    /*flexarray_sort(a + i, n - i);*/
}

void flexarray_free(flexarray f) {
    /* free the memory associated with the flexarray */
    free(f->items);
    free(f);

}
