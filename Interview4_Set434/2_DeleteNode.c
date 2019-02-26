/Delete a node in a Doubly Linked List
//https://www.geeksforgeeks.org/delete-a-node-in-a-doubly-linked-list/
//Write a function to delete a given node in a doubly linked list.
/*
Possible scenarios - 

Delete a node when - 
    1. If list is empty
    2. Delete the only node
    3. Delete the non exiting node
    4. Delete first node
    5. Delete last node
    6. Delete any middle node
*/
#include "../../COMMON/common.h"
typedef struct node
{
    int data;
    struct node *prev, *next;
}DLIST;

void InsertNode(DLIST **head, int data)
{
    DLIST *temp = malloc(sizeof(DLIST));
    temp->data = data;
    temp->next = *head;
    temp->prev = NULL;
    if(*head)
        (*head)->prev = temp;

    *head = temp;
    return;
}

void PrintList(DLIST *head)
{
    while(head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void DelNode(DLIST **head, DLIST *node)
{
    if(*head == NULL || node == NULL) return;

    if(*head == node) //for the first node -or- the only node to be deleted
        *head = (*head)->next;

    if(node->next != NULL)//if node to be deleted is not last node then change previous pointer of next node
        node->next->prev = node->prev;

    if(node->prev != NULL)//if node to be deleted is not first node then change the next pointer of prev node
        node->prev->next = node->next;

    free(node);
    node = NULL;

    return;
}


int main()
{
    DLIST *head = NULL;
    //InsertNode(&head, 90);
    //InsertNode(&head, 80);
    InsertNode(&head, 70);
    InsertNode(&head, 60);
    InsertNode(&head, 50);

    PrintList(head);
    //DelNode(&head, head);
    DelNode(&head, head->next);
    DelNode(&head, head->next);
    //DelNode(&head, head);
    //DelNode(&head, head);
    PrintList(head);

    return 0;
}

