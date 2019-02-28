
//Count distinct elements in every window of size k
//https://www.geeksforgeeks.org/count-distinct-elements-in-every-window-of-size-k/
//Count distinct in first window of k elements and then for next elements keep adding next element one by one and keep removing the elements which are not there in that window.
#include "../../COMMON/common.h"

void countDistinctInWindow(int *a, int k, int n)
{   
    int min = 0, max = 0, i = 0;
    
    for(i = 0 ; i < n ; i++)
    {   
        if(min > a[i])
            min = a[i];
        if(max < a[i])
            max = a[i];
    }
    
    int hash[max - min +1];
    int count = 0;
    
    for(i = 0 ; i <= max - min ; i++)
        hash[i] = 0;
    
    for(i = 0 ; i < k ; i++)
    {   
        if(!hash[a[i] - min])
            count++;
        hash[a[i] - min]++;
    }
    
    printf("%d ", count);
    for(i = k; i < n ; i++)
    {   
        int temp = a[i-k] - min;
        hash[temp]--;
        if(!hash[temp])//Reduce count only if frequency of item is zero now as same element can be there in some other window and if that is then we need take into that account
            count--;
        
        if(!hash[a[i] - min])
            count++;
        
        hash[a[i] - min]++;
        
        printf("%d ", count);
    }
    printf("\n");
    return ;

}

int main()
{
    int arr[] = {1, 2, 1, 3, 4, 2, 3};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    countDistinctInWindow(arr, k, size);
    return 0;
}
