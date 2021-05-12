#ifndef __SP_HEAP__H
#define __SP_HEAP__H 123
#include<sp_common.h>
#include<sp_array.h>
typedef struct __$_heap
{
Array *array;
int (*predicate)(void*,void*);
int size;
}Heap;
Heap* createHeap(int (*predicate)(void*,void*),bool *success);
void addInHeap(Heap *heap,void *ptr,bool *success);
void* removeFromHeap(Heap *heap,bool *success);
void* getTopElementFromHeap(Heap *heap);
void* getElementFromHeap(Heap *heap,int index,bool *success);
void updateElementOfHeap(Heap *heap,int index,void *ptr,bool *success);
int getSizeOfHeap(Heap *heap);
void destroyHeap(Heap *heap);
#endif