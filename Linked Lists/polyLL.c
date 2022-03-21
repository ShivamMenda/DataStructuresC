#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coeff;
    int exponen;
    struct node *add;
};

typedef struct node Node;

Node *createnode()
{
    Node *nw;
    nw=(Node *)malloc(sizeof(Node));
    printf("Enter coeff:");
    scanf("%d",&nw->coeff);
    printf("Enter exp:");
    scanf("%d",&nw->exponen);
    nw->add=NULL;
    return nw;
}

void addpoly(Node *first,Node *second)
{
    if(first==NULL && second==NULL){
        return ;
    }
    else if(first->exponen==second->exponen)
    {
        printf("%d x^%d",first->coeff+second->coeff,first->exponen);
        addpoly(first->add,second->add);
    }
    else if(first->exponen>second->exponen)
    {
        printf("%d x^%d",first->coeff,first->exponen);
        addpoly(first->add,second);
    }
    else
    {
        printf("%d x^%d",second->coeff,second->exponen);
        addpoly(first,second->add);
    }
    
}
Node * insert(Node *head)
{
    Node *temp,*trav;
    if (head==NULL)
    {
        head=trav=temp;   
    }
    else
    {
        trav->add=temp;
        trav=trav->add;
    }
    return head;
}


void printList(Node *head){
  while(head!=NULL){
    printf("%d x^%d\n",head->coeff,head->exponen);
    head = head->add;
  }
}

int main()
{
    Node *head=NULL,*head1=NULL,*temp,*trav;
    int i,j,n,n1;
    printf("Enter the number of terms for poly 1:");
    scanf("%d",&n);
    for (i = 0; i <n; i++)
    {
        Node *head=createnode();
        head=insert(head);
    }
    printf("Enter the number of terms for poly 2:");
    scanf("%d",&n1);
    for (j = 0; j <n1; j++)
    {
        Node *head1=createnode();
        head1=insert(head1);
    }
    printList(head);
    printList(head1);
    addpoly(head,head1);
}