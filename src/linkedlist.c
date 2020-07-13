/*
 Author : Vikrant Thakur 
 Created on : April 16, 2020
*/
#include "commondefine.h"
#include "headerfiles.h"

bool insert = false;
bool append = false;

int nodes = 0;

struct Node *put = NULL;

employee_count employee_obj;
static struct Node *create_node(char *name, int id, int len)
{
    struct Node *employee_details;
    employee_details = (struct Node *)malloc(sizeof(struct Node));
    employee_details->employee_id = id;
    employee_details->employee_name = (char *)malloc(len);
    employee_obj.noofemployee = nodes;
    memcpy(employee_details->employee_name, name, len);
    return employee_details;
}
static void print_data(struct Node *put)
{
    printf(".............................\n");
    while (put != NULL)
    {
        printf("employee id = %d\t", put->employee_id);
        printf("employee name = %s\n", put->employee_name);
        put = put->next;
    }
}
static struct Node *insert_node(struct Node *emp, char *name, int id, int len , bool append)
{
   if(append == false)
   {
    if (emp == NULL)
    {
        emp = create_node(name, id, len);
    }
    else
    {
        //recursion keeps calling until loop ends...
        emp->next = insert_node(emp->next, name, id, len ,append);
    }
   }
   else if(append == true)
   { 
        if(emp == NULL)
        {
            emp = create_node(name, id, len);
            append = false;
        }
        else
        {
            emp->next = insert_node(emp->next, name, id, len ,append);
        }
   }
    return emp;
}
static struct Node *multiple_node(int num, struct Node *emp)
{
    int id;
    char name[255];
    for (int i = 0; i < num; i++)
    {
        // keeps adding the details
        printf("enter the employee id = ");
        scanf("%d", &id);
        printf("enter the employee name = ");
        scanf("%s", name);
        int len = strlen(name);
        emp = insert_node(emp, name, id, len ,append);
    }
    return emp;
}
static void search_node(int search , struct Node *currentnode)
{
    struct Node *temp = currentnode;
    if (temp != NULL)
    {
    while (temp != NULL)
        {

            if (temp->employee_id == search)   // search the id
            {
                
                printf("ID found in linkedlist\n");
                print_data(temp);       
                return;  
                
            }
            else if(temp == NULL)
            {

                printf("ID not found in linkedlist\n");
                return;
            }
            else
            {
                // loop the search till don't find the loc 
                temp = temp->next;              
            }
        }
    }
    else if (currentnode == NULL)
    {
        printf("Error in linkedlist creation\n");
        return;
    }
}
static void delete_node(int num, struct Node **currentnode)
{
    // first position delete
    int pos = 0;
    // copy of address
    struct Node *temp = *currentnode , *prev;
    if (temp != NULL)
    {
    while (temp != NULL)
        {

            pos++;
            if (temp->employee_id == num)   // search the id
            {
                if (pos == 1)
                {
                    // delete the node if found at first loc
                    goto firstnodedelete;
                }
                else
                {
                    printf("Node found..\n");
                    prev->next = temp->next;
                    free(temp);  // Free memory
                    return;  
                }
            }
            else if(temp == NULL)
            {

                printf("ID not found in linkedlist\n");
            }
            else
            {
                // loop the search till don't find the loc
                prev = temp; 
                temp = temp->next;              
            }
        }
    }
    else if (currentnode == NULL)
    {
        printf("Error in linkedlist creation\n");
    }
firstnodedelete:

    *currentnode = temp->next;
    free(temp);
}
void linkedlistoperations(int op, int num)
{
    switch (op)
    {
    case INSERTING:

        put = multiple_node(num, put);
        print_data(put);
        insert = true;
        break;

    case DELETE:

        delete_node(num, &put);
        print_data(put);
        break;

    case SEARCH:

        search_node(num, put);
        break;

    case APPEND:

        put = multiple_node(num, put);
        print_data(put);
        break;

    default:
        break;
    }
}
