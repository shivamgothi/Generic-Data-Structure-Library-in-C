#ifndef __SP_QUEUE__H
#define __SP_QUEUE__H 123
#include<sp_sll.h>
#include<sp_common.h>
typedef struct __$_sp_queue
{
SinglyLinkedList *singlyLinkedList;
}Queue;
Queue* createQueue(bool *success);
void addInQueue(Queue *queue,void *ptr,bool *success);
void* removeFromQueue(Queue *queue,bool *success);
int getSizeOfQueue(Queue *queue);
void* elementAtFrontOfQueue(Queue *queue,bool *success);
bool isQueueEmpty(Queue *queue);
void clearQueue(Queue *queue);
void destroyQueue(Queue *queue);
#endif