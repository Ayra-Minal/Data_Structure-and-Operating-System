//double_ended_queue
#include <stdio.h>
#include<stdlib.h>
#define SIZE 10
int Q[SIZE];
int F=-1;
int R=-1;
int isfull();
int isempty();
void insertrear(int item);
void insertfront(int item);
int deleterear();
int deletefront();
void display();

void main()
{
    int item,c;
    printf("1.insertrear \n 2.insertfront \n 3.deletefront \n 4.deleterear \n 5.display \n 6.exit \n");
    do
    {
        printf("enter choice ");
        scanf("%d",&c);
        switch(c)
        {
            case 1: 
                    if(isfull())
                        printf("queue full");
                    else
                        {
                        printf("enter no.to be inserted");
                        scanf("%d",&item);
                        insertrear(item);
                        }
                    break;
            case 2:
                    if(isfull())
                        printf("queue full");
                    else
                        {
                        printf("enter no.to be inserted");
                        scanf("%d",&item);
                        insertfront(item);
                        }
                    break;
            case 3: 
                    if(isempty())
                        printf("is empty");
                    else
                        printf("the deleted item is %d ",deletefront());
                    break;    
            case 4:
                    if(isempty())
                        printf("is empty");
                    else
                        printf("the deleted item is %d ",deleterear());
                    break; 
            case 5:
                    if(isempty())
                        printf("is empty");
                    else 
                        display();
                    break;    
            case 6:printf("exit");
                    break;
            default:printf("invalid");  
                    break;
        }
    }while(c!=6);
}    
  
int isfull()
{
    if(F==(R+1)%SIZE)
        return(1);
    else
        return(0);
}
int isempty()
{
    if(F==-1)
        return(1);
    else
        return(0);
}

void insertrear(int item)
{
    if(isfull())
        printf("is full");
    else
        if(isempty())
        {
            F=R=0;
            Q[R]=item;
        }
        else
        {
            R=(R+1)%SIZE;
            Q[R]=item;
        }
}
int deletefront()
{
    int item=Q[F];
    if(F==R)
        F=R=-1;
    else
        F=(F+1)%SIZE;
    return (item);    
}

void insertfront(int item)
{
    if(isfull())
        printf("is full");
    else 
    {
        if(F==-1)
        {
            {F=R=0;
            Q[F]=item;}
        }  
        else if(F==0)
            {F=SIZE-1;
            Q[F]=item;}
        else 
            {F--;
            Q[F]=item;}
            
    }
}
int deleterear()
{
    if(isempty())
        printf("is empty");
    else 
    {
        int item=Q[R];
        if(F==R)
        {
            F=R=-1;
        }  
        else if(R==0)
            R=SIZE-1;
        else 
            R--;
        return (item);
            
    }
}


void display()
{
    int i;
    if(R>=F)
        {
        for(i=F;i<=R;i++)
            printf("%d",Q[i]);
        }    
    else
        {
        for(i=F;i<SIZE;i++)
             printf("%d",Q[i]);
        for(i=0;i<=R;i++)    
             printf("%d",Q[i]);
        }     
}

  
    
