
//Print a given matrix in spiral form
//https://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/

/*
    Need 4 loop
    one for first row
    last column 
    last row
    first column 
    and so on
*/

#include "../../COMMON/common.h"
#define R 6
#define C 6

void spiralPrint(int a[R][C])
{
    int i = 0, k = 0, l = 0;
    int m = R, n = C;

    while(k < m && l < n)
    {
        for(i = l; i < n; i++)
            printf("%d ", a[k][i]);
        k++;

        for(i = k; i < m; i++)
            printf("%d ", a[i][n-1]);
        n--;
   
    //  printf("\n %d\n", n);
        if(k < m)
        {
            for(i = n-1; i >= l; i--)
                printf("%d ", a[m-1][i]);
            m--;
        }
        //printf("\n %d %d\n", m, l);
        if(l < n)
        {
            for(i = m-1; i >= k; i--)
                printf("%d ", a[i][l]);
            l++;
        }
    }
    printf("\n");
    return;
}

int main()
{
    int a[R][C] = { {1,  2,  3,  4,  5,  6},
        {7,  8,  9,  10, 11, 12},
        {13, 14, 15, 16, 17, 18},
        {19, 20, 21, 22, 23, 24},
        {25, 26, 27, 28, 29, 30},
        {31, 32, 33, 34, 35, 36}
    };

    spiralPrint(a);
    return 0;
}
