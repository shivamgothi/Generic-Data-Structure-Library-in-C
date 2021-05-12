#ifndef __SP_SLL__H
#define __SP_SLL__H 123
#include<sp_common.h>
typedef struct __$_sp_sll_n
{
void *ptr;
struct __$_sp_sll_n *next;
}SinglyLinkedListNode;
typedef struct __$_sp_sll
{
SinglyLinkedListNode *start;
SinglyLinkedListNode *end;
int size;
}SinglyLinkedList;
typedef struct __$_sp_sll_iterator
{
SinglyLinkedListNode *node;
}SinglyLinkedListIterator;
SinglyLinkedList* createSinglyLinkedList(bool *success);
void destroySinglyLinkedList(SinglyLinkedList *singlyLinkedList);
void clearSinglyLinkedList(SinglyLinkedList *singlyLinkedList);
void addInSinglyLinkedList(SinglyLinkedList *singlyLinkedList,void *ptr,bool *success);
void insertInSinglyLinkedList(SinglyLinkedList *singlyLinkedList,int index,void *ptr,bool *success);
void* removeFromSinglyLinkedList(SinglyLinkedList *singlyLinkedList,int index,bool *success);
int getSizeOfSinglyLinkedList(SinglyLinkedList *singlyLinkedList);
void appendSinglyLinkedList(SinglyLinkedList *targetSinglyLinkedList,SinglyLinkedList *sourceSinglyLinkedList,bool *success);
void* getFromSinglyLinkedList(SinglyLinkedList *singlyLinkedList,int index,bool *success);
SinglyLinkedListIterator getSinglyLinkedListIterator(SinglyLinkedList *singlyLinkedList,bool *success);
bool hasNextInSinglyLinkedList(SinglyLinkedListIterator *singlyLinkedListIterator);
void* getNextElementFromSinglyLinkedList(SinglyLinkedListIterator *singlyLinkedListIterator,bool *success);
#endif