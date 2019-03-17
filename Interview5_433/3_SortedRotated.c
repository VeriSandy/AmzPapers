//Search an element in a sorted and rotated array
//https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/

/*
    Use Binary Search here
    Though it is rotated still some part of it will be sorted
    so check which part is sorted and look for the key
*/

#include "../../COMMON/common.h"

int Search(int *a, int n, int k)
{
    if(n)
    {
        int l = 0;
        int h = n-1;
        int mid =  0;

        while(l <= h)
        {
            mid = (l+h)/2;
            if(a[mid] == k)
                return mid;
   
            if(a[l] <= a[mid]) //if first half is sorted
            {
   
                if(a[l] <= k && k <= a[mid])
                    h = mid -1;
                else
                    l = mid +1;
            }
            else//if other part is sorted
            {
                if(k >= a[mid] && k <= a[h])
                    l = mid +1;
                else
                    h = mid -1;
            }
        }
    }
    return -1;
}

int main()
{
  int arr1[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
  int n = sizeof(arr1)/sizeof(arr1[0]);
  int key = 3;
  printf("Index of the element is : %d\n", Search(arr1, n, key));
  return 0;
}
