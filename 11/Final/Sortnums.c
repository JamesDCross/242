#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

int main(void) {

    int i;
    flexarray f = flexarray_new();

    while (1 == scanf("%d", &i)) {
        flexarray_append(f, i);
    }

    flexarray_sort(f);
    flexarray_print(f);
    flexarray_free(f);

    return EXIT_SUCCESS;
}
