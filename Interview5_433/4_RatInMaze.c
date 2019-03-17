//Rat in a Maze | Backtracking-2
//https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/

/*
Ideas -- 

Naive Solution - Generate all the paths from source to destination and check one by one if any of them satisfy the constraint

BackTraking solution - 
Try to move on each possible path and see if it leads to dest 
And if not try another path and so on untill you dont get to destination.
*/
#include "../../COMMON/common.h"
#define N 4
#define FALSE 0
#define TRUE 1

int IsSafe(int a[N][N], int x, int y)
{
    if(x >= 0 && y >= 0 && x < N && y < N && a[x][y] == 1)
        return TRUE;

    return FALSE;
}

int solveMazeUtil(int a[N][N], int x, int y, int sol[N][N])
{
    if(x == N-1 && y == N-1)
    {
        sol[x][y] = 1;
        return TRUE;
    }
   
    if(IsSafe(a, x, y))
    {
        sol[x][y] = 1;

        if(solveMazeUtil(a, x+1, y, sol) == TRUE)
            return TRUE;

        if(solveMazeUtil(a, x, y+1, sol) == TRUE)
            return TRUE;
   
        //If reached here, then it is quite simple to tell that this path will not take you to destination
        sol[x][y] = 0;
        return FALSE;
    }
    return FALSE;
}

void solveMaze(int a[N][N])
{
    int sol[N][N] = {0};

    if(solveMazeUtil(a, 0, 0, sol) ==  FALSE)
        printf("No Possible Solution\n");
    else
    {
        int i = 0, j = 0;
        for(; i < N ; i++)
        {
            for(j = 0; j < N ; j++)
                printf("%d  ", sol[i][j]);
            printf("\n");
        }
    }
    return;
}

int main()
{
    int maze[N][N]  =  { {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    solveMaze(maze);
    return 0;
}

