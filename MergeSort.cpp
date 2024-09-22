# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <random>

void merge(int[],int,int,int);
void split(int[],int,int);

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
    split(arr,0,n-1);
    gettimeofday(&v2,&z2);

    for(int i=0; i<n; i++) //display loop
    {
        printf("\narr[%d]: %d",i+1,arr[i]);
    }

    printf("\nTime Difference : %d",(v2.tv_usec-v1.tv_usec));
    return 0;
}


void merge(int arr[],int first,int second,int third)
{
    int temp[third-first+1];
    int i=first,j=second,k=0;

    while(i<second && j<=third)
    {
        if(arr[i]<arr[j])
        {
            temp[k]=arr[i];
            i++;
        }
        else
        {
            temp[k]=arr[j];
            j++;
        }
        k++;
    }
    if(i==second)
    {
        while(j<=third)
        {
            temp[k]=arr[j];
            k++;
            j++;
        }
    }
    else
    {
        while(i<second)
        {
            temp[k]=arr[i];
            i++;
            k++;
        }
    }
    for(int l=0; l<=third-first; l++)
    {
        arr[first+l]=temp[l];
    }
}

void split(int arr[],int start,int finish)
{
    if(finish>start)
    {
        int middle = (start+finish+1)/2;
        split(arr,start,middle-1);
        split(arr,middle,finish);
        merge(arr,start,middle,finish);
    }
}
