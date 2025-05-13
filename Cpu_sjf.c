//SJF_cpu_scheduling
#include <stdio.h>
void swap(int *a, int *b) 
{
 int temp;
 temp = *a;
 *a = *b;
 *b = temp;
}

int main()
{
    int i,j,n,min,current;
    float ttat=0,twt=0;
    printf("enter number of processes: ");
    scanf("%d",&n);
    int a[n][5];
    printf("enter at and bt: ");
    for(i=0;i<n;i++)
    {
        printf("process id: ");
        scanf("%d",&a[i][0]);
        printf("at of %d: ",a[i][0]);
        scanf("%d",&a[i][1]);
        printf("bt of %d: ",a[i][0]);
        scanf("%d",&a[i][2]);
    }
    //swapping based on at and bt
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j][1]>a[j+1][1])
            {
                swap(&a[j][0],&a[j+1][0]);
                swap(&a[j][1],&a[j+1][1]);
                swap(&a[j][2],&a[j+1][2]);
            }
            if(a[j][1]==a[j+1][1] && a[j][2]>a[j+1][2])
            {
                swap(&a[j][0],&a[j+1][0]);
                swap(&a[j][1],&a[j+1][1]);
                swap(&a[j][2],&a[j+1][2]);
            }
        }
    }
    //calcu of 1st row
    a[0][3]=a[0][1];
    a[0][4]=a[0][2]-a[0][1];
    current=a[0][4];
    twt+=a[0][3];
    ttat+=a[0][4];
    //sorting by min burst time
    for(i=1;i<n;i++)
    {
        min=a[i][2];
        for(j=i+1;j<n;j++)
        {
            if(min>a[j][2] && current>a[j][1])
            {
                min=a[j][2];
                swap(&a[i][0], &a[j][0]);
                swap(&a[i][1], &a[j][1]);
                swap(&a[i][2], &a[j][2]);
            }
        }
        //calcu
        a[i][3]=current-a[i][1];//wt
        twt+=a[i][3];
        current+=a[i][2];
        a[i][4]=current-a[i][1];//tat=ct-at
        ttat+=a[i][4];
    }
    printf("P\tat\tbt\twt\ttat\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n",a[i][0],a[i][1],a[i][2],a[i][3],a[i][4]);
    }
    printf("\nAverage Turnaround time = %f", ttat / n);
     printf("\nAverage Waiting time = %f", twt / n);
     return 0;
}
