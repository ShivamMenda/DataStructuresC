#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *add;

};


int main()
{
    struct node *root=NULL,*temp,*trav;
    struct node *ptr;
    int i,n;

    printf("Enter the number of nodes:");
    scanf("%d",&n);

    for ( i = 1; i <=n; i++)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d",&temp->info);
        temp->add=NULL;
        if (root==NULL)
        {
            root=trav=temp;
        }
        else{

            trav->add=temp;
            trav=trav->add;
        }
        
    }

    while (root!=NULL)
    {
        printf("%d->",root->info);
        root=root->add;
    }
    
    




}