# include <stdio.h>
# include <sys/time.h>
# include <random>

void createHeap(int[],int);
void HeapSort(int[],int);

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
    HeapSort(arr,n);
    gettimeofday(&v2,&z2);


    for(int i=0; i<n; i++) //display loop
    {
        printf("\narr[%d]: %d",i+1,arr[i]);
    }

    printf("\nTime Difference : %ld",(v2.tv_usec-v1.tv_usec));
    return 0;
}

void createHeap(int arr[],int n)
{
    int q=1;
    int key,i,j;

    while(q<n)
    {
        i=q;
        key=arr[i];
        j=i/2;

        while(i>0 && key>arr[j])
        {
            arr[i]=arr[j];
            i=j;
            j=i/2;
        }
        arr[i]=key;
        q++;
    }
}

void HeapSort(int arr[],int n)
{
    createHeap(arr,n);
    int i,j,key,q=n-1;

    while(q>0)
    {
        int temp=arr[0];
        arr[0]=arr[q];
        arr[q]=temp;

        i=0;
        key=arr[0];
        j=1;

        if(j+1<q && arr[j+1]>arr[j])
        {
            j++;
        }

        while(j<q && key<arr[j])
        {
            arr[i]=arr[j];
            i=j;
            j=2*i+1;

            if(j+1<q && arr[j+1]>arr[j])
            {
                j++;
            }
            else if(j>n-1)
            {
                j=n-1;
            }
            arr[i]=key;
        }
        q--;
    }
}
