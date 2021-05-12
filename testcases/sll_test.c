#include<stdio.h>
#include<sp_sll.h>
int main()
{
SinglyLinkedList *list1,*list2;
int i1,i2,i3,i4,i5,i6;
SinglyLinkedListIterator itr;
bool success;
int y;
int *x;
i1=100;
i2=200;
i3=300;
i4=400;
i5=500;
i6=600;
list1=createSinglyLinkedList(&success);
list2=createSinglyLinkedList(&success);
if(success) printf("List1 is created\n");
addInSinglyLinkedList(list1,(void*)&i1,&success);
addInSinglyLinkedList(list1,(void*)&i2,&success);
addInSinglyLinkedList(list2,(void*)&i3,&success);
addInSinglyLinkedList(list2,(void*)&i4,&success);
addInSinglyLinkedList(list2,(void*)&i6,&success);
appendSinglyLinkedList(list1,list2,&success);
itr=getSinglyLinkedListIterator(list1,&success);
while(hasNextInSinglyLinkedList(&itr))
{
x=(int*)getNextElementFromSinglyLinkedList(&itr,&success);
printf("%d\n",*x);
}
return 0;
}