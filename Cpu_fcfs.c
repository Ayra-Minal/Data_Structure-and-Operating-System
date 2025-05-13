//FCFS_cpu_scheduling
#include<stdio.h>
void main()
{
    int n,i,p,c,temp,current;
    printf("enter number of process: ");
    scanf("%d",&n);
    int pid[n],at[n],bt[n],wt[n],tat[n],ct[n];
    printf("enter arrival time in order: ");
    for(i=0;i<n;i++)
    {
        pid[i]=i+1;
        scanf("%d",&at[i]);
    }
    printf("enter burst time in order: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }
    //sorting
    for(p=0;p<n-1;p++)
    {
        for(c=0;c<n-p-1;c++)
        {
            if(at[c]>at[c+1])
            {
                temp =pid[c];
                pid[c]=pid[c+1];
                pid[c+1]=temp;
                
                temp =at[c];
                at[c]=at[c+1];
                at[c+1]=temp;
                
                temp =bt[c];
                bt[c]=bt[c+1];
                bt[c+1]=temp;
            }
        }
    }
    //calcu
    ct[0]=at[0]+bt[0];
    current=ct[0];
    tat[0]=ct[0]-at[0];
    wt[0]=tat[0]-bt[0];
    for(i=1;i<n;)
    {
        if(at[i]<=current)
        {
            ct[i]=current+bt[i];
            current=ct[i];
            tat[i]=ct[i]-at[i];
            wt[i]=tat[i]-bt[i];
            i++;
        }
        else
        {
            current++;
        }
    }
    float awt=0,atat=0;
    printf("pid\tat\tbt\tct\ttat\twt\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
        atat+=tat[i];
        awt+=wt[i];
    }
    printf("average turn around time=%f\n",atat/n);
    printf("average waiting time=%f\n",awt/n);
}
