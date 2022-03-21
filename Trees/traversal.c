#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *left;
    struct node *right;
};

typedef struct node Node;

void preorder(Node *t)
{
    if (t!=NULL)
    {
        printf("%d ",t->info);
        preorder(t->left);
        preorder(t->right);
    }
  return;  
}
void postorder(Node *t)
{
    if (t!=NULL)
    {
        postorder(t->left);
        postorder(t->right);
        printf("%d ",t->info);
    }
    return;
}

void create(Node *root)
{
    Node *nw;
    int ch;
    printf("Create left child(1/0):");
    scanf("%d",&ch);
    if (ch==1)
    {
        nw=(Node *)malloc(sizeof(Node));
        printf("Enter info:");
        scanf("%d",&nw->info);
        nw->left=NULL;
        nw->right=NULL;
        root->left=nw;
        create(nw);
    }
    printf("Create right child(1/0):");
    scanf("%d",&ch);
    if (ch==1)
    {
        nw=(Node *)malloc(sizeof(Node));
        printf("Enter info:");
        scanf("%d",&nw->info);
        nw->left=NULL;
        nw->right=NULL;
        root->right=nw;
        create(nw);
    }
    
}

int main()
{
    Node *root;
    root=(Node *)malloc(sizeof(Node));
    printf("Enter the value for root(info):");
    scanf("%d",&root->info);
    create(root);
    printf("Preorder is:\n");
    preorder(root);
    printf("\nPostorder is\n");
    postorder(root);
}