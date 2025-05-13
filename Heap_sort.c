//Heap_sort
#include<stdio.h>
void heapify(int a[],int i,int n)
{
    int larg=i;
    int lc=2*i+1;
    int rc=2*i+2;
    int temp;
    if(lc<n && a[lc]>a[larg])
        larg=lc;
    if(rc<n && a[rc]>a[larg])
        larg=rc;
    if(larg!=i)
    {
        temp=a[larg];
        a[larg]=a[i];
        a[i]=temp;
        heapify(a,larg,n);
    }    
}

void heapsort(int a[] ,int n)
{
    int temp,i;
    for(i=n/2-1;i>=0;i--)
        heapify(a,i,n);
    for(i=n-1;i>0;i--)
    {
        temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        heapify(a,0,i);
    }
}    

void main()
{
    int a[20],n,i;
    printf("enter no.of elements: " );
    scanf("%d",&n);
    printf("enter %d elements :",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    heapsort(a,n);
    printf("the sorted elements are: ");
    for(i=0;i<n;i++)
    {
        printf("%d \n",a[i]);
    }
}

