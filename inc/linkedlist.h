#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

#define INSERTING 0
#define DELETE 1
#define SEARCH 2
#define APPEND 3

enum
{
  appendll = 1,
};

struct Node
{
    int employee_id;
    char *employee_name;
    struct Node *next;
};

typedef struct
{
    int noofemployee;
}employee_count;

void linkedlistoperations(int op, int num);
extern int nodes;

#endif