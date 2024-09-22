# include <stdio.h>
# include <sys/time.h>

long factRec(int);
long factIteration(int);

int main()
{
    struct timeval v1,v2;
    struct timezone z1,z2;
    gettimeofday(&v1,&z1);
    printf("\nFactorial : %d", factRec(10));
    //printf("\nFactorial : %d", factIteration(10));
    gettimeofday(&v2,&z2);
    printf("\nTime Difference : %d",(v2.tv_usec-v1.tv_usec));
    return 0;
}

long factIteration(int n)
{
    long fact=1;
    while(n!=0)
    {
        fact*=n;
        n--;
    }
    return fact;
}

long factRec(int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return n*factRec(n-1);
    }
}