#ifndef SORTING_H
#define SORTING_H
#include "commondefine.h"

/*
@ algo : - The algo compares the elements successive from each other starting froom first element
@ parameters :- arr elements & size of array 
*/
extern void insertsort(int *arr , size_t size);

extern void selectionsort(int *arr ,int size);

extern void bubblesort(int *arr ,int size);



#endif