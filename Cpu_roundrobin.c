//Round-robin_cpu_scheduling
#include <stdio.h>
int q[100];
int f=-1;
int r=-1;
int insert(int n)
{
    if(f==-1)
        f=0;
    r=r+1;
    q[r]=n;
}
int delete()
{
    int n=q[f];
    f=f+1;
    return n;
}
void main()
{
    int n,i,p,tq,t=0;
    float twt=0,ttat=0;
    printf("enter number of process: ");
    scanf("%d",&n);
    int a[n][5],bt[10],exist[10]={0};
    printf("--enter arrival time and burst time of each process--\n");
    for(i=0;i<n;i++)
    {
        printf("\nProcess ID: ");
        scanf("%d",&a[i][0]);
        printf("\nArrival time of %d : ",a[i][0]);
        scanf("%d",&a[i][1]);
        printf("\nBurst time of %d: ",a[i][0]);
        scanf("%d",&a[i][2]);
        bt[i]=a[i][2];
    }
    printf("\nenter time quantun: ");
    scanf("%d",&tq);
    insert(0);
    exist[0]=1;
    while(f<=r)
    {
        p=delete();
        if(a[p][2]>=tq)
        {
            a[p][2]-=tq;
            t+=tq;
        }
        else
        {
            t+=a[p][2];
            a[p][2]=0;
        }
        for(i=0;i<n;i++)
        {
            if(exist[i]==0 && a[i][1]<=t)
            {
                insert(i);
                exist[i]=1;
            }
        }
        if(a[p][2]==0)
        {
            a[p][4]=t-a[p][1];  //a[p][4]=turn around time
            a[p][3]=a[p][4]-bt[p]; //a[p][3]=waiting time 
            ttat+=a[p][4];
            twt+=a[p][3];
        }
        else
        {
            insert (p);
        }
    }
    printf("\nP.NO.\tAT\t BT\t TAT\t WT");
    for (i=0;i<n;i++)
    {
        printf("\n%d\t%d\t%d\t%d\t%d",a[i][0],a[i][1],bt[i],a[i][4],a[i][3]);
    }
    printf("\n average turn around time is %f ",ttat/n);
    printf("\n average waiting time is %f ",twt/n);
}
  
