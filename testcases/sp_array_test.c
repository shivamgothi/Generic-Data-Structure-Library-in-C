#include<stdio.h>
#include<sp_array.h>
int main()
{
Array *array;
int i,j;
int *x;
int x1,x2,x3;
bool succ;
x1=111;
x2=222;
x3=333;
array=createArray(&succ);
addInArray(array,0,&x1,&succ);
addInArray(array,25,&x2,&succ);
addInArray(array,1000,&x3,&succ);
j=getSizeOfArray(array);
for(i=0;i<j;i++)
{
x=(int*)getElementFromArray(array,i);
if(x!=NULL) printf("(%d-->%d)",i,*x);
else printf("(%d--->  )",i);
}
destroyArray(array);
return 0;
}