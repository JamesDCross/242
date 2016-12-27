#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "queue.h"

struct queue {
   double *items;
   int capacity;
   int head;
   int num_items;
};