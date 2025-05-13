//FCFS_disk_scheduling
#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n,i,seek=0,diff;
    printf("enter size of queue: ");
    scanf("%d",&n);
    int a[n+1];
    printf("enter queue values: ");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter initial head position: ");
    scanf("%d",&a[0]);
    printf("movement of cylinder: ");
    for(i=0;i<n;i++)
    {
        diff=abs(a[i+1]-a[i]);
        seek+=diff;
        printf("%d -> ",a[i]);
    }
    printf("%d",a[n]);
    printf("\n total seek time= %d \n",seek);
    printf("avg seek time =%f\n",(float)seek/n);
}
