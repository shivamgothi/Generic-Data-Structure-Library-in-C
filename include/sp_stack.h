#ifndef __SP_STACK__H
#define __SP_STACK__H 123
#include<sp_sll.h>
#include<sp_common.h>
typedef struct __$_sp_stack
{
SinglyLinkedList *singlyLinkedList;
}Stack;
Stack* createStack(bool *success);
void pushInStack(Stack *stack,void *ptr,bool *success);
void* popFromStack(Stack *stack,bool *success);
int getSizeOfStack(Stack *stack);
void* elementAtTopOfStack(Stack *stack,bool *success);
bool isStackEmpty(Stack *stack);
void clearStack(Stack *stack);
void destroyStack(Stack *stack);
#endif