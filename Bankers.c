//Bankers
#include<stdio.h>
void main()
{
    int abc,np,i,j,k,c;
    printf("enter number of process: ");
    scanf("%d",&np);
    printf("enter number of instances: ");
    scanf("%d",&abc);
    
    //input alloc
    int alloc[np][abc],max[np][abc],avail[abc],need[np][abc];
    printf("enter allocation matrix");
    for(i=0;i<np;i++)
    {
        for(j=0;j<abc;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("enter max matrix");
    for(i=0;i<np;i++)
    {
        for(j=0;j<abc;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    printf("enter available matrix");
    for(i=0;i<abc;i++)
    {
        scanf("%d",&avail[i]);
    }
    
    
    //calcu need
    printf("\nneed matrix is:\n");
    for(i=0;i<np;i++)
    {
        printf("\t\n");
        for(j=0;j<abc;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
            printf("%d\t",need[i][j]);
        }
    }
    
    
    //banker
    int flag,completed[np],safeseq[np],checker=0,index=0;
    for(i=0;i<np;i++)
    {
        completed[i]=0;
    }
    for(c=0;c<np;c++)
    {
        for(i=0;i<np;i++)
        {
            if(completed[i]==0)
            {
                flag=0;
                for(j=0;j<abc;j++)
                {
                    if(need[i][j]>avail[j])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    safeseq[index++]=i;
                    for(k=0;k<abc;k++)
                    {
                        avail[k]+=alloc[i][k];
                    }
                    completed[i]=1;
                    checker++;
                }    
            }
        }
    }
    if(checker==np)
    {
        printf("\nSafe seq is:\n\t");
        for(i=0;i<np-1;i++)
        {
            printf("P%d->",safeseq[i]);
        }
        printf("P%d\n",safeseq[np-1]);
    }
    else
    {
        printf("\ndeadlock");
    }
}
