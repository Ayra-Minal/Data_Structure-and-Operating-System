//Forking_mechanism
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void main()
{
    int pid,pid1,pid2;
    pid=fork();
    if(pid==-1)
    {
        printf("error in process");
        exit(1);
    }
    if(pid!=0)
    {
        pid1=getpid();
        printf("the process id of parent is: %d\n",pid1);
    }
    else
    {
        pid2=getpid();
        printf("the pid of child id : %d",pid2);
    }
}
