////https://www.geeksforgeeks.org/minimize-cash-flow-among-given-set-friends-borrowed-money/
/*
1) Compute the net amount for every person. The net amount for person ‘i’ can be computed be subtracting sum of all debts from sum of all credits.
2) Find the two persons that are maximum creditor and maximum debtor. Let the maximum amount to be credited maximum creditor be maxCredit and maximum amount to be debited from maximum debtor be maxDebit. Let the maximum debtor be Pd and maximum creditor be Pc.
3) Find the minimum of maxDebit and maxCredit. Let minimum of two be x. Debit ‘x’ from Pd and credit this amount to Pc
4) If x is equal to maxCredit, then remove Pc from set of persons and recur for remaining (n-1) persons.
5) If x is equal to maxDebit, then remove Pd from set of persons and recur for remaining (n-1) persons.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 3
int MinDebit(int *a)
{   
    int i = 1;
    int MinDebit = 0;
    for(;i <N ; i++)
        if(a[i] < a[MinDebit])
            MinDebit = i;
    return MinDebit;
}

int MaxCredit(int *a)
{   
    int i = 1;
    int MaxCredit = 0;
    for(;i <N ; i++)
        if(a[i] > a[MaxCredit])
            MaxCredit = i;
    return MaxCredit;
}

int Min(int a, int b)
{   
    return (a > b ? b:a);
}


void MinCashFlowUtil(int *a)
{
    int Credit = MaxCredit(a);
    int Debit = MinDebit(a);
    int min = Min(a[Credit], -a[Debit]);
   
    if(!a[Credit] && !a[Debit]) return;

    a[Credit] -= min;
    a[Debit] += min;

   
    printf("%d-->%d:%d\n", Debit, Credit, min);

    MinCashFlowUtil(a);
   
    return;
}

void minCashFlow(int g[][N])
{
    int *amnt = malloc(sizeof(int)*N);
    memset(amnt, 0x00, sizeof(int)*N);
    int i = 0, j = 0;

    for(i = 0; i < N ; i++)
    {
        for(j = 0; j < N ; j++)
            amnt[i] += g[j][i] - g[i][j];

        //printf("amnt[%d] = %d\n", i, amnt[i]);
    }
    MinCashFlowUtil(amnt);
    return;
}

int main()
{
    int graph[N][N] = { {0, 1000, 2000},
                        {0, 0, 5000},
                        {0, 0, 0},};

    minCashFlow(graph);
    return 0;
}

