#ifndef __SP_ARRAY__C
#define __SP_ARRAY__C 123
#include<sp_common.h>
#include<stdlib.h>
#include<sp_array.h>
#include<stdio.h>
Array* createArray(bool *success)
{
Array *array;
if(success) *success=false;
array=(Array*)malloc(sizeof(Array));
if(array==NULL) return NULL;
array->a=NULL;
array->size=0;
array->rows=0;
if(success) *success=true;
return array;
}
void addInArray(Array *array,int index,void *ptr,bool *success)
{
int sp,ep,i,rowIndex,coloumIndex;
void ***t;
if(success) *success=false;
if(array==NULL) return;
if(index<0) return;
rowIndex=index/10;
coloumIndex=index%10;
if(rowIndex>=array->rows)
{
if(array->a!=NULL)
{
t=(void***)calloc(rowIndex+1,sizeof(void**));
if(t==NULL) return;
sp=0;
ep=array->rows-1;
for(i=sp;i<=ep;i++) t[i]=array->a[i];
free(array->a);
array->a=t;
array->rows=rowIndex+1;
}
else
{
array->a=(void***)calloc(rowIndex+1,sizeof(void**));
if(array->a==NULL) return;
array->rows=rowIndex+1;
}
}
if(array->a[rowIndex]==NULL)
{
array->a[rowIndex]=(void**)calloc(10,sizeof(void*));
if(t==NULL) return;
}
array->a[rowIndex][coloumIndex]=ptr;
if(index>=array->size) array->size=index+1;
if(success) *success=true;
}
void* getElementFromArray(Array *array,int index)
{
int rowIndex,coloumIndex;
if(array==NULL || array->a==NULL) return NULL;
if(index<0) return NULL;
rowIndex=index/10;
coloumIndex=index%10;
if(rowIndex>=array->size) return NULL;
if(array->a[rowIndex]==NULL) return NULL;
return array->a[rowIndex][coloumIndex];
}
int getSizeOfArray(Array *array)
{
if(array==NULL) return 0;
return array->size;
}
void destroyArray(Array *array)
{
int i,sp,ep;
void **ptr;
sp=0;
ep=array->size/10;
for(i=0;i<ep;i++)
{
if(array->a[i]!=NULL) free(array->a[i]);
}
free(array->a);
free(array);
}
#endif
