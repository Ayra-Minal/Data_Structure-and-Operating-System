//queue_using_linked_list
#include <stdio.h>
#include<malloc.h>
struct Node
{
    int info;
    struct Node*next;
};
typedef struct Node node;
node*f=NULL;
node*r=NULL;
node*newnode()
{
    return((node*)malloc(sizeof(node)));
}
void insert(int item)
{
    node*p=newnode();
    p->info=item;
    p->next=NULL;
    if(r==NULL)
        f=r=p;
    else
    {
        r->next=p;
        r=p;
    }    
}
int isempty()
{
    if(f==NULL)
        return(1);
    else
        return(0);
}

int deleteq()
{
    int item;
    if(isempty())
        printf("queue empty");
    else
    {    
        node*p=f;
        item=p->info;
        if(f==r)
            f=r=NULL;
        else
            f=f->next;
        free(p);    
        return(item);    
    }    
}

void display()
{
    node*curr=f;
    while(curr!=NULL)
    {
        printf("%d \n",curr->info);
        curr=curr->next;
    }printf("\n");
}
void main()
{
    int c,val;
    printf("1.insert \n2.delete \n3.display \n4.exit \n");
    do
    {
        printf("enter choice ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                    printf("enter value ");
                    scanf("%d",&val);
                    insert(val);
                    break;
            case 2:
                    if(f==NULL)
                        printf("Queue is empty");
                    else
                        printf("the deleted item is %d ",deleteq());
                    break;
            case 3:
                    if(isempty())
                        printf("queue empty");
                    else
                        display();
                    break;
            case 4:
                    printf("exit");
                    break;
            default:printf("invalid");        
        }
    }while(c!=4);
}

