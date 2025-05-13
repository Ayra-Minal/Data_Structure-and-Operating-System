//Quick_sort

#include <stdio.h>
void qsort(int a[],int start,int end);
int partition (int a[],int start,int end);

void main()
{
    int a[20],start,end,n,i;
    printf("enter no.of elements: " );
    scanf("%d",&n);
    printf("enter %d elements :",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    start=0;
    end=n-1;
    qsort(a,start,end);
    printf("the sorted elements are: ");
    for(i=0;i<n;i++)
    {
        printf("%d \n",a[i]);
    }
}
void qsort(int a[],int start,int end)
{
    if(start<end)
    {
        int pos=partition (a,start,end);
        qsort(a,start,pos-1);
        qsort(a,pos+1,end);
    }
}
int partition (int a[],int start,int end)
{
    int i,j,temp,key;
    key=a[start];
    i=start+1;
    j=end;
    do
    {
        while(i<j && a[i]<key)
            i++;
        while (j>start && a[j]>key)
            j--;
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);
    temp=a[start];
    a[start]=a[j];
    a[j]=temp;
    return j;
}
