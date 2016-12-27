#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "queue.h"

struct queue {
	double *items;
	int capacity;
	int head;
	int numitems;
};

queue queue_new() {
   int d = 7;
   queue q = emalloc(sizeof *q);
   q->items = calloc(d,sizeof(double)); 
   q->capacity = d;
   q->head = 0;
   q->numitems = 0;
   
   return q;
   
}

void enqueue(queue q, double item) {
   if (q->numitems < q->capacity) {
      q->items[(q->head + q->numitems++) % q->capacity] = item;
   }
}
/*could be a problem with this*/
double dequeue(queue q) {
    if(q->numitems > 0){
        int i = q->head;
        q->numitems--;
        q->head++;
        q->head%=q->capacity;
        return q->items[i];
    }
    return 0;
}






/*not tested*/
void queue_print(queue q) {
/* print queue contents one per line to 2 decimal places */
    int i = 0;
    while(i != q->numi){
        printf("%.2f\n", q->items[(q->head+i) % q->capacity]);
        i++;
    }

}

void queue_print_info(queue q) {
   int i;
   printf("capacity %d, num_items %d, head %d\n[", q->capacity,
         q->numi, q->head);
   for (i = 0; i < q->capacity; i++) {
      printf("%s%.2f", i == 0 ? "" : ", ", q->items[i]);
   }
   printf("]\n");
}

int queue_size(queue q) {
	return q->numi;
}

queue queue_free(queue q) {
	free(q->items);
	free(q);
	return q;
}
