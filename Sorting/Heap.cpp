# include <stdio.h>
# include <sys/time.h>
# include <random>
# define size 10

void max_Heapify(int [],int,int);
void built_Heap(int []);
void Heap_Sort(int []);

int main()
{
    int arr[size];
    for(int i=0; i<size; i++)
    {
        arr[i] = rand()%size;
        printf("\narr[%d] : %d",i,arr[i]);
    }
    struct timeval v1,v2;
    struct timezone z1,z2;

    gettimeofday(&v1,&z1);
    Heap_Sort(arr);
    gettimeofday(&v2,&z2);
    printf("\n\n");
    for(int i=0; i<size; i++)
    {
        printf("\narr[%d] : %d",i,arr[i]);
    }
    printf("\n\n Time difference : %d",v2.tv_usec-v1.tv_usec);
    return 0;
}

void max_Heapify(int arr[],int i,int n)
{
    int l = 2*i;
    int r = 2*i+1;
    int max=i;

    if(l<n && arr[l]>arr[max])
    {
        max = l;
    }
    if(r<n && arr[r]>arr[max])
    {
        max = r;
    }

    if(max!=i)
    {
        int temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
        max_Heapify(arr,max,n);
    }
}

void built_Heap(int arr[])
{
    for(int i=(size-1)/2; i>=0; i--)
    {
        max_Heapify(arr,i,size);
    }
}

void Heap_Sort(int arr[])
{
    built_Heap(arr);

    for(int i=size-1; i>0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        max_Heapify(arr,0,i);
    }
}