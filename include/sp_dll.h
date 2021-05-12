#ifndef __SP_DLL__H
#define __SP_DLL__H 123
#include<sp_common.h>
typedef struct __$_sp_dll_n
{
void *ptr;
struct __$_sp_dll_n *next;
struct __$_sp_dll_n *previous;
}DoublyLinkedListNode;
typedef struct __$_sp_dll
{
DoublyLinkedListNode *start;
DoublyLinkedListNode *end;
int size;
}DoublyLinkedList;
typedef struct __$_sp_dll_iterator
{
DoublyLinkedListNode *node;
}DoublyLinkedListIterator;

DoublyLinkedList* createDoublyLinkedList(bool *success);
void destroyDoublyLinkedList(DoublyLinkedList *doublyLinkedList);
void clearDoublyLinkedList(DoublyLinkedList *doublyLinkedList);
void addInDoublyLinkedList(DoublyLinkedList *doublyLinkedList,void *ptr,bool *success);
void insertInDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index, void *ptr,bool *success);
void* removeFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int index, bool *success);
void appendDoublyLinkedList(DoublyLinkedList *targetDoublyLinkedList,DoublyLinkedList *sourceDoublyLinkedList,bool *success);
int getSizeOfDoublyLinkedList(DoublyLinkedList *doublyLinkedList);
void* getFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,bool *success);
DoublyLinkedListIterator getDoublyLinkedListNextIterator(DoublyLinkedList *doublyLinkedList,bool *success);
void* getNextElementFromDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator, bool *success);
bool hasNextInDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator);
DoublyLinkedListIterator getDoublyLinkedListBackIterator(DoublyLinkedList *doublyLinkedList,bool *success);
void* getPreviousElementFromDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator, bool *success);
#endif