#include <stdio.h> /* for fprintf */
#include <stdlib.h> /* for size_t, malloc, realloc, exit */
#include "mylib.h" /*links this to mylib h*/


/*methods for interface*/
void* erealloc(void *a, size_t n) {
    
    a = realloc(a, n);
    if (NULL == a) {
        fprintf(stderr, "memory reallocation failed.\n");
        exit(EXIT_FAILURE);
    }
    /*note becuase this is a void* function it must
      return the pointer, it is of type void pointer*/
    /*also the syntax of void* is the same as void *erealloc*/
    return a;
}

void* emalloc(size_t n) {

    void *r = malloc(n);
    if (NULL == r) {
        fprintf(stderr, "memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    return r;
}
