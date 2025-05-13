//stack_using_linked_list

#include<stdio.h>
#include<malloc.h>
struct Node
{
    int info;
    struct Node* next;
};
typedef struct Node node;
node* TOP=NULL;
node*newnode()
{
    return((node*)malloc(sizeof(node)));
}
void push(int val)
{
    node*p=newnode();
    if(p==NULL)
        printf("no memory");
    else
    {   
        p->info=val;
        p->next=TOP;
        TOP=p;
    }
}

int pop()
{
    int item;
    node*p=TOP;
    TOP=TOP->next;
    item=p->info;
    free(p);
    return(item);
}
int peek()
{
    if(TOP==NULL)
        printf("stack empty");
    else
        return(TOP->info);
}
int isempty()
{
    if(TOP==NULL)
        return(1);
    else
        return(0);
}
void display()
{
    node*curr;
    curr=TOP;
    while(curr!=NULL)
    {
        printf("%d \n",curr->info);
        curr=curr->next;
    }        
}

void main()
{
    int c,val;
    printf("1.push \n2.pop \n3.peek \n4.display \n5.exit \n");
    do
    {
        printf("enter choice ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                    printf("enter value ");
                    scanf("%d",&val);
                    push(val);
                    break;
            case 2:
                    if(isempty())
                        printf("stack empty");
                    else
                    {
                        printf("the deleted item is %d ",pop());
                    }
                    break;
            case 3:
                    if(isempty())
                        printf("stack empty");
                    else
                    {
                        printf("the top item is %d ",peek());
                    }
                    break;
            case 4:
                    if(isempty())
                        printf("stack empty");
                    else
                        display();
                    break;
            case 5: printf("exit");
                    break;
            default:printf("invalid");
        }
    }while(c!=5);
}
