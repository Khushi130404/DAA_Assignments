# include <stdio.h>
# include <sys/time.h>
# include <random>

void quickSort(int [],int,int);

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
    quickSort(arr,0,n-1);
    gettimeofday(&v2,&z2);

    for(int i=0; i<n; i++) //display loop
    {
        printf("\narr[%d]: %d",i+1,arr[i]);
    }

    printf("\nTime Difference : %d",(v2.tv_usec-v1.tv_usec));
    return 0;
}

void quickSort(int arr[],int lb,int ub)
{
    if(lb<ub)
    {
        int key=arr[lb];
        int left=lb;
        int right=ub+1;

        while(1)
        {
            left++;
            while(key>arr[left])
            {
                left++;
            }
            right--;
            while(key<arr[right])
            {
                right--;
            }
            if(left<right)
            {
                int temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
            }
            else
            {
                break;
            }
        }
        arr[lb]=arr[right];
        arr[right]=key;

        quickSort(arr,lb,right-1);
        quickSort(arr,right+1,ub);
    }
}

