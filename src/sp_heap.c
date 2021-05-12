#ifndef __SP_HEAP__C
#define __SP_HEAP__C 123
#include<sp_heap.h>
#include<sp_array.h>
#include<stdlib.h>
#include<stdio.h>
Heap* createHeap(int (*predicate)(void*,void*),bool *success)
{
int succ;
Heap *heap;
if(success) *success=false;
heap=(Heap*)malloc(sizeof(Heap));
if(heap==NULL || predicate==NULL) return NULL;
heap->predicate=predicate;
heap->array=createArray(&succ);
heap->size=0;
if(!succ) return NULL;
if(success) *success=true;
return heap;
}
void addInHeap(Heap *heap,void *ptr,bool *success)
{
int succ,ci,ri,weight; 
void *left,*right,*t;
if(success) *success=false;                
if(heap==NULL || heap->array==NULL) return;
addInArray(heap->array,heap->size,ptr,&succ);
if(!succ) return;
ci=heap->size;
heap->size++;
while(ci>0)
{
ri=(ci-1)/2;
left=getElementFromArray(heap->array,ci);
right=getElementFromArray(heap->array,ri);
weight=heap->predicate(left,right);
if(weight<0)
{
addInArray(heap->array,ci,right,&succ);
addInArray(heap->array,ri,left,&succ);
ci=ri;
}
else 
{
break;
}
}
if(success) *success=true;
}
void* removeFromHeap(Heap *heap,bool *success)
{
void *left,*right,*tmp;
int ri,lci,rci,swi,lb,ub,succ,weight;
if(success) *success=false;
if(heap==NULL || heap->array==NULL) return NULL;
lb=0;
ub=heap->size-1;
left=getElementFromArray(heap->array,lb);
right=getElementFromArray(heap->array,ub);
addInArray(heap->array,ub,left,&succ);
addInArray(heap->array,lb,right,&succ);
tmp=getElementFromArray(heap->array,ub);
ub--;
ri=0;
while(ri<ub)
{
lci=(ri*2)+1;
rci=lci+1;
if(lci>ub) break;
else if(rci>ub) swi=lci;
else
{
left=getElementFromArray(heap->array,lci);
right=getElementFromArray(heap->array,rci);
weight=heap->predicate(left,right);
if(weight<0) swi=lci;
else swi=rci;
}
left=getElementFromArray(heap->array,swi);
right=getElementFromArray(heap->array,ri);
weight=heap->predicate(left,right);
if(weight<0)
{
addInArray(heap->array,ri,left,&succ);
addInArray(heap->array,swi,right,&succ);
ri=swi;
}
else break;
}
heap->size--;
if(success) *success=true;
return tmp;
}
void* getTopElementFromHeap(Heap *heap)
{
if(heap==NULL || heap->array==NULL) return NULL;
return getElementFromArray(heap->array,0);
}
int getSizeOfHeap(Heap *heap)
{
if(heap==NULL || heap->array==NULL) return 0;
return heap->size;
}
void destroyHeap(Heap *heap)
{
if(heap==NULL) return;
if(heap->array!=NULL) destroyArray(heap->array);
free(heap);
}

void* getElementFromHeap(Heap *heap,int index,bool *success)
{
void *ptr=NULL;
if(success) *success=false;
if(heap==NULL) return ptr;
if(heap->array==NULL) return ptr;
if(index<0 || index>=heap->size) return ptr;
ptr=getElementFromArray(heap->array,index);
if(success) *success=true;
return ptr;
}
void updateElementOfHeap(Heap *heap,int index,void *ptr,bool *success)
{
int succ,goDown,ri,ci,lci,rci,swi,weight,ub;
void *left,*right,*t;
if(success) *success=false;
if(heap==NULL) return;
if(heap->array==NULL) return;
if(index<0 || index>=heap->size) return;
addInArray(heap->array,index,ptr,&succ);
if(index==0)
{
goDown=true;
}
else if(index==heap->size-1)
{
goDown=false;
}
else
{
ci=index;
ri=(ci-1)/2;
left=getElementFromArray(heap->array,ci);
right=getElementFromArray(heap->array,ri);
weight=heap->predicate(left,right);
if(weight<0) goDown=false;
else goDown=true;
}
if(goDown)
{
ub=heap->size-1;
ri=index;
while(ri<ub)
{
lci=(ri*2)+1;
rci=lci+1;
if(lci>ub) break;
else if(rci>ub) swi=lci;
else
{
left=getElementFromArray(heap->array,lci);
right=getElementFromArray(heap->array,rci);
weight=heap->predicate(left,right);
if(weight<0) swi=lci;
else swi=rci;
}
left=getElementFromArray(heap->array,swi);
right=getElementFromArray(heap->array,ri);
weight=heap->predicate(left,right);
if(weight<0)
{
addInArray(heap->array,ri,left,&succ);
addInArray(heap->array,swi,right,&succ);
ri=swi;
}
else break;
}
}
else
{
ci=index;
while(ci>0)
{
ri=(ci-1)/2;
left=getElementFromArray(heap->array,ci);
right=getElementFromArray(heap->array,ri);
weight=heap->predicate(left,right);
if(weight<0)
{
addInArray(heap->array,ci,right,&succ);
addInArray(heap->array,ri,left,&succ);
ci=ri;
}
else 
{
break;
}
}
}
if(success) *success=true;
}
#endif
