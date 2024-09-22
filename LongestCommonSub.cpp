# include <stdio.h>
# include <string.h>
# define x 50
# define y 50


int lcs(int,int,char [],char [],int[x][y]);
void printLCS(int,int,char [],char [],int [x][y]);
int max(int,int);
int temp = 0;

int main()
{
    char a[50],b[50];
    printf("\n1st String : ");
    gets(a);
    printf("\n2nd String : ");
    gets(b);
    int memo[x][y];
    for(int i=0; i<=strlen(a); i++)
    {
        for(int j=0; j<=strlen(b); j++)
        {
            memo[i][j] = -1;
        }
    }
    int max = lcs(strlen(a),strlen(b),a,b,memo);
    printf("Max : %d",max);
    printf("\n");
    printLCS(strlen(a),strlen(b),a,b,memo);
    return 0;
}

//  Line glass cutting , assembly line shceduling

int max(int a,int b)
{
    int mx = (a>b) ? a : b;
    return mx;
}

int lcs(int i,int j,char a[],char b[],int memo[x][y])
{
    if(memo[i][j]!=-1)
    {
        return memo[i][j];
    }
    if(i==0 || j==0)
    {
        memo[i][j]=0;
    }
    else if(a[i-1]==b[j-1])
    {
        memo[i][j] = lcs(i-1,j-1,a,b,memo)+1;
        
    }
    else
    {
        memo[i][j] = max(lcs(i-1,j,a,b,memo),lcs(i,j-1,a,b,memo));
    }
    return memo[i][j];
}

void printLCS(int i,int j,char a[],char b[],int memo[x][y])
{
    if(i==0 || j==0)
    {
        return;
    }
    if(a[i-1]==b[j-1])
    {
        printLCS(i-1,j-1,a,b,memo);
        printf("%c",a[i-1]);
    }
    else if(memo[i-1][j] > memo[i][j-1])
    {
        printLCS(i-1,j,a,b,memo);
    }
    else
    {
        printLCS(i,j-1,a,b,memo);
    }
}

// void printLCS2(int i,int j,char a[],char b[],int memo[x][y])
// {
//     if(i==0 || j==0)
//     {
//         return;
//     }
//     if(a[i-1]==b[j-1])
//     {
//         printLCS(i-1,j-1,a,b,memo);
//         printf("%c",a[i-1]);
//     }
//     else if(memo[i-1][j] >= memo[i][j-1])
//     {
//         printLCS(i-1,j,a,b,memo);
//     }
//     else
//     {
//         printLCS(i,j-1,a,b,memo);
//     }
// }