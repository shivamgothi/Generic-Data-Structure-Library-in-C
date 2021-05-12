#ifndef __SP_PRIORITY_QUEUE__H
#define __SP_PRIORITY_QUEUE__H 123
#include<sp_common.h>
#include<sp_heap.h>
typedef struct __$_sp_priority_queue
{
Heap *heap;
int (*predicate)(void*,void*);
}PriorityQueue;
PriorityQueue* createPriorityQueue(int (*predicate)(void*,void*),bool *success);
void destroyPriorityQueue(PriorityQueue *priorityQueue);
void* removeFromPriorityQueue(PriorityQueue *priorityQueue, bool *success);
void addInPriorityQueue(PriorityQueue *priorityQueue,void *ptr,bool *success);
int getSizeOfPriorityQueue(PriorityQueue *priorityQueue);
void getElementAtFrontOfPriorityQueue(PriorityQueue *priorityQueue,bool *success);
int isPriorityQueueEmpty(PriorityQueue *priorityQueue);
void* getElementFromPriorityQueue(PriorityQueue *priorityQueue,int index,bool *success);
void updateElementOfPriorityQueue(PriorityQueue *priorityQueue,int index,void *ptr,bool *success);
#endif