#ifndef __SP_STACK__C
#define __SP_STACK__C 123
#include<sp_stack.h>
#include<sp_sll.h>
#include<stdlib.h>
#include<stdio.h>
Stack* createStack(bool *success)
{
Stack *stack;
SinglyLinkedList *singlyLinkedList;
if(success) *success=false;
singlyLinkedList=createSinglyLinkedList(success);
if(singlyLinkedList==NULL) return NULL;
stack=(Stack*)malloc(sizeof(Stack));
if(stack==NULL)
{
destroySinglyLinkedList(singlyLinkedList);
if(success) *success=false;
return NULL;
}
stack->singlyLinkedList=singlyLinkedList;
if(success) *success=true;
return stack;
}
void pushInStack(Stack *stack,void *ptr,bool *success)
{
if(success) *success=false;
if(stack==NULL) return;
if(stack->singlyLinkedList==NULL) return;
insertInSinglyLinkedList(stack->singlyLinkedList,0,ptr,success);
if(success) *success=true;
}
void* popFromStack(Stack *stack,bool *success)
{
void *ptr;
if(success) *success=false;
if(isStackEmpty(stack)) return NULL;
ptr=removeFromSinglyLinkedList(stack->singlyLinkedList,0,success);
if(success) *success=true;
return ptr;
}
void* elementAtTopOfStack(Stack *stack, bool *success)
{
void *ptr;
if(success) *success=false;
if(isStackEmpty(stack)) return NULL;
ptr=getFromSinglyLinkedList(stack->singlyLinkedList,0,success);
if(success) *success=true;
return ptr;
}
int getSizeOfStack(Stack *stack)
{
if(isStackEmpty(stack)) return 0;
return getSizeOfSinglyLinkedList(stack->singlyLinkedList);
}
bool isStackEmpty(Stack *stack)
{
if(stack==NULL) return true;
if(stack->singlyLinkedList==NULL) return true;
if(getSizeOfSinglyLinkedList(stack->singlyLinkedList)==0) return true;
return false;
}
void clearStack(Stack *stack)
{
if(stack==NULL) return;
if(stack->singlyLinkedList==NULL) return;
clearSinglyLinkedList(stack->singlyLinkedList);
}
void destroyStack(Stack *stack)
{
if(stack==NULL) return ;
destroySinglyLinkedList(stack->singlyLinkedList);
free(stack);
}
#endif