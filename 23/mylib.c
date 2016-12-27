#include <stdlib.h>
#include <stdio.h>
#include "mylib.h"
#include <assert.h>
#include <ctype.h>

void* emalloc (size_t s){
   void* f = malloc(s);
   if (f==NULL){
      fprintf(stderr,"mem alloc fail!\n");
      exit(EXIT_FAILURE);
   }
   return f;
}




