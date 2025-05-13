//binary search

#include <stdio.h>
int binser(int a[],int n,int x);
void main()
{
    int a[20],key,n,i,result=0;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("enter %d elements: ",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter element to be searched : ");
    scanf("%d",&key);
    result=binser(a,n,key);
    if(result==0)
        printf("no such element ");
    else
        printf("element found at index %d .",result);
}

int binser(int a[],int n,int x)
{
    int top,mid,bot;
    top=0;
    bot=n-1;
    while(top<=bot)
    {
        mid=(top+bot)/2;
        if(a[mid]==x)
            return mid;
        else if(a[mid]<x)
            top=mid+1;
        else
            bot=mid-1;
    }
}
