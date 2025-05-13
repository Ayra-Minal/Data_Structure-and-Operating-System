//SCAN_disk_scheduling
#include<stdio.h>
#include<stdlib.h>
void main()
{
    int i,j,k,n=0,m=0,s,max,temp,seek=0,head,diff;
    printf("enter max range of disc: ");
    scanf("%d",&max);
    max--;
    printf("enter initial head position: ");
    scanf("%d",&head);
    printf("number of requests: ");
    scanf("%d",&s);
    int a[s+2],b[s+2],c[s+2];
    printf("enter the queue of disk position: ");
    for(i=1;i<=s;i++)
    {
        scanf("%d",&temp);
        if(temp>=head)
        {
            c[n]=temp;
            n++;
        }
        else
        {
            b[m]=temp;
            m++;
        }
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(c[j]>c[j+1])
            {
                temp=c[j];
                c[j]=c[j+1];
                c[j+1]=temp;
            }
        }
    }
    for(i=0;i<m-1;i++)
    {
        for(j=0;j<m-i-1;j++)
        {
            if(b[j]<b[j+1])
            {
                temp=b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
            }
        }
    }
    a[0]=head;
    for(i=1,j=0;j<n;i++,j++)
    {
        a[i]=c[j];
    }
    a[i]=max;
    for(i=n+2,j=0;j<m;i++,j++)
    {
        a[i]=b[j];
    }
    for(i=0;i<s+1;i++)
    {
        diff=abs(a[i+1]-a[i]);
        seek+=diff;
        printf("%d ->",a[i]);
    }
    printf("%d",a[s+1]);
    printf("\n total seek time =%d\n",seek);
    printf("\n avg seek time=%f",(float)seek/s);
}
