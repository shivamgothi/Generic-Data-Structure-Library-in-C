#ifndef __SP_AVL_TREE__H
#define __SP_AVL_TREE__H 123
#include<sp_common.h>
#include<sp_stack.h>
#include<sp_queue.h>
#include<stdio.h>
typedef struct __$_avl_tree_node
{
void *ptr;
struct __$_avl_tree_node *left;
struct __$_avl_tree_node *right;
}AVLTreeNode;
typedef struct __$_avl_tree
{
AVLTreeNode *start;
int size;
int (*predicate)(void*,void*);
}AVLTree;
typedef struct __$_avl_tree_in_order_iterator
{
AVLTreeNode *node;
Stack *stack;
}AVLTreeInOrderIterator;
typedef struct __$_avl_tree_pre_order_iterator
{
AVLTreeNode *node;
Stack *stack;
}AVLTreePreOrderIterator;
typedef struct __$_avl_tree_post_order_iterator
{
AVLTreeNode *node;
Stack *stack;
}AVLTreePostOrderIterator;
typedef struct __$_avl_tree_level_order_iterator
{
AVLTreeNode *node;
Queue *queue;
}AVLTreeLevelOrderIterator;
AVLTree* createAVLTree(int (*predicate)(void*,void*),bool *success);
void destroyAVLTree(AVLTree *avlTree);
void clearAVLTree(AVLTree *avlTree);
int getSizeOfAVLTree(AVLTree *avlTree);
void insertInAVLTree(AVLTree *avlTree,void *ptr,bool *success);
void* removeFromAVLTree(AVLTree *avlTree,void *ptr,bool *success);
void* getFromAVLTree(AVLTree *avlTree,void *ptr,bool *success);
bool searchInAVLTree(AVLTree *avlTree,void *ptr,bool *success);
int getHeightOfAVLTree(AVLTreeNode *root);
void balanceIt(AVLTree *avlTree,Stack *stack);
AVLTreeInOrderIterator getAVLTreeInOrderIterator(AVLTree *avlTree,bool *success);
bool hasNextInOrderElementInAVLTree(AVLTreeInOrderIterator *avlTreeInOrderIterator);
void* getNextInOrderElementFromAVLTree(AVLTreeInOrderIterator *avlTreeInOrderIterator,bool *success);
AVLTreePostOrderIterator getAVLTreePostOrderIterator(AVLTree *avlTree,bool *success);
bool hasNextPostOrderElementInAVLTree(AVLTreePostOrderIterator *avlTreePostOrderIterator);
void* getNextPostOrderElementFromAVLTree(AVLTreePostOrderIterator *avlTreePostOrderIterator,bool *success);
AVLTreePreOrderIterator getAVLTreePreOrderIterator(AVLTree *avlTree,bool *success);
bool hasNextPreOrderElementInAVLTree(AVLTreePreOrderIterator *avlTreePreOrderIterator);
void* getNextPreOrderElementFromAVLTree(AVLTreePreOrderIterator *avlTreePreOrderIterator,bool *success);
AVLTreeLevelOrderIterator getAVLTreeLevelOrderIterator(AVLTree *avlTree,bool *success);
bool hasNextLevelOrderElementInAVLTree(AVLTreeLevelOrderIterator *avlTreeLevelOrderIterator);
void* getNextLevelOrderElementFromAVLTree(AVLTreeLevelOrderIterator *avlTreeLevelOrderIterator,bool *success);
#endif