#include<sp_common.h>
#include<sp_heap.h>
#include<stdio.h>
#include<stdlib.h>
int comparator(void *left,void *right)
{
int *intLeft,*intRight;
intLeft=(int*)left;
intRight=(int*)right;
printf("%d   %d\n",*intLeft,*intRight);
return (*intLeft)-(*intRight);
}
int main()
{
Heap *heap;
bool succ;
int *p;
int ch,num;
heap=createHeap(comparator,&succ);
if(!succ) 
{
printf("unable to create\n");
return 0;
}
else printf("heap created\n");
while(1)
{
printf("1.Add\n");
printf("2.Remove\n");
printf("3.Get Top Element\n");
printf("4.Get Size\n");
printf("5.Exit\n");
printf("Enter your choice:");
scanf("%d",&ch);
fflush(stdin);
if(ch==1)
{
printf("Enter a number:");
scanf("%d",&num);
fflush(stdin);
p=(int*)malloc(sizeof(int));
*p=num;
addInHeap(heap,(void*)p,&succ);
if(succ) printf("%d is added\n",*p);
else printf("unable to add\n");
}
else if(ch==2)
{
p=(int*)removeFromHeap(heap,&succ);
if(succ) printf("%d is removed\n",*p);
else printf("unable to remove\n");
}
else if(ch==3)
{
p=(int*)getTopElementFromHeap(heap);
if(succ) printf("%d is topest elemnt\n",*p);
else printf("No element\n");
}
else if(ch==4) 
{
printf("%d\n",getSizeOfHeap(heap));
}
else if(ch==5)
{
destroyHeap(heap);
break;
} 
}
return 0;
}