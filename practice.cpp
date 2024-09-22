# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

void insertion(int [],int);
void bubble(int [],int);
void quick(int [],int,int);
void selection(int [],int);
void split(int [],int,int);
void merge(int [],int,int,int);
void count(int [],int);
void radix(int [],int);

int main()
{
    struct timeval v1,v2;
    struct timezone z1,z2;
    int n=10;
    int arr[n];

    // for(int i=0; i<n; i++)
    // {
    //     arr[i] = i+1;
    // } // Best Case

    for(int i=0; i<n; i++)
    {
        arr[i] = rand()%n;
        printf("%d\n",arr[i]);
    }

    // for(int i=n-1; i>=0; i--)
    // {
    //     arr[i] = i+1;
    // }  // Worst case

    printf("\n");
    gettimeofday(&v1,&z1);
    // insertion(arr,n);
    // bubble(arr,n);
    // quick(arr,0,n-1);
    // selection(arr,n);
    // split(arr,0,n-1);
    // count(arr,n);
    radix(arr,n);
    
    gettimeofday(&v2,&z2);

    for(int i=0; i<n; i++)
    {
        printf("%d\n",arr[i]);
    }
    printf("\n\n\n%d",v2.tv_usec-v1.tv_usec);
    return 0;
}

void insertion(int arr[],int n)
{
    for(int i=1; i<n; i++)
    {
        int j=i-1;
        int key = arr[i];
        while(key<arr[j] && j>=0)
        {
            arr[j+1] = arr[j];
            j--; 
        }
        arr[j+1]=key;
    }
}

void bubble(int arr[],int n)
{
    int e=0;
    for(int i=0; i<n-1; i++)
    {
        e=0;
        for(int j=0; j<n-i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                e++;
            }
        }
        if(e==0)
        {
            break;
        }
    }
}

void quick(int arr[],int lb,int ub)
{
    if(lb<ub)
    {
        
        int left = lb;
        int right = ub+1;
        int key = arr[left];

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

            if(right<left)
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
        arr[lb] = arr[right];
        arr[right] = key;

        quick(arr,lb,right-1);
        quick(arr,right+1,ub);
    }
}

void selection(int arr[],int n)
{
    for(int i=0; i<n-1; i++)
    {
        int min=i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j]<arr[min])
            {
                min = j;
            }
        }
        if(i!=min)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
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

void merge(int arr[],int first,int second, int third)
{
    int i=first,j=second,k=0;
    int temp[third-first+1];

    while(i<second && j<=third)
    {
        if(arr[i]<arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i!=second)
    {
        temp[k] = arr[i];
        i++;
    }
    while(j<=third)
    {
        temp[k] = arr[j];
        j++;
    }

    for(int l=first; l<=third; l++)
    {
        arr[l] = temp[l-first];
    }
}

void count(int arr[],int n)
{
    int max = arr[0];
    int a[n];
    for(int i=1; i<n; i++)
    {
        if(max<arr[i])
        {
            max = arr[i];
        }
    }
    int temp[max+1];
    for(int i=0; i<=max; i++)
    {
        temp[i] = 0;
    }

    for(int i=0; i<n; i++)
    {
        temp[arr[i]]++;
    }
    
    for(int i=1; i<=max; i++)
    {
        temp[i]+=temp[i-1];
    }
    
    for(int i=n-1; i>=0; i--)
    {
        a[temp[arr[i]]-1] = arr[i];
        temp[arr[i]]--;
    }
    
    for(int i=0; i<n; i++)
    {
        arr[i] = a[i];
    }
}

void radix(int arr[],int n)
{
    int max=arr[0];
    for(int i=1; i<n; i++)
    {
        if(max<arr[i])
        {
            max = arr[i];
        }
    }
    
    int pass=0;
    while(max!=0)
    {
        max = max/10;
        pass++;
    }
    
    int bk[10][n];
    int divisor=1,r;

    for(int i=0; i<pass; i++)
    {
        int bucket[10]={0};
        for(int j=0; j<n; j++)
        {
            r = (arr[j]/divisor)%10;
            bk[r][bucket[r]] = arr[j];
            bucket[r]++;
        }
        int l=0;
        for(int j=0; j<10; j++)
        {
            for(int k=0; k<bucket[j]; k++)
            {
                arr[l] = bk[j][k];
                l++;
            }
        }
        divisor*=10;
    }
}