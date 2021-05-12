#include<stdio.h>
#include<sp_heap.h>
int comparator(void *l,void *r)
{
int *left,*right;
left=(int*)l;
right=(int*)r;
return *left-*right;
}
int main()
{
Heap *heap;
int succ,i;
int *x;
int x1,x2,x3,x4,x5,x6,x7;
x1=10;
x2=2;
x3=-1;
x4=50;
x5=25;
x6=-5;
x7=60;
heap=createHeap(comparator,&succ);
addInHeap(heap,(void*)&x1,&succ);
addInHeap(heap,(void*)&x2,&succ);
addInHeap(heap,(void*)&x3,&succ);
addInHeap(heap,(void*)&x4,&succ);
addInHeap(heap,(void*)&x5,&succ);
for(i=0;i<getSizeOfHeap(heap);i++)
{
x=(int*)getElementFromHeap(heap,i,&succ);
printf("%d\n",*x);
}
updateElementOfHeap(heap,1,(void*)&x6,&succ);
updateElementOfHeap(heap,2,(void*)&x7,&succ);
printf("After updated\n");
for(i=0;i<getSizeOfHeap(heap);i++)
{
x=(int*)getElementFromHeap(heap,i,&succ);
printf("%d\n",*x);
}
return 0;
}


