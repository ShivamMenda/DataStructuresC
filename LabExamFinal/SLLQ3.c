#include<stdio.h>
#include<stdlib.h>

int count=0;

struct node
{
    int data;
    struct node *add;
};

typedef struct node Node;

Node *create()
{
    Node *new;
    new=(Node *)malloc(sizeof(Node));
    printf("Enter data:");
    scanf("%d",&new->data);
    new->add=NULL;
    return new;
}

void display(Node *root)
{
    Node *temp;
    temp=root;
    if (root==NULL)
    {
        printf("List empty\n");
    }
    while (temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->add;
    }    
}

Node *insertatpos(Node *root,int pos)
{
    Node *new;
    Node *temp,*prev,*cur;
    temp=root;
    int i;
    new=create();
    printf("Enter pos:");
    scanf("%d",&pos);
    if (root==NULL)
    {
        count=1;
       return new; 
    }
    else if (pos<1 || pos>count+1)
    {
        printf("Invalid pos\n");
        return root;
    }
    else if (pos==1)
    {
        new->add=root;
        return new;
    }
    else if (pos==count+1)
    {
        while (temp->add!=NULL)
        {
            temp=temp->add;
        }
        temp->add=new;
        return root;
    }
    else
    {
        temp=root;
        for (i = 1; i < pos; i++)
        {
            prev=temp;
            temp=temp->add;
        }
        new->add=temp;
        prev->add=new;
        return root;
    }
    
    
    

}

Node *delatpos(Node *root,int pos)
{
    Node *temp,*prev;
    printf("Enter pos:");
    scanf("%d",&pos);
    if (root==NULL)
    {
        printf("List empty\n");
        return root;
    }
    else if (pos<1 || pos>count)
    {
        printf("Invalid pos\n");
        return root;
    }
    else if (pos==1)
    {
       temp=root;
       root=root->add;
       printf("The deleted node is %d\n",temp->data);
       free(temp);
       return root; 
    }
    else
    {
        temp=root;
        for (int i = 1; i < pos; i++)
        {
            prev=temp;
            temp=temp->add;
        }
        prev->add=temp->add;
        printf("The deleted node is %d\n",temp->data);
        free(temp);
        count--;
        return root;

    }
       
}

Node *search(Node *root,int key)
{
    int pos=1;
    Node *temp;
    temp=root;
    if (root==NULL)
    {
        printf("List empty\n");
        return root;
    }
    else if (root->data==key)
    {
        pos=1;
        printf("Key found at %d\n",pos);
        return root;
    }
    else
    {
        while (temp!=NULL && temp->data!=key)
        {
            temp=temp->add;
            pos++;
        }
        if (temp==NULL)
        {
            printf("Not found\n");
        }
        else
        {
            printf("Found at %d\n",pos);
        }
        return root;
    }
    
    
}

Node *rev(Node *root)
{
    Node *temp,*cur;
    if (root==NULL)
    {
        printf("List empty\n");
        return NULL;
    }
    
        cur=NULL;
        while (root!=NULL)
        {
            temp=root;
            root=root->add;
            temp->add=cur;
            cur=temp;   
        }
        return cur;
    
}


int main()
{
    Node *root=NULL;
    int ch,i,pos,key;
    while (1)
    {
        printf("\n----SLL-----\n");
        printf("1.Insert by pos\n");
        printf("2.Delete by pos\n");
        printf("3.Search by key\n");
        printf("4.Reverse\n");
        printf("5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            root=insertatpos(root,pos);
            count++;
            display(root);
            break;
        case 2:
            root=delatpos(root,pos);
            display(root);
            break;
        case 3:
            printf("Enter key to find:");
            scanf("%d",&key);
            root=search(root,key);
            display(root);
            break;
        case 4:
            root=rev(root);
            display(root);
            break;
        default:
            exit(1);
            break;
        }
    }
    
}