#include<stdio.h>
#include<sp_queue.h>
#include<sp_sll.h>
int main()
{
Queue *queue;
bool success;
int *x;
int x1,x2,x3,x4,x5;
x1=100;
x2=200;
x3=300;
x4=400;
x5=500;
queue=createQueue(&success);
if(success==false)
{
printf("Unable to  create\n");
return 0;
}
addInQueue(queue,(void*)&x1,&success);
if(success) printf("%d is added in queue\n",x1);
else printf("unalbe to add %d in queue\n",x1);
addInQueue(queue,(void*)&x2,&success);
if(success) printf("%d is added in queue\n",x2);
else printf("unalbe to add %d in queue\n",x2);
addInQueue(queue,(void*)&x3,&success);
if(success) printf("%d is added in queue\n",x3);
else printf("unalbe to add %d in queue\n",x3);
addInQueue(queue,(void*)&x4,&success);
if(success) printf("%d is added in queue\n",x4);
else printf("unalbe to add %d in queue\n",x4);
printf("Size of queue is %d\n",getSizeOfQueue(queue));
x=(int*)elementAtTopOfQueue(queue,&success);
printf("%d is top element\n",*x);
if(isQueueEmpty(queue)) printf("Queue is Empty\n");
else printf("Queue Is not empty\n");
while(!isQueueEmpty(queue))
{
x=(int*)removeFromQueue(queue,&success);
if(success) printf("%d is removeed\n",*x);
}
if(isQueueEmpty(queue)) printf("Queue is Empty\n");
else printf("Queue Is not empty\n");
return 0;
}