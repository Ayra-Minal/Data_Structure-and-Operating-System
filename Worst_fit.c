//Worstfit_memory_allocation
#include<stdio.h>
void main()
{
    int nb, nf, temp, i, j;
    printf("Enter number of blocks: ");
    scanf("%d", &nb);
    printf("Enter number of files: ");
    scanf("%d", &nf);

    int frag[nf+1], f[nf+1], ff[nf+1];
    int b[nb+1], bf[nb+1]; // bf to track if block is allocated or not

    printf("Enter size of blocks: \n");
    for(i = 1; i <= nb; i++)
    {
        printf("Block %d: ", i);
        scanf("%d", &b[i]);
        bf[i] = 0; // Initialize all blocks as not allocated
    }

    printf("Enter size of files: \n");
    for(i = 1; i <= nf; i++)
    {
        printf("File %d: ", i);
        scanf("%d", &f[i]);
    }

    // Worst Fit Allocation Logic
    for(i = 1; i <= nf; i++)
    {
        temp = -1;
        for(j = 1; j <= nb; j++)
        {
            if(bf[j] == 0) // Check if block j is not yet allocated
            {
                if(b[j] >= f[i]) // Check if block size is sufficient
                {
                    if(temp == -1 || b[j] > b[temp]) // Check if this block is larger
                    {
                        temp = j;
                    }
                }
            }
        }
        if(temp != -1)
        {
            frag[i] = b[temp] - f[i];
            ff[i] = temp;
            bf[temp] = 1; // Mark block temp as allocated
        }
        else
        {
            frag[i] = -1; // No suitable block found
            ff[i] = -1;
        }
    }

    // Output Results
    printf("\nFileno.\tFilesize\tBlockno\tBlocksize\tFragment\n");
    for(i = 1; i <= nf; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n", i, f[i], ff[i], (ff[i] != -1 ? b[ff[i]] : -1), frag[i]);
    }
}
