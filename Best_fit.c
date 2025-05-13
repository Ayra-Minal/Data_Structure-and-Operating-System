//Bestfit_memory_allocation
#include<stdio.h>
void main()
{
    int nb,nf,temp,i,j;
    printf("enter number  of block: ");
    scanf("%d",&nb);
    printf("enter number of files: ");
    scanf("%d",&nf);
    int frag[nf+1],f[nf+1],ff[nf+1];
    int b[nb+1],bf[nb+1];
    printf("enter size of blocks: \n");
    for(i=1;i<=nb;i++)
    {
        printf("block %d: ",i);
        scanf("%d",&b[i]);
    }
    printf("enter size of files: \n");
    for(i=1;i<=nf;i++)
    {
        printf("file %d: ",i);
        scanf("%d",&f[i]);
    }
    for(i=1;i<=nf;i++)
    {
        temp=-1;
        for(j=1;j<=nb;j++)
        {
            if(bf[j]!=1)
            {
                if(b[j]>=f[i])
                {
                    if(temp==-1 || (b[j]-f[i])<(b[temp]-f[i]))
                    {
                        temp=j;
                    }
                }
            }
        }
        if(temp!=-1)
        {
            frag[i]=b[temp]-f[i];
            ff[i]=temp;
            bf[temp]=1;
        }
        else
        {
            frag[i]=-1;
            ff[i]=-1;
        }
    }
    printf("Fileno.\tFilesize\tblockno\tblocksize\tFragment\n");
    for(int i=1;i<=nf;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t%d\n",i,f[i],ff[i],b[ff[i]],frag[i]);
    }
    
}
