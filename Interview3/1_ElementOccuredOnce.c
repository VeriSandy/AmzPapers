//Elements that occurred only once in the array
//https://www.geeksforgeeks.org/elements-that-occurred-only-once-in-the-array/
/*
Given an array arr that has numbers appearing twice or once. The task is to identify numbers that occurred only once in the array.
Note: Duplicates appear side by side every time. Might be few numbers can occur one time and just assume this is a right rotating
 array (just say an array can rotate k times towards right). Order of the elements in the output doesn’t matter.
Input: arr[] = { 7, 7, 8, 8, 9, 1, 1, 4, 2, 2 }
Output: 9 4

Input: arr[] = {-9, -8, 4, 4, 5, 5, -1}
Output: -9 -8 -1
*/

/** Ideas -- 
    1. Sorting
    2. Hashing
    3. Use the problem statement
**/

#include "../../COMMON/common.h"
int part(int *a, int l, int h)
{   
    int i= l, index = l, p = a[h], temp = 0;
    
    while(i < h)
    {   
        if(a[i] < p)
        {   
            temp = a[i];
            a[i] = a[index];
            a[index] = temp;
            index++;
        }
        i++;
    }
    
    temp = a[h];
    a[h] = a[index];
    a[index] = temp;
    
    return index;
}

void Sort(int *a, int l, int h)
{   
    if(l < h)
    {   
        int p = part(a, l, h);
        Sort(a, l, p-1);
        Sort(a, p+1, h);
    }
    return;
}

void occurredOnceSorting(int *a, int n)
{
    int i = 0;
    Sort(a, 0, n-1);
    /*
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    */
    if(n == 1)
    {
        printf("%d\n", a[0]);
        return;
    }
    if(a[0] != a[1])
        printf("%d ", a[0]);

    for(i = 1; i < n-1; i++)
    {
        if(a[i] != a[i-1] && a[i] != a[i+1])
            printf("%d ", a[i]);
    }

    if(a[n-2] != a[n-1])
        printf("%d ", a[i]);

    printf("\n");
    return;
}


//store frequency of each element and print those which has one frequency
void occurredOnceHashing(int *a, int n)
{
    int i = 0, min = a[0], max = a[0], flag = 0;

    for(i = 1; i < n ; i++)
    {
        if(max < a[i])
            max = a[i];
        if(min > a[i])
            min = a[i];
    }

    int hash[max - min+1];

    for(i = 0; i <= max -min ; i++)
        hash[i] = 0;

    for(i = 0; i < n ; i++)
        hash[a[i]-min]++;

    for(i = 0; i <= max -min ; i++)
        if(hash[i] == 1)
        {
            printf("%d ", i+min);
            flag = 1;
        }

    if(!flag)
        printf("there is no element with one frequency");

    printf("\n");
    return;
}

//make use of the problem statement
void occurredOnce(int *a, int n)
{
    int i = 0;

    if(!n) return;

    if(n == 1)
    {
        printf("%d \n", a[0]);
        return;
    }

    if(a[n-1] == a[0])
    {
        n--;
        i++;
    }
    else
    {
        if(a[0] != a[1])
            printf("%d ", a[0]);
        i++;
    }

    for(; i < n -1; i++)
        if(a[i] != a[i-1] && a[i] != a[i+1])
            printf("%d ", a[i]);

    if(n > 1 && a[n-2] != a[n-1]) //need here n > 1 as in case of two elements amnd that too same, this is wrong 
        printf("%d ", a[n-1]);


    printf("\n");

    return;
}

int main()
{
    //int arr[] = { 7, 7, 8, 8, 9, 1, 4, 2, 3,3 }; 
    //int arr[] = { 1, 2}; 
    //int arr[] = { 1, 1}; 
    //int arr[] = { 1}; 
    //int arr[] = { 1, 2, 2, 3, 0}; 
    //int arr[] = { -1, 2, 2, 3, 4, 0}; 
    //int arr[] = {1, 1}; 
    //int arr[] = {1, 2, 1}; 
    int arr[] = {1, 2, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    occurredOnceSorting(arr, n); 
    occurredOnceHashing(arr, n);
    occurredOnce(arr, n);
    return 0;
}
