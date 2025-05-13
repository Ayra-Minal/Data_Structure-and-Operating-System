//CSCAN_disk_scheduling
#include<stdio.h>
#include<stdlib.h>
void main()
{
    int i,j,m=0,n=0,s,diff,head,temp,seek=0,max;
    printf("enter max range: ");
    scanf("%d",&max);
    max--;
    printf("\n enter head position: ");
    scanf("%d",&head);
    printf("total number of request?: ");
    scanf("%d",&s);
    int a[s+3],b[s+3],c[s+3];
    printf("enter disc values: ");
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
            if(b[j]>b[j+1])
            {
                temp=b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
            }
        }
    }
    
    a[0]=head;
    for(i=1,j=0;j<n;j++,i++)
    {
        a[i]=c[j];
    }
    a[i]=max;
    a[i+1]=0;
    for(i=n+3,j=0;j<m;i++,j++)
    {
        a[i]=b[j];
    }
    for(i=0;i<s+2;i++)
    {
        diff=abs(a[i+1]-a[i]);
        seek+=diff;
        printf("%d ->",a[i]);
    }
    printf("%d",a[s+2]);
    printf("\nTotal seek time is %d\n",seek);
    printf("Average seek time is %f\n",seek/(float)s);
}
