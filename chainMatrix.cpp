# include <stdio.h>
# define m 50

int min(int,int);
int matrixMultiplication(int,int,int [],int [m][m]);

int main()
{
    int n;
    printf("\nEnter the number of matrix : ");
    scanf("%d",&n);
    int arr[n+1];
    int memo[m][m];

    for(int i=0; i<=n+1; i++)
    {
        for(int j=0; j<=n+1; j++)
        {
            memo[i][j] = -1;
        }
    }

    printf("Enter the order...\n\n");
    for(int i=0; i<=n; i++)
    {
        scanf("%d",&arr[i]);
    }

    int min = matrixMultiplication(1,n+1,arr,memo);
    printf("\nMin : %d",min);
    return 0;
}

int min(int l,int k)
{
    if(l<k)
    {
        return l;
    }
    else
    {
        return k;
    }
}

int matrixMultiplication(int i,int j,int arr[],int memo[m][m])
{
    if(memo[i][j]==-1)
    {
        if(i==j-1)
        {
            memo[i][j] = 0;
        }
        else
        {
            int mn=10000;
            for(int k=i+1; k<j; k++)
            {
                mn = min(mn,matrixMultiplication(i,k,arr,memo)+matrixMultiplication(k,j,arr,memo)+(arr[i-1]*arr[j-1]*arr[k-1]));
            }
            memo[i][j] = mn;
        }
    }
   return memo[i][j];
}