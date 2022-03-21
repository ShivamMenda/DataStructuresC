#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *add;
};
typedef struct node Node;

int main(){
    Node *root=NULL,*t,*temp,*nw;
    int i,n;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    for ( i = 1; i <= n; i++)
    {
        nw=(Node *)malloc(sizeof(Node));
        printf("Enter the info:");
        scanf("%d",&nw->info);
        if (root==NULL)
        {
            nw->add=nw;
            root=temp=nw;
        }
        else
        {
            temp->add=nw;
            temp=temp->add;
            nw->add=root;
        }
        
    }
    t=root;
    do
    {
        printf("%d->",t->info);
        t=t->add;
    } while (t!=root);
    
    


}