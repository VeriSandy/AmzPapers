//LRU Cache Implementation
//https://www.geeksforgeeks.org/lru-cache-implementation/

/*
Idea -- 
LRU -- Pages which are recenctly used keep them at front else keep them at back
If Cache is full then replace the page from back and get it in front
If not have new page at the front if that page doesnt exist in the memory, pull it from main memory.

Better use DLL, so deleting and insertion would be easy
*/

#include "../../COMMON/common.h"

typedef struct node
{   
    struct node *prev, *next;
    int pageNum;
}QNode;

typedef struct
{   
    int count;
    int cap;
    QNode *front, *rear;
}QUEUE;

typedef struct
{   
    int cap;
    QNode **arr;
}HASH;

QUEUE *createQueue(int cap)
{   
    QUEUE *q = malloc(sizeof(QUEUE));
    q->count = 0;
    q->cap = cap;
    q->front = q->rear = NULL;
    
    return q;
}

HASH *createHash(int cap)
{   
    HASH *h = malloc(sizeof(HASH));
    h->cap = cap;
    h->arr = malloc(sizeof(QNode *)*cap);

    int i = 0;
    for(i = 0; i < cap; i++)
        h->arr[i] = NULL;

    return h;
}

int IsQueueEmpty(QUEUE *q)
{
    return (!q->count?1:0);
}

int IsQueueFull(QUEUE *q)
{
    return (q->count == q->cap?1:0);
}

void DeQueue(QUEUE *q)
{
    QNode *temp = NULL;

    if(IsQueueEmpty(q))
            return;
    if(q->front == q->rear)
    {
        temp = q->front;
        q->front = q->rear = NULL;
    }
    else
    {
        temp = q->rear;
        q->rear->prev->next = NULL;
        q->rear = q->rear->prev;
        temp->prev = NULL;
    }

    free(temp);
    temp = NULL;
    q->count--;
    return;
}

void EnQueue(QUEUE *q, HASH *h, int page)
{
    if(IsQueueFull(q))
    {
        h->arr[q->rear->pageNum] = NULL;
        DeQueue(q);
    }
    QNode *temp = malloc(sizeof(QNode));

    temp->pageNum= page;
    temp->prev = NULL;
    temp->next = q->front;
    if(q->front == NULL)
        q->rear = temp;
    else
        q->front->prev = temp;

    q->front = temp;
    q->count++;
    h->arr[page] = temp;

    return;
}

void ReferencePage(QUEUE *q, HASH *h, int page)
{
    QNode *node = h->arr[page];

    if(node == NULL)//if page is not there in the cache
        EnQueue(q, h, page);
    else if(q->front && q->front != node)
    {
        node->prev->next = node->next;
        if(node->next)
            node->next->prev =  node->prev;

        //take care if node is last node so change the q->rear also
        if(node->next == NULL)
            q->rear = node->prev;

        node->next = q->front;
        node->prev = NULL;
        q->front->prev = node;
        q->front = node;
    }

    return;
}

int main()
{
    QUEUE* q = createQueue( 4 );
    HASH* hash = createHash( 10 );

    ReferencePage( q, hash, 1);
    ReferencePage( q, hash, 2);
    ReferencePage( q, hash, 3);
    ReferencePage( q, hash, 1);
    ReferencePage( q, hash, 4);
    ReferencePage( q, hash, 5);

    printf ("%d ", q->front->pageNum);
    printf ("%d ", q->front->next->pageNum);
    printf ("%d ", q->front->next->next->pageNum);
    printf ("%d ", q->front->next->next->next->pageNum);

    printf("\n");

    return 0;
}
