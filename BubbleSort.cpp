# include <stdio.h>
# include <sys/time.h>
# include <random>

void bubbleSort(int [],int);

int main()
{
    int n;
    struct timeval v1,v2;
    struct timezone z1,z2;
    printf("\nEnter the number of elements: ");
    scanf("%d",&n);
    int arr[n];

    for(int i=0; i<n; i++) // Best Case
    {
        arr[i] = i+1;
    }
    for(int i=0; i<n; i++) // Average Case
    {
        arr[i] = rand()%n;
        printf("Info of arr[%d]: %d\n",i+1,arr[i]);
    }
    for(int i=0; i<n; i++) // Worst Case
    {
        arr[i] = n-i;
    }    

    gettimeofday(&v1,&z1);
    bubbleSort(arr,n);
    gettimeofday(&v2,&z2);


    for(int i=0; i<n; i++) //display loop
    {
        printf("\narr[%d]: %d",i+1,arr[i]);
    }

    printf("\nTime Difference : %ld",(v2.tv_usec-v1.tv_usec));
    return 0;
}

void bubbleSort(int arr[],int n)
{
    int exchg;
    for(int i=0; i<n; i++)
    {
        exchg=0;
        for(int j=0; j<n-i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
                exchg++;
            } 
        }
        if(exchg==0)
        {
            break;
        }
    } 
}