//polynomial_addition_using_linked_list

#include <stdio.h>
#include<malloc.h>
struct Node 
{
    int cons;
    int expo;
    struct Node*next;
};
typedef struct Node node;
node*head=NULL;
node*newnode()
{
    return((node*)malloc(sizeof(node)));
}
node*readpoly()
{
    int c,e,choice;
    node*curr;
    head=newnode();
    curr=head;
    do
    {
        printf("enter constant and exponent :" );
        scanf("%d %d",&c,&e);
        curr->cons=c;
        curr->expo=e;
        printf("more? ");
        scanf("%d",&choice );
        if(choice==1)
        {
            curr->next=newnode();
            curr=curr->next;
        }
    }while(choice==1);
    curr->next=NULL;
    return head;
    
}
node *addpoly(node*A ,node*B)
{
    node *C,*curr;
    C=newnode();
    curr=C;
    while(A!=NULL && B!=NULL)
    {
        if(A->expo==B->expo)
        {
            curr->cons=A->cons+B->cons;
            curr->expo=A->expo;
            A=A->next;
            B=B->next;
        }
        else if(A->expo > B->expo)
        {
            curr->cons=A->cons;
            curr->expo=A->expo;
            A=A->next;
        }
        else
        {
            curr->cons=B->cons;
            curr->expo=B->expo;
            B=B->next;
        }
        if(A!=NULL || B!=NULL)
        {
            curr->next=newnode();
            curr=curr->next;
        }
    }
     while(A!=NULL)
     {
        curr->cons=A->cons;
        curr->expo=A->expo;
        A=A->next;
        if(A!=NULL)
        {
            curr->next=newnode();
            curr=curr->next;
        }
        
     }
     while(B!=NULL)
     {
        curr->cons=B->cons;
        curr->expo=B->expo;
        B=B->next;
        if(B!=NULL)
        {
            curr->next=newnode();
            curr=curr->next;
        }
        
     }
    curr->next=NULL;
    return (C);
     
        
}
void displaypoly(node*poly)
{
    node*curr;
    curr=poly;
    while(curr!=NULL)
    {
        printf("%dx^%d",curr->cons,curr->expo);
        if(curr->next!=NULL)
            printf("+");
        curr=curr->next;
    }
    printf("\n");
}
void main()
{
    node *A,*B,*C;
    A=readpoly();
    B=readpoly();
    printf("poly A is: \n");
    displaypoly(A);
    printf("poly B is: \n");
    displaypoly(B);
    printf("resultant is: \n");
    C=addpoly(A,B);
    displaypoly(C);
}
