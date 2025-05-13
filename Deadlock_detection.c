//deadlock_detection
#include<stdio.h>
void main()
{
    int n,m,i,j;
    printf("enter number of process: ");
    scanf("%d",&n);
    printf("enter number of resources: ");
    scanf("%d",&m);
    int alloc[n][m],request[n][m],avail[m];
    printf("enter allocation matrix: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("enter request matrix: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&request[i][j]);
        }
    }
    printf("enter available matrix: \n");
    for(i=0;i<m;i++)
    {
        scanf("%d",&avail[i]);
    }
    int finish[n];
    for(i=0;i<n;i++)
    {
        finish[i]=0;
    }
    //check if process can be executed
    int dead=0;
    for(i=0;i<n;i++)
    {
        if(finish[i]==0)
        {
            int canexecute=1;
            for(j=0;j<m;j++)
            {
                if(request[i][j]>avail[j])
                {
                canexecute=0;
                break;
                }
            }    
            if(canexecute)
            {
                for(j=0;j<m;j++)
                {
                    avail[j]+=alloc[i][j];
                    finish[i]=1;
                    i=-1;//reset i to check all process
                }
            }
        }    
            
    }
    //checking unfinished
    for(i=0;i<n;i++)
    {
        if(finish[i]==0)
        {
            dead=1;
            break;
        }
    }
    if(dead)
    {
        printf("dead yes\n");
    }
    else
    {
        printf("dead no\n");
    }
}
