# include <stdio.h>
# include <sys/time.h>

int fiboRec(int);
int fiboInteration(int);

int main()
{
    struct timeval v1,v2;
    struct timezone z1,z2;
    gettimeofday(&v1,&z1);
    //printf("\nFibonacci : %d",fiboRec(30));
    printf("\nFibonacci : %d",fiboInteration(30));
    gettimeofday(&v2,&z2);
    printf("\nTime Difference : %d",(v2.tv_usec-v1.tv_usec));
    return 0;
}

int fiboRec(int n)
{
    if(n==1)
    {
        return 0;
    }
    else if(n==2)
    {
        return 1;
    }
    else
    {
        return fiboRec(n-1)+fiboRec(n-2);
    }
}

int fiboInteration(int n)
{
    
    if(n==1)
    {
        return 0;
    }
    else if(n==2)
    {
        return 1;
    }
    else
    {
        int a=0,b=1,c;
        for(int i=2; i<n; i++)
        {
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
}