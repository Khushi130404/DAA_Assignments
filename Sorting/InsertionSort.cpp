# include <stdio.h>
# include <sys/time.h>
# include <random>

void insertionSort(int[],int);

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
    insertionSort(arr,n);
    gettimeofday(&v2,&z2);

    for(int i=0; i<n; i++) //display loop
    {
        printf("\narr[%d]: %d",i+1,arr[i]);
    }

    printf("\nTime Difference : %d",(v2.tv_usec-v1.tv_usec));
    return 0;
}

void insertionSort(int arr[],int size)
{
    for(int i=0 ; i<size; i++)
    {
        int key=arr[i];
        int j;
        for(j=i-1; j>=0; j--)
        {
            if(key<arr[j])
            {
                arr[j+1]=arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j+1]=key;
    }
}
