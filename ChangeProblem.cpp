# include <stdio.h>
# define total_coin 6

int coin[] = {1,2,5,10,20,25};
int changeProblem(int,int,int [][total_coin+1]);
int min(int,int);

int main()
{
    int change;
    printf("\nEnter the change : ");
    scanf("%d",&change);
    int memo[change+1][total_coin+1];
    for(int i=0; i<=change; i++)
    {
        for(int j=0; j<=total_coin; j++)
        {
            memo[i][j] = -1;
        }
    }
    int min_coin = changeProblem(total_coin,change,memo);
    printf("\nMinimum coin : %d",min_coin);
    return 0;
}

int min(int n,int m)
{
    if(n<m)
    {
        return n;
    }
    else
    {
        return m;
    }
}

int changeProblem(int i,int j,int memo[][total_coin+1])
{
    if(memo[j][i]!=-1)
    {
        return memo[j][i];
    }
    if(j==0)
    {
        return 0;
    }
    else if(i==0)
    {
        return coin[5]+1;
    }
    else if(coin[i-1]<=j)
    {
        int mn = min(changeProblem(i-1,j,memo),changeProblem(i,j-coin[i-1],memo)+1);
        memo[j][i] = mn;
        return mn;
    }
    else
    {
        int mn = changeProblem(i-1,j,memo);
        memo[j][i] = mn;
        return mn;
    }
}
