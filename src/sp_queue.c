#ifndef __SP_QUEUE__C
#define __SP_QUEUE__C 123
#include<sp_queue.h>
#include<sp_sll.h>
#include<stdlib.h>
#include<stdio.h>
Queue* createQueue(bool *success)
{
Queue *queue;
SinglyLinkedList *singlyLinkedList;
if(success) *success=false;
singlyLinkedList=createSinglyLinkedList(success);
if(singlyLinkedList==NULL) return NULL;
queue=(Queue*)malloc(sizeof(Queue));
if(queue==NULL)
{
destroySinglyLinkedList(singlyLinkedList);
if(success) *success=false;
return NULL;
}
queue->singlyLinkedList=singlyLinkedList;
if(success) *success=true;
return queue;
}
void addInQueue(Queue *queue,void *ptr,bool *success)
{
if(success) *success=false;
if(queue==NULL) return;
if(queue->singlyLinkedList==NULL) return;
addInSinglyLinkedList(queue->singlyLinkedList,ptr,success);
if(success) *success=true;
}
void* removeFromQueue(Queue *queue,bool *success)
{
void *ptr;
if(success) *success=false;
if(isQueueEmpty(queue)) return NULL;
ptr=removeFromSinglyLinkedList(queue->singlyLinkedList,0,success);
if(success) *success=true;
return ptr;
}
void* elementAtFrontOfQueue(Queue *queue, bool *success)
{
void *ptr;
if(success) *success=false;
if(isQueueEmpty(queue)) return NULL;
ptr=getFromSinglyLinkedList(queue->singlyLinkedList,0,success);
if(success) *success=true;
return ptr;
}
int getSizeOfQueue(Queue *queue)
{
if(isQueueEmpty(queue)) return 0;
return getSizeOfSinglyLinkedList(queue->singlyLinkedList);
}
bool isQueueEmpty(Queue *queue)
{
if(queue==NULL) return true;
if(queue->singlyLinkedList==NULL) return true;
if(getSizeOfSinglyLinkedList(queue->singlyLinkedList)==0) return true;
return false;
}
void clearQueue(Queue *queue)
{
if(queue==NULL) return;
if(queue->singlyLinkedList==NULL) return;
clearSinglyLinkedList(queue->singlyLinkedList);
}
void destroyQueue(Queue *queue)
{
if(queue==NULL) return ;
destroySinglyLinkedList(queue->singlyLinkedList);
free(queue);
}
#endif