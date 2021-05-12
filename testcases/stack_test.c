#include<stdio.h>
#include<sp_stack.h>
#include<sp_sll.h>
int main()
{
Stack *stack;
bool success;
int *x;
int x1,x2,x3,x4,x5;
x1=100;
x2=200;
x3=300;
x4=400;
x5=500;
stack=createStack(&success);
if(success==false)
{
printf("Unable to  create\n");
return 0;
}
pushInStack(stack,(void*)&x1,&success);
if(success) printf("%d is pushed in stack\n",x1);
else printf("unalbe to push %d in stack\n",x1);
pushInStack(stack,(void*)&x2,&success);
if(success) printf("%d is pushed in stack\n",x2);
else printf("unalbe to push %d in stack\n",x2);
pushInStack(stack,(void*)&x3,&success);
if(success) printf("%d is pushed in stack\n",x3);
else printf("unalbe to push %d in stack\n",x3);
pushInStack(stack,(void*)&x4,&success);
if(success) printf("%d is pushed in stack\n",x4);
else printf("unalbe to push %d in stack\n",x4);
printf("Size of stack is %d\n",getSizeOfStack(stack));
x=(int*)elementAtTopOfStack(stack,&success);
printf("%d is top element\n",*x);
if(isStackEmpty(stack)) printf("Stack is Empty\n");
else printf("Stack Is not empty\n");
while(!isStackEmpty(stack))
{
x=(int*)popFromStack(stack,&success);
if(success) printf("%d is poped\n",*x);
}
if(isStackEmpty(stack)) printf("Stack is Empty\n");
else printf("Stack Is not empty\n");
return 0;
}