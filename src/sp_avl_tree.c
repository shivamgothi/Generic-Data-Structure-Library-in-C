#ifndef __SP_AVL_TREE__C
#define __SP_AVL_TREE__C 123
#include<sp_stack.h>
#include<sp_queue.h>
#include<sp_avl_tree.h>
#include<sp_common.h>
#include<stdlib.h>
#include<stdio.h>
AVLTree* createAVLTree(int (*predicate)(void*,void*),bool *success)
{
AVLTree *avlTree;
if(success) *success=false;
avlTree=(AVLTree*)malloc(sizeof(AVLTree));
if(avlTree==NULL || predicate==NULL) return NULL;
avlTree->start=NULL;
avlTree->predicate=predicate;
avlTree->size=0;
if(success) *success=true;
return avlTree;
}
void destroyAVLTree(AVLTree *avlTree)
{
if(avlTree==NULL) return;
clearAVLTree(avlTree);
free(avlTree);
}
void clearAVLTree(AVLTree *avlTree)
{
int success;
void *ptr;
AVLTreeInOrderIterator avlTreeInOrderIterator;
if(avlTree==NULL) return;
avlTreeInOrderIterator=getAVLTreeInOrderIterator(avlTree,&success);
while(hasNextInOrderElementInAVLTree(&avlTreeInOrderIterator))
{
ptr=(AVLTree*)getNextInOrderElementFromAVLTree(&avlTreeInOrderIterator,&success);
free(ptr);
}
avlTree->start=NULL;
avlTree->size=0;
}
int getSizeOfAVLTree(AVLTree *avlTree)
{
if(avlTree==NULL) return 0;
return avlTree->size;
}
void insertInAVLTree(AVLTree *avlTree,void *ptr,bool *success)
{
int succ;
Stack *stack;
int weight;
AVLTreeNode *t,*j;
if(success) *success=false;
if(avlTree==NULL) return;
if(avlTree->start==NULL)
{
t=(AVLTreeNode*)malloc(sizeof(AVLTreeNode));
t->ptr=ptr;
t->left=NULL;
t->right=NULL;
avlTree->start=t;
avlTree->size++;
if(success) *success=true;
return;
}
j=avlTree->start;
stack=createStack(&succ);
if(succ==false) return;
while(1)
{
weight=avlTree->predicate(ptr,j->ptr);
if(weight==0)return;
pushInStack(stack,(void*)j,&succ);
if(succ==false)
{
destroyStack(stack);
return;
}
if(weight<0)
{
if(j->left==NULL)
{
t=(AVLTreeNode*)malloc(sizeof(AVLTreeNode));
t->ptr=ptr;
t->left=NULL;
t->right=NULL;
j->left=t;
break;
}
else
{
j=j->left;
}
}
else
{
if(j->right==NULL)
{
t=(AVLTreeNode*)malloc(sizeof(AVLTreeNode));
t->ptr=ptr;
t->left=NULL;
t->right=NULL;
j->right=t;
break;
}
else
{
j=j->right;
}
}
}
avlTree->size++;
balanceIt(avlTree,stack);
destroyStack(stack);
if(success) *success=true;
}
AVLTreeInOrderIterator getAVLTreeInOrderIterator(AVLTree *avlTree,bool *success)
{
int succ;
AVLTreeNode *j,*t;
AVLTreeInOrderIterator avlTreeInOrderIterator;
avlTreeInOrderIterator.node=NULL;
avlTreeInOrderIterator.stack=NULL;
if(success) *success=false;
if(avlTree==NULL) return avlTreeInOrderIterator;
if(avlTree->start==NULL)
{
if(success) *success=true;
return avlTreeInOrderIterator;
}
j=avlTree->start;
avlTreeInOrderIterator.stack=createStack(&succ);
if(succ==false) return avlTreeInOrderIterator;
while(j!=NULL)
{
pushInStack(avlTreeInOrderIterator.stack,(void*)j,&succ);
if(succ==false)
{ 
destroyStack(avlTreeInOrderIterator.stack);
avlTreeInOrderIterator.node=NULL;
avlTreeInOrderIterator.stack=NULL;
return avlTreeInOrderIterator;
}
j=j->left;
}
t=(AVLTreeNode*)popFromStack(avlTreeInOrderIterator.stack,success);
if(succ==false) 
{
destroyStack(avlTreeInOrderIterator.stack);
avlTreeInOrderIterator.node=NULL;
avlTreeInOrderIterator.stack=NULL;
return avlTreeInOrderIterator;
}
avlTreeInOrderIterator.node=t;
if(success) *success=true;
return avlTreeInOrderIterator; 
}
bool hasNextInOrderElementInAVLTree(AVLTreeInOrderIterator *avlTreeInOrderIterator)
{
if(avlTreeInOrderIterator==NULL) return false;
if(avlTreeInOrderIterator->node==NULL) return false;
return true;
}
void* getNextInOrderElementFromAVLTree(AVLTreeInOrderIterator *avlTreeInOrderIterator,bool *success)
{
AVLTreeNode *t,*j;
if(success) *success=false;
if(avlTreeInOrderIterator==NULL) return NULL;
if(avlTreeInOrderIterator->node==NULL) return NULL;
t=avlTreeInOrderIterator->node;
j=t->right;
while(j!=NULL)
{
pushInStack(avlTreeInOrderIterator->stack,(void*)j,success);
if(*success==false)
{
destroyStack(avlTreeInOrderIterator->stack);
avlTreeInOrderIterator->stack=NULL;
avlTreeInOrderIterator->node=NULL;
if(success) *success=true;
return t->ptr;
}
j=j->left;
}
if(!isStackEmpty(avlTreeInOrderIterator->stack))
{
j=(AVLTreeNode*)popFromStack(avlTreeInOrderIterator->stack,success);
if(*success==false)
{  
destroyStack(avlTreeInOrderIterator->stack);
avlTreeInOrderIterator->node=NULL;
avlTreeInOrderIterator->stack=NULL;
if(success) *success=true;
return t->ptr;
}
avlTreeInOrderIterator->node=j;
}
else
{
avlTreeInOrderIterator->node=NULL;
}
if(success) *success=true;
return t->ptr;
}
void* getFromAVLTree(AVLTree *avlTree,void *ptr,bool *success)
{
int weight;
AVLTreeNode *t;
if(success) *success=false;
if(avlTree==NULL) return NULL;
t=avlTree->start;
while(t!=NULL)
{
weight=avlTree->predicate(ptr,t->ptr);
if(weight==0) break;
if(weight<0) t=t->left;
else t=t->right;
}
if(t==NULL) return NULL;
if(success) *success=true;
return t->ptr;
}
bool searchInAVLTree(AVLTree *avlTree,void *ptr,bool *success)
{
int weight;
AVLTreeNode *t;
if(success) *success=false;
if(avlTree==NULL) return false;
t=avlTree->start;
while(t!=NULL)
{
weight=avlTree->predicate(ptr,t->ptr);
if(weight==0) break;
if(weight<0) t=t->left;
else t=t->right;
}
if(t==NULL) return false;
if(success) *success=true;
return true;
}
void* removeFromAVLTree(AVLTree *avlTree,void *ptr,bool *success)
{
void *tptr;
int succ;
Stack *stack;
Queue *queue;
int weight;
AVLTreeNode **p2p;
AVLTreeNode *t,*j,*e,*f,*z;
if(success) *success=false;
if(avlTree==NULL || avlTree->start==NULL) return NULL;
t=avlTree->start;
stack=createStack(&succ);
if(succ==false) return NULL;
while(t!=NULL)
{
weight=avlTree->predicate(ptr,t->ptr);
if(weight==0) break;
j=t;
pushInStack(stack,(void*)j,&succ);
if(succ==false)
{
destroyStack(stack);
return NULL;
}
if(weight<0) t=t->left;
else t=t->right;
}
if(t==NULL) return NULL;
if(t==avlTree->start) p2p=&(avlTree->start);
else if(t==j->left) p2p=&(j->left);
else p2p=&(j->right);
if(t->left==NULL && t->right==NULL)
{
*p2p=NULL;
tptr=t->ptr;
free(t);
avlTree->size--;
balanceIt(avlTree,stack);
destroyStack(stack);
if(success) *success=true;
return tptr;
}
queue=createQueue(&succ);
if(succ==false) return NULL;
if(t->right!=NULL)
{
for(e=t->right;e->left!=NULL;e=e->left) 
{
f=e;
addInQueue(queue,(void*)f,&succ);
if(succ==false) 
{
destroyQueue(queue);
return NULL;
}
}
pushInStack(stack,(void*)e,&succ);
if(succ==false) 
{
destroyStack(stack);
return NULL;
}
while(!isQueueEmpty(queue))
{
z=(AVLTreeNode*)removeFromQueue(queue,&succ);
pushInStack(stack,(void*)z,&succ);
if(succ==false) 
{
destroyStack(stack);
return NULL;
}
}
if(t->right==e)
{
e->left=t->left;
}
else
{
f->left=e->right;
e->left=t->left;
e->right=t->right;
}
}
else
{
for(e=t->left;e->right!=NULL;e=e->right) 
{
f=e;
addInQueue(queue,(void*)f,&succ);
if(succ==false) 
{
destroyQueue(queue);
return NULL;
}
}
pushInStack(stack,(void*)e,&succ);
if(succ==false) 
{
destroyStack(stack);
return NULL;
}
while(!isQueueEmpty(queue))
{
z=(AVLTreeNode*)removeFromQueue(queue,&succ);
pushInStack(stack,(void*)z,&succ);
if(succ==false) 
{
destroyStack(stack);
return NULL;
}
}
if(e!=t->left)
{
f->right=e->left;
e->left=t->left;
}
}
*p2p=e;
tptr=t->ptr;
free(t);
avlTree->size--;
balanceIt(avlTree,stack);
destroyStack(stack);
if(success) *success=true;
return tptr;
}
int getHeightOfAVLTree(AVLTreeNode *root)
{
int leftTreeHeight,rightTreeHeight;
if(root==NULL) return 0;
leftTreeHeight=getHeightOfAVLTree(root->left);
rightTreeHeight=getHeightOfAVLTree(root->right);
return (leftTreeHeight>rightTreeHeight)?leftTreeHeight+1:rightTreeHeight+1;
}
void balanceIt(AVLTree *avlTree,Stack *stack)
{
int succ;
AVLTreeNode *root,*rc,*rclc,*lc,*lcrc,*parent;
int lch,rch,dif;
AVLTreeNode **p2p;
while(!isStackEmpty(stack))
{
root=(AVLTreeNode*)popFromStack(stack,&succ);
lch=getHeightOfAVLTree(root->left);
rch=getHeightOfAVLTree(root->right);
dif=lch-rch;
if(dif>=-1 && dif<=1) continue;
if(root==avlTree->start)
{
p2p=&(avlTree->start);
}
else 
{
parent=(AVLTreeNode*)elementAtTopOfStack(stack,&succ);
if(succ==false)
{
return;
}
if(root==parent->left)
{
p2p=&(parent->left);
}
else
{
p2p=&(parent->right);
}
}
if(lch<rch)
{
rc=root->right;
if(getHeightOfAVLTree(rc->left)>getHeightOfAVLTree(rc->right))
{
rclc=rc->left;
rc->left=rclc->right;
rclc->right=rc;
root->right=rclc;
rc=root->right;
}
root->right=rc->left;
rc->left=root;
*p2p=rc;
}
else
{
lc=root->left;
if(getHeightOfAVLTree(lc->right)>getHeightOfAVLTree(lc->left))
{
lcrc=lc->right;
lc->right=lcrc->left;
lcrc->left=lc;
root->left=lcrc;
lc=root->left;
}
root->left=lc->right;
lc->right=root;
*p2p=lc;
}
}
}
AVLTreePreOrderIterator getAVLTreePreOrderIterator(AVLTree *avlTree,bool *success)
{
int succ;
AVLTreePreOrderIterator avlTreePreOrderIterator;
avlTreePreOrderIterator.node=NULL;
avlTreePreOrderIterator.stack=NULL;
if(success) *success=false;
if(avlTree==NULL) return avlTreePreOrderIterator;
if(avlTree->start==NULL)
{
if(success) *success=true;
return avlTreePreOrderIterator;
}
avlTreePreOrderIterator.node=avlTree->start;
avlTreePreOrderIterator.stack=createStack(&succ);
if(succ=false) return avlTreePreOrderIterator;
if(success) *success=true;
return avlTreePreOrderIterator;
}
bool hasNextPreOrderElementInAVLTree(AVLTreePreOrderIterator *avlTreePreOrderIterator)
{
if(avlTreePreOrderIterator==NULL || avlTreePreOrderIterator->node==NULL) return false;
return true;
}
void* getNextPreOrderElementFromAVLTree(AVLTreePreOrderIterator *avlTreePreOrderIterator,bool *success)
{
int succ;
AVLTreeNode *t,*j;
if(success) *success=false;
if(avlTreePreOrderIterator==NULL || avlTreePreOrderIterator->node==NULL) return NULL;
t=avlTreePreOrderIterator->node;
if(t->right!=NULL)
{
pushInStack(avlTreePreOrderIterator->stack,(void*)(t->right),&succ);
if(succ==false)
{
destroyStack(avlTreePreOrderIterator->stack);
avlTreePreOrderIterator->node=NULL;
avlTreePreOrderIterator->stack=NULL;
if(success) *success=true;
return t->ptr;
}
}
if(t->left!=NULL)
{
pushInStack(avlTreePreOrderIterator->stack,(void*)(t->left),&succ);
if(succ==false)
{
destroyStack(avlTreePreOrderIterator->stack);
avlTreePreOrderIterator->node=NULL;
avlTreePreOrderIterator->stack=NULL;
if(success) *success=true;
return t->ptr;
}
}
if(!isStackEmpty(avlTreePreOrderIterator->stack))
{
avlTreePreOrderIterator->node=(AVLTreeNode*)popFromStack(avlTreePreOrderIterator->stack,&succ);
if(succ==false)
{
destroyStack(avlTreePreOrderIterator->stack);
avlTreePreOrderIterator->node=NULL;
avlTreePreOrderIterator->stack=NULL;
if(success) *success=true;
return t->ptr;
}
}
else
{
destroyStack(avlTreePreOrderIterator->stack);
avlTreePreOrderIterator->node=NULL;
avlTreePreOrderIterator->stack=NULL;
if(success) *success=true;
return t->ptr;
}
return t->ptr;
}
AVLTreePostOrderIterator getAVLTreePostOrderIterator(AVLTree *avlTree,bool *success)
{
int succ;
AVLTreeNode *t,*j;
AVLTreePostOrderIterator avlTreePostOrderIterator;
avlTreePostOrderIterator.node=NULL;
avlTreePostOrderIterator.stack=NULL;
if(success) *success=false;
if(avlTree==NULL) return avlTreePostOrderIterator;
if(avlTree->start==NULL) 
{
if(success) *success=true;
return avlTreePostOrderIterator;
}
avlTreePostOrderIterator.stack=createStack(&succ);
if(succ==false) return avlTreePostOrderIterator;
t=avlTree->start;
while(1)
{
while(t!=NULL)
{
if(t->right!=NULL)
{
pushInStack(avlTreePostOrderIterator.stack,(void*)t->right,&succ);
if(succ==false)
{
destroyStack(avlTreePostOrderIterator.stack);
return avlTreePostOrderIterator;
}
}
pushInStack(avlTreePostOrderIterator.stack,(void*)t,&succ);
{
if(succ==false) 
{
destroyStack(avlTreePostOrderIterator.stack);
return avlTreePostOrderIterator;
}
}
t=t->left;
}
t=(AVLTreeNode*)popFromStack(avlTreePostOrderIterator.stack,&succ);
if(!isStackEmpty(avlTreePostOrderIterator.stack) && t->right!=NULL && t->right==(AVLTreeNode*)elementAtTopOfStack(avlTreePostOrderIterator.stack,&succ))
{
popFromStack(avlTreePostOrderIterator.stack,&succ);
pushInStack(avlTreePostOrderIterator.stack,(void*)t,&succ);
if(succ==false)
{
destroyStack(avlTreePostOrderIterator.stack);
return avlTreePostOrderIterator;
}
t=t->right;
}
else
{
avlTreePostOrderIterator.node=t;
break;
}
}
if(success) *success=true;
return avlTreePostOrderIterator;
}
bool hasNextPostOrderElementInAVLTree(AVLTreePostOrderIterator *avlTreePostOrderIterator)
{
if(avlTreePostOrderIterator==NULL || avlTreePostOrderIterator->node==NULL) return false;
return true;
}
void* getNextPostOrderElementFromAVLTree(AVLTreePostOrderIterator *avlTreePostOrderIterator,bool *success)
{
int succ;
AVLTreeNode *t,*j;
if(success) *success=false;
if(avlTreePostOrderIterator==NULL || avlTreePostOrderIterator->node==NULL) return NULL;
j=avlTreePostOrderIterator->node;
if(isStackEmpty(avlTreePostOrderIterator->stack))
{
destroyStack(avlTreePostOrderIterator->stack);
avlTreePostOrderIterator->stack=NULL;
avlTreePostOrderIterator->node=NULL;
if(success) *success=true;
return j->ptr;
}
t=NULL;
while(1)
{
while(t!=NULL)
{
if(t->right!=NULL) 
{
pushInStack(avlTreePostOrderIterator->stack,(void*)t->right,&succ);
if(succ==false)
{
destroyStack(avlTreePostOrderIterator->stack);
avlTreePostOrderIterator->stack=NULL;
avlTreePostOrderIterator->node=NULL;
if(success) *success=true;
return j->ptr;
}
}
pushInStack(avlTreePostOrderIterator->stack,(void*)t,&succ);
if(succ==false)
{
destroyStack(avlTreePostOrderIterator->stack);
avlTreePostOrderIterator->stack=NULL;
avlTreePostOrderIterator->node=NULL;
if(success) *success=true;
return j->ptr;
}
t=t->left;
}
t=(AVLTreeNode*)popFromStack(avlTreePostOrderIterator->stack,&succ);
if(!isStackEmpty(avlTreePostOrderIterator->stack) && t->right!=NULL && t->right==(AVLTreeNode*)elementAtTopOfStack(avlTreePostOrderIterator->stack,&succ))
{
popFromStack(avlTreePostOrderIterator->stack,&succ);
pushInStack(avlTreePostOrderIterator->stack,(void*)t,&succ);
if(succ==false)
{
destroyStack(avlTreePostOrderIterator->stack);
avlTreePostOrderIterator->stack=NULL;
avlTreePostOrderIterator->node=NULL;
return j->ptr;
}
t=t->right;
}
else
{
avlTreePostOrderIterator->node=t;
break;
}
}
if(success) *success =true;
return j->ptr;  
}
AVLTreeLevelOrderIterator getAVLTreeLevelOrderIterator(AVLTree *avlTree,bool *success)
{
int succ;
AVLTreeNode *j,*t;
AVLTreeLevelOrderIterator avlTreeLevelOrderIterator;
avlTreeLevelOrderIterator.node=NULL;
avlTreeLevelOrderIterator.queue=NULL;
if(success) *success=false;
if(avlTree==NULL) return avlTreeLevelOrderIterator;
if(avlTree->start==NULL)
{
if(success) *success=true;
return avlTreeLevelOrderIterator;
}
j=avlTree->start;
avlTreeLevelOrderIterator.queue=createQueue(&succ);
if(succ==false) return avlTreeLevelOrderIterator;
avlTreeLevelOrderIterator.node=j;
if(success) *success=true;
return avlTreeLevelOrderIterator; 
}
bool hasNextLevelOrderElementInAVLTree(AVLTreeLevelOrderIterator *avlTreeLevelOrderIterator)
{
if(avlTreeLevelOrderIterator==NULL) return false;
if(avlTreeLevelOrderIterator->node==NULL) return false;
return true;
}
void* getNextLevelOrderElementFromAVLTree(AVLTreeLevelOrderIterator *avlTreeLevelOrderIterator,bool *success)
{
int succ;
AVLTreeNode *t,*j;
if(success) *success=false;
if(avlTreeLevelOrderIterator==NULL) return NULL;
if(avlTreeLevelOrderIterator->node==NULL) return NULL;
t=avlTreeLevelOrderIterator->node;
if(t->left!=NULL)
{
addInQueue(avlTreeLevelOrderIterator->queue,(void*)(t->left),&succ);
if(succ==false)
{
destroyQueue(avlTreeLevelOrderIterator->queue);
avlTreeLevelOrderIterator->node=NULL;
avlTreeLevelOrderIterator->queue=NULL;
if(success) *success=true;
return t->ptr;
}
}
if(t->right!=NULL)
{
addInQueue(avlTreeLevelOrderIterator->queue,(void*)(t->right),&succ);
if(succ==false)
{
destroyQueue(avlTreeLevelOrderIterator->queue);
avlTreeLevelOrderIterator->node=NULL;
avlTreeLevelOrderIterator->queue=NULL;
if(success) *success=true;
return t->ptr;
}
}
if(!isQueueEmpty(avlTreeLevelOrderIterator->queue))
{
avlTreeLevelOrderIterator->node=(AVLTreeNode*)removeFromQueue(avlTreeLevelOrderIterator->queue,&succ);
if(succ==false)
{
destroyQueue(avlTreeLevelOrderIterator->queue);
avlTreeLevelOrderIterator->node=NULL;
avlTreeLevelOrderIterator->queue=NULL;
if(success) *success=true;
return t->ptr;
}
}
else
{
destroyQueue(avlTreeLevelOrderIterator->queue);
avlTreeLevelOrderIterator->node=NULL;
avlTreeLevelOrderIterator->queue=NULL;
if(success) *success=true;
return t->ptr;
}
if(success) *success=true;
return t->ptr;
}
#endif