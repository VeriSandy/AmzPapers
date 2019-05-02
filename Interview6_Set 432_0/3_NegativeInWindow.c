//First negative integer in every window of size k
//https://www.geeksforgeeks.org/first-negative-integer-every-window-size-k/

/*
Use Window concept
*/

#include "../common.h"

typedef struct
{   
    int *q;
    int size, cap;
    int front, rear;
}QUEUE;

QUEUE *CreateQueue(int size)
{   
    QUEUE *que = malloc(sizeof(QUEUE));
    que->cap = size;
    que->size = 0;
    que->rear = -1;
    que->front = -1;
    que->q = malloc(sizeof(int)*size);
    return que;
}

void EnQueue(QUEUE *que, int data)
{   
    que->rear++;
    que->size++;
    que->q[que->rear] = data;   
    if(!que->rear) que->front = 0;
    return;
}

int DeQueue(QUEUE *que)
{   
    int data = que->q[que->front];
    que->front++;
    que->size--;
    if(!que->size)
    {   
        que->front = que->rear = -1;
    }
    return data;
}

void printFirstNegativeInteger(int *a, int n, int k)
{
    int i = 0;
    int p = 0;
    QUEUE *que = CreateQueue(k);

    for(i = 0; i < k; i++)
        if(a[i] < 0)
            EnQueue(que, i);

    while(i < n)
    {
        if(que->size)
        {
            p = que->q[que->front];
            printf("%d ", a[p]);
        }
        else
            printf("%d ", 0);

        while(que->size && que->q[que->front] < i-k+1)
              DeQueue(que);

        if(a[i] < 0)
            EnQueue(que, i);

        i++;
    }
    if(que->size)
    {
        p = que->q[que->front];
        printf("%d ", a[p]);
    }
    else
        printf("%d ", 0);

    printf("\n");
    return;
}

int main()
{
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    printFirstNegativeInteger(arr, n, k);
    return 0;
 }
 
 
