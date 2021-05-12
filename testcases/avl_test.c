#include<stdio.h>
#include<sp_common.h>
#include<sp_avl_tree.h>
#include<stdlib.h>
int predicate(void *left,void *right)
{
int *leftInt,*rightInt;
leftInt=(int*)left;
rightInt=(int*)right;
return (*leftInt)-(*rightInt);
}
int main()
{
int height;
int ch;
char m;
int num;
int *x;
AVLTree *tree;
AVLTreeInOrderIterator inIterator;
AVLTreePostOrderIterator postIterator;
AVLTreePreOrderIterator preIterator;
AVLTreeLevelOrderIterator levelIterator;
bool success;
tree=createAVLTree(predicate,&success);
if(success==false) 
{
printf("Unable to create tree\n");
return 0;
}
while(1)
{
printf("1.Add Item\n");
printf("2.Seach Item\n");
printf("3.Print Item In Inorder\n");
printf("4.Remove Item\n");
printf("5.Height Of Tree\n");
printf("6.Print Item In Preorder\n");
printf("7.Print Item In Postorder\n");
printf("8.Print Item In Leveloder\n");
printf("9.Get Size Of Tree\n");
printf("10.Exit\n");
printf("choose any option:");
scanf("%d",&ch);
fflush(stdin);
if(ch==1)
{
while(1)
{
printf("Enter a number:");
scanf("%d",&num);
fflush(stdin);
x=(int*)malloc(sizeof(int));
*x=num;
insertInAVLTree(tree,(void*)x,&success);
if(success) printf("Address which contain %d is added in tree\n",*x);
else printf("Unable to add\n");
printf("Are you want to add more(Y/N):");
m=getchar();
fflush(stdin);
if(m!='Y'&& m!='y')
{
break;
}
}
}
if(ch==2)
{
printf("Search For What:");
scanf("%d",&num);
fflush(stdin);
x=(int*)getFromAVLTree(tree,(void*)&num,&success);
if(success) printf("%d\n",*x);
else printf("Not exist\n");
}
if(ch==3)
{
inIterator=getAVLTreeInOrderIterator(tree,&success);
if(success)
{	
while(hasNextInOrderElementInAVLTree(&inIterator))
{
x=(int*)getNextInOrderElementFromAVLTree(&inIterator,&success);
printf("%d\n",*x);
}
}
}
if(ch==4)
{
printf("Enter a number:");
scanf("%d",&num);
fflush(stdin);
x=(int*)removeFromAVLTree(tree,(void*)&num,&success);
if(success) printf("%d is  removed\n",*x);
else printf("Item Not Exist\n");
}
if(ch==5) 
{
height=getHeightOfAVLTree(tree->start);
printf("Height of tree is %d\n",height);
}
if(ch==6)
{
preIterator=getAVLTreePreOrderIterator(tree,&success);
if(success)
{	
while(hasNextPreOrderElementInAVLTree(&preIterator))
{
x=(int*)getNextPreOrderElementFromAVLTree(&preIterator,&success);
printf("%d\n",*x);
}
}
}
if(ch==7)
{
postIterator=getAVLTreePostOrderIterator(tree,&success);
if(success)
{	
while(hasNextPostOrderElementInAVLTree(&postIterator))
{
x=(int*)getNextPostOrderElementFromAVLTree(&postIterator,&success);
printf("%d\n",*x);
}
}
}
if(ch==8)
{
levelIterator=getAVLTreeLevelOrderIterator(tree,&success);
if(success)
{	
while(hasNextLevelOrderElementInAVLTree(&levelIterator))
{
x=(int*)getNextLevelOrderElementFromAVLTree(&levelIterator,&success);
printf("%d\n",*x);
}
}
}
if(ch==9)
{
printf("%d\n",getSizeOfAVLTree(tree));
}
if(ch==10) break;
}
return 0;
}