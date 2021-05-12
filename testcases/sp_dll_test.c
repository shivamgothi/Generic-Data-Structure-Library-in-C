#include<stdio.h>
#include<sp_dll.h>
int main()
{
DoublyLinkedList *list1,*list2;
int i1,i2,i3,i4,i5,i6;
DoublyLinkedListIterator itr;
bool success;
int y;
int *x;
i1=100;
i2=200;
i3=300;
i4=400;
i5=500;
i6=600;
list1=createDoublyLinkedList(&success);
if(success) printf("List1 is created\n");
list2=createDoublyLinkedList(&success);
addInDoublyLinkedList(list1,(void*)&i1,&success);
addInDoublyLinkedList(list1,(void*)&i2,&success);
addInDoublyLinkedList(list2,(void*)&i3,&success);
addInDoublyLinkedList(list2,(void*)&i4,&success);
addInDoublyLinkedList(list2,(void*)&i6,&success);
x=(int*)getFromDoublyLinkedList(list1,1,&success);
printf("%d\n",*x);
appendDoublyLinkedList(list1,list2,&success);
insertInDoublyLinkedList(list1,4,(void*)&i5,&success);
itr=getDoublyLinkedListBackIterator(list1,&success);
while(hasNextInDoublyLinkedList(&itr))
{
x=(int*)getPreviousElementFromDoublyLinkedList(&itr,&success);
printf("%d\n",*x);
}
return 0;
}