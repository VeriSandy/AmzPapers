//Find the number of islands | Set 1 (Using DFS)
//https://www.geeksforgeeks.org/find-number-of-islands/

/*
Use DFS concept, find out how many are reachable in one go or how much land can be covered in one go, that would count as 1
*/

#include "../common.h"
#define R 5
#define C 5

void countIslandsUtil(int i, int j, int a[R][C], int vis[R][C])
{
    int k = 0;

    int Xmove[] = {-1, 0, 1, 1, 1, 0, -1, -1};
    int Ymove[] = {-1, -1, -1, 0, 1, 1, 1, 0};

    vis[i][j] = 1;

    for(k = 0; k < 8 ; k++)
    {
        int x = i + Xmove[k];
        int y = j + Ymove[k];

        if(x >= 0 && x < R && y >= 0 && y < C && !vis[x][y] && a[i][j] == 1)
            countIslandsUtil(x, y, a, vis);
    }
    return;
}

int countIslands(int a[R][C])
{
    int vis[R][C] = {0};
    int i = 0, j = 0;
    int count = 0;
   

    for(i = 0; i < R; i++)
        for(j = 0; j < C; j++)
            if(!vis[i][j] && a[i][j] == 1)
            {
                countIslandsUtil(i, j, a, vis);
                count++;
            }

    return count;
}

int main()
{
    int M[R][C] =
        {
            {1, 1, 0, 0, 0},
            {0, 1, 0, 0, 1},
            {1, 0, 0, 1, 1},
            {0, 0, 0, 0, 0},
            {1, 0, 1, 0, 1}
        };
    printf("Number of islands is: %d\n", countIslands(M));
    return 0;
}
