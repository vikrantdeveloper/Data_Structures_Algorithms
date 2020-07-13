/*
 Author : Vikrant Thakur
 Created on : 16th April 2020 
*/
#include "commondefine.h"
#include "main.h"
#include "headerfiles.h"

#ifdef LINKEDLIST

extern bool insert;
extern bool append;
extern struct Node *put;
void linkedlist()
{
    int choice = 0;
    printf("Enter the operations on the linkedlist- 0:NEW LINKEDLIST, 1:DELETE DATA FROM LINKEDLIST, 2:SEARCH DATA IN LINKED LIST, 3:APPEND IN THE LINKED LIST, 4:NEW LIST, 5:EXIT =");
    scanf("%d", &choice);
    if (choice == 0 && insert == false)
    {
        printf("enter the number of nodes to be entered = ");
        scanf("%d",&nodes);
        printf("................\n");
        linkedlistoperations(choice, nodes);
        linkedlist();                                             // recursion function
    }
    else if (choice == 0 && insert == true)
    {
        printf("Linked list is created. Perform another operations ...\n");
        linkedlist();
    }
    if (choice == 1 && insert == true)
    {
        int id = 0;
        printf("enter the ID to be deleted.. = ");
        scanf("%d", &id);
        printf("................\n");
        linkedlistoperations(choice, id);
        linkedlist();
    }
    if (choice == 2 && insert == true)
    {
        int id = 0;
        printf("enter the ID to be search.. = ");
        scanf("%d", &id);
        printf("................\n");
        linkedlistoperations(choice, id);
        linkedlist();
    }
    if(choice == 3 && insert == true && append == false)
    {
        append = true;
        printf("Appending the list....\n");
        nodes = nodes + 1;
        linkedlistoperations(choice , appendll);
        linkedlist();
    }
    if(choice == 4 && insert == true)
    {
        nodes = 0;
        printf(" ...New linkedlist....\n");
        struct Node *next;  
        while (put != NULL)  
        {  
            next = put->next;  
            free(put);  
            put = next;  
        }    
        choice = 0;
        printf("enter the number of nodes to be entered = ");
        scanf("%d", &nodes);
        printf("................\n");
        linkedlistoperations(choice,nodes);
        linkedlist();
    }
    else if (insert == false)
    {
        printf("Kindly create a linkedlist first...\n");
        linkedlist();
    }
    else if(choice == 5 && insert == true)
    {
        printf("Exist from linkedlist operations ....\n");
    }
}
#endif

#ifdef SORTINGALGO

int choice = 0;
void sort(int *arr , size_t arrsize)
{
    printf("enter the choice to perform sorting:- 1/2/3 - insertsort , selectionsort, bubblesort = ");
    scanf("%d",&choice);
    if(choice == 1)
    {
        insertsort(arr , arrsize);
    }
    else if(choice == 2)
    {
        selectionsort(arr ,arrsize);
    }
    else if(choice == 3)
    {
        bubblesort(arr , arrsize);
    }
}
#endif

int main(void)
{
#ifdef LINKEDLIST
    /*
    Problem Statement - create a linked list to store the ID and names of the employes dynamically
    Search the employee through ID
    Delete the data of the employee
    The program is written in c.
    */
    linkedlist();

#endif

#ifdef SORTINGALGO

   /*
    Problem Statement : - Sort a given array using three sorting algos
                        - Insert sort ,selection sort and bubble sort
   */
  int array[] = {7,3,4,8,2,9,0,2};
  size_t size = sizeof(array)/sizeof(array[0]);
  printf("the size of array is = %zu\n",size);
  sort(array , size);
  for (int i = 0; i < size; i++)
  {
    printf("the sorted array elements are = %d\n",array[i]);
  }
  

#endif
}