#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "queue.h"

/*lab book, mycodeschool https://www.youtube.com/watch?v=okr-XE8yTO8*/
/*stack overflow http://stackoverflow.com/questions/20619234/circular-queue-implementation*/


struct queue {
	/*array ptr*/
   double *items;
   /*size of the array*/
   int capacity;
   /*head is where deletion is preformed*/
   /*insertion is performed at the tail*/
   int head;
   /*the number of items in the queue(not the array)*/
   int num_items;
};

/*an aside:
java create object-
queue q = new queue; set a variable of type queue to a newly initialized queue
this must do what the method below does except it fills the parameters of the queue
object with zero's.an then you change them later.
*/


/*may just set a default size*/
queue queue_new(int s){
/*like saying queue q = new queue*/
queue newq = emalloc(sizeof * newq);
newq->capacity = s;
newq->head = 0;
newq->num_items = 0;
newq->items = emalloc( s * sizeof newq->items[0]);


return newq;
}

void enqueue(queue q, double item) {
	/*check not exceeding capacity*/
   if (q->num_items < q->capacity) {
	   /*head + num items = tail % capacity for wrap around*/
      q->items[(q->head + q->num_items) % q->capacity] = item;
	  /*up number of items*/
      q->num_items++;
   }
}

double dequeue(queue q){

if(q->num_items > 0){
	double to_delete = q->items[q->head];
	q->head--;
	q->num_items++;
	return to_delete;
}
}

void queue_print(queue q){
	/*take a copy of q head and change that*/
	int i = q->head;
	for(i ;i < q->head + q->num_items; (i++)%q->capacity){
	printf("%2.2f\n",q->items[i]);

	}
}

int queue_size(queue q) {
   return q->num_items;
}
queue queue_free(queue q) {
   free(q->items);
   free(q);
   return q;
}


