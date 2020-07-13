#include "headerfiles.h"
#include "commondefine.h"

void insertsort(int *arr , size_t size)
{
    int swap = 0;
    int j=0; 
    for (int i = 1 ;i < size ; i++)
    {
        j=i;
        while(arr[j-1]>arr[j] && j>0)
        {
            //swap value
            swap = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = swap;
            j--;
        } 
    }
}
void selectionsort(int *arr ,int size)
{

}
void bubblesort(int *arr ,int size)
{

}