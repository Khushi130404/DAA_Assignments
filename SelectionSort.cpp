# include <stdio.h>
# include <sys/time.h>
# include <random>

void selectionSort(int [],int);

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
    selectionSort(arr,n);
    gettimeofday(&v2,&z2);


    for(int i=0; i<n; i++) //display loop
    {
        printf("\narr[%d]: %d",i+1,arr[i]);
    }

    printf("\nTime Difference : %ld",(v2.tv_usec-v1.tv_usec));
    return 0;
}

void selectionSort(int arr[],int n)
{
    for(int pass=0; pass<n-1; pass++)
    {
        int min_index = pass;
        for(int i=pass+1; i<n; i++)
        {
            if(arr[i]<arr[min_index])
            {
                min_index=i;
            }
        }
        if(min_index!=pass)
        {
            int temp=arr[pass];
            arr[pass]=arr[min_index];
            arr[min_index]=temp;
        }
    }
}