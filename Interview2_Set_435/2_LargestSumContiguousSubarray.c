//https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
//kadane's algorithm
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int LargestSum(int *a, int n)
{   
    int max_so_far = INT_MIN;
    int cur_max = 0;
    int i = 0;
    
    for(i = 0; i < n ; i++)
    {   
        cur_max = cur_max + a[i];
        if(cur_max < 0)
            cur_max = 0;
        
        if(cur_max > max_so_far)
            max_so_far = cur_max;
    }
    
    return max_so_far;
}

int max(int a, int b)
{
    return (a>b?a:b);
}


//This will take care of negative and positive numbers
//Additionally it will print, start and end of the subarray
int LargestSubArraySum(int *a, int n)
{
    int max_so_far = INT_MIN;
    int cur_max = 0;
    int i = 0, s = 0, e = 0, s1 = 0;
    for(i = 0; i < n ; i++)
    {
        //cur_max = max(a[i], cur_max+a[i]);
        if((cur_max + a[i]) < a[i])
        {
            cur_max = a[i];
            s1 = i;
        }
        else
            cur_max = cur_max + a[i];

        //max_so_far = max(max_so_far, cur_max);
        if(max_so_far < cur_max)
        {
            s = s1;
            e = i;
            max_so_far = cur_max;
        }
    }
    printf("start = %d and end = %d\n", s, e);
    return max_so_far;
}

int main()
{
    int a[] = {-3, -2, -4, -1, -2, -1, -5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = LargestSum(a, n);
    printf("%d\n", max_sum);
    max_sum = LargestSubArraySum(a, n);
    printf("%d\n", max_sum);
    return 0;
}
