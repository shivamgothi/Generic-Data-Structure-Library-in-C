#ifndef __SP_PRIORITY_QUEUE__C
#define __SP_PRIORITY_QUEUE__C 123
#include<sp_priority_queue.h>
#include<sp_heap.h>
#include<stdlib.h>
#include<stdio.h>
PriorityQueue* createPriorityQueue(int (*predicate)(void*,void*),bool *success)
{
int succ;
PriorityQueue *priorityQueue;
if(success) *success=false;
priorityQueue=(PriorityQueue*)malloc(sizeof(PriorityQueue));
if(priorityQueue==NULL || predicate==NULL) return NULL;
priorityQueue->predicate=predicate;
priorityQueue->heap=createHeap(predicate,&succ);
if(!succ) 
{
free(priorityQueue);
return NULL;
}
if(success) *success=true;
return priorityQueue;
}
void addInPriorityQueue(PriorityQueue *priorityQueue,void *ptr,bool *success)
{
int succ;
if(success) *success=false;
if(priorityQueue==NULL) return;
if(priorityQueue->heap==NULL) return;
addInHeap(priorityQueue->heap,ptr,&succ);
if(!succ) return;
if(success) *success=true;
}
void* removeFromPriorityQueue(PriorityQueue *priorityQueue,bool *success)
{
int succ;
void *ptr;
if(success) *success=false;
if(isPriorityQueueEmpty(priorityQueue)) return NULL;
ptr=removeFromHeap(priorityQueue->heap,&succ);
if(!succ) return NULL;
if(success) *success=true;
return ptr;
}
void* elementAtFrontOfPriorityQueue(PriorityQueue *priorityQueue, bool *success)
{
void *ptr;
if(success) *success=false;
if(isPriorityQueueEmpty(priorityQueue)) return NULL;
ptr=getTopElementFromHeap(priorityQueue->heap);
if(success) *success=true;
return ptr;
}
int getSizeOfPriorityQueue(PriorityQueue *priorityQueue)
{
if(isPriorityQueueEmpty(priorityQueue)) return 0;
return getSizeOfHeap(priorityQueue->heap);
}
bool isPriorityQueueEmpty(PriorityQueue *priorityQueue)
{
if(priorityQueue==NULL) return true;
if(priorityQueue->heap==NULL) return true;
if(getSizeOfHeap(priorityQueue->heap)==0) return true;
return false;
}
void destroyPriorityQueue(PriorityQueue *priorityQueue)
{
if(priorityQueue==NULL) return ;
destroyHeap(priorityQueue->heap);
free(priorityQueue);
}
void* getElementFromPriorityQueue(PriorityQueue *priorityQueue,int index,bool *success)
{
void *ptr=NULL;
if(success) *success=false;
if(priorityQueue==NULL) return ptr;
if(priorityQueue->heap==NULL) return ptr;
ptr=getElementFromHeap(priorityQueue->heap,index,success);
return ptr;
}
void updateElementOfPriorityQueue(PriorityQueue *priorityQueue,int index,void *ptr,bool *success)
{

if(success) *success=false;
if(priorityQueue==NULL) return;
if(priorityQueue->heap==NULL) return;
updateElementOfHeap(priorityQueue->heap,index,ptr,success);
}
#endif