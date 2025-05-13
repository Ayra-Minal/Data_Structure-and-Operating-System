//Merge_sortt

#include <stdio.h>
void main()
{
    int a[20],beg,end,n,i;
    printf("enter no.of elements: " );
    scanf("%d",&n);
    printf("enter %d elements :",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    beg=0;
    end=n-1;
    mergesort(a,beg,end);
    printf("the sorted elements are: ");
    for(i=0;i<n;i++)
    {
        printf("%d \n",a[i]);
    }
}
void mergesort(int a[],int beg,int end)
{
    if(beg<end)
    {
        int mid=(beg+end)/2;
        mergesort(a,beg,mid);
        mergesort(a,mid+1,end);
        simple_merge(a,beg,mid+1,end);
    }
}

void simple_merge(int a[],int f,int s,int t)
{
    int i,j,k,temp[40];
    i=f,j=s,k=0;
    while(i<s && j<=t)
    {
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }
    while(i<s)
        temp[k++]=a[i++];
    while(j<=t)    
        temp[k++]=a[j++];
    for(i=f,k=0;i<=t; )    
        a[i++]=temp[k++];
}
