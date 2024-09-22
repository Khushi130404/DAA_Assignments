# include <stdio.h>
# define max_choice 5
# define max_capacity 24

int diamond[][2] = {{2,3},{3,6},{5,7},{6,12},{8,17}};
int memo[max_choice+1][max_capacity+1];

int max(int,int);
int knapsack(int,int);

int main()
{
    int total_choice=5;
    int capacity;
    printf("\nEnter the total capacity : ");
    scanf("%d",&capacity);
    for(int i=0; i<=max_choice; i++)
    {
        for(int j=0; j<=max_capacity; j++)
        {
            memo[i][j] = -1;
        }
    }
    int dia = knapsack(total_choice,capacity);
    printf("Total prize : %d\n",dia);
    return 0;
}

int max(int n, int m)
{
    if(n>m)
    {
        return n;
    }
    else
    {
        return m;
    }
}

int knapsack(int i,int j)
{
    if(memo[i][j]!=-1)
    {
        return memo[i][j];
    }
    if(j==0 || i==0)
    {
        return 0;
    }
    else if(diamond[i-1][0]<=j)
    {
        int mx = max(knapsack(i-1,j-diamond[i-1][0])+diamond[i-1][1],knapsack(i-1,j));
        memo[i][j] = mx;
        return mx;
    }
    else
    {
        int mx = knapsack(i-1,j);
        memo[i][j] = mx;
        return mx;
    }
}