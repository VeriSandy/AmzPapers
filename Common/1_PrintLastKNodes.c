/*
Ideas -- 
1. Reverse the list and print first k nodes.
2. Recursively iterate the list and while returning print the nodes, keep track the number of nodes.
3. Have all nodes in stack and pop k nodes.
4. find out the kth node from last and from here last k nodes can be printedin reverse order.
*/

//Implemented 2nd one

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{   
    struct node *next;
    int data;
}NODE;

void NewNode(NODE **head, int data)
{
    NODE *temp = malloc(sizeof(NODE));
    temp->next = *head;
    temp->data = data ;
    *head = temp;
    return;
}

void PrintList(NODE *head)
{
    while(head)
    {
        printf("%d  ", head->data);
        head = head->next;
    }   
    printf("\n");
    return;
}

void PrintList(NODE *head)
{
    while(head)
    {
        printf("%d  ", head->data);
        head = head->next;
    }   
    printf("\n");
    return;
}

void PrintLastKNodes(NODE *head, int *c)
{
    if(!head) return;
    
    PrintLastKNodes(head->next, c);
    if(*c > 0)
    {   
        printf("%d ", head->data);
        *c = *c - 1;
    }
    return;
}

int main()
{
    NODE *head = NULL;

    NewNode(&head, 50);
    NewNode(&head, 40);
    NewNode(&head, 30);
    NewNode(&head, 20);
    NewNode(&head, 10);

    PrintList(head);
    int k = 0;
    PrintLastKNodes(head, &k);
    printf("\n");
    return 0;
}

