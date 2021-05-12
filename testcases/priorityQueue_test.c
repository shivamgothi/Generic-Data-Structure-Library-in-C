#include<stdio.h>
#include<sp_common.h>
#include<sp_priority_queue.h>
typedef struct __$_element
{
int itemId;
int priority; 
}Element; 
int priorityCalculator(void *right,void *left)
{
Element *Eleft,*Eright;
Eleft=(Element*)left;
Eright=(Element*)right;
return  (Eleft->priority)-(Eright->priority);
}
int main()
{
Element elem1,elem2,elem3,elem4;
Element *elem;
bool succ;
PriorityQueue *pQueue;
pQueue=createPriorityQueue(priorityCalculator,&succ);
if(!succ)
{
printf("Unble to create priority queue\n");
return 0;
}
elem1.itemId=400;
elem1.priority=4;
elem2.itemId=300;
elem2.priority=1;
elem3.itemId=200;
elem3.priority=2;
elem4.itemId=100;
elem4.priority=3;
addInPriorityQueue(pQueue,(void*)&elem1,&succ);
if(succ) printf("elem1 is added\n");
else printf("elem1 is not added\n");
addInPriorityQueue(pQueue,(void*)&elem2,&succ);
if(succ) printf("elem2 is added\n");
else printf("elem2 is not added\n");
addInPriorityQueue(pQueue,(void*)&elem3,&succ);
if(succ) printf("elem3 is added\n");
else printf("elem3 is not added\n");
addInPriorityQueue(pQueue,(void*)&elem4,&succ);
if(succ) printf("elem4 is added\n");
else printf("elem4 is not added\n");
printf("**************\n");
if(isPriorityQueueEmpty(pQueue)) printf("priority queue is empty\n");
else printf("priority queue is not empty\n");
printf("**************\n");
elem=(Element*)removeFromPriorityQueue(pQueue,&succ);
if(succ) printf("item Id:%d  priority:%d\n",elem->itemId,elem->priority);
elem=(Element*)removeFromPriorityQueue(pQueue,&succ);
if(succ) printf("item Id:%d  priority:%d\n",elem->itemId,elem->priority);
elem=(Element*)removeFromPriorityQueue(pQueue,&succ);
if(succ) printf("item Id:%d  priority:%d\n",elem->itemId,elem->priority);
elem=(Element*)removeFromPriorityQueue(pQueue,&succ);
if(succ) printf("item Id:%d  priority:%d\n",elem->itemId,elem->priority);
printf("**************\n");
if(isPriorityQueueEmpty(pQueue)) printf("priority queue is empty\n");
else printf("priority queue is not empty\n");
return 0;
}