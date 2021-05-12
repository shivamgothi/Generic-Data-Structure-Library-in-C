#ifndef __SP_ARRAY__H
#define __SP_ARRAY__H 123
#include<sp_common.h>
typedef struct __$_array
{
void ***a;
int size;
int rows;
}Array;
Array* createArray(bool *success);
void addInArray(Array *array,int index,void *ptr,bool *success);
void* getElementFromArray(Array *array,int index);
int getSizeOfArray(Array *array);
void destroyArray(Array *array);
#endif
