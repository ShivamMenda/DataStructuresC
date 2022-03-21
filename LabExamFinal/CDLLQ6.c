#include<stdio.h>
#include<stdlib.h>

int count=0;

struct node
{
    int data;
    struct node *left,*right;
};

typedef struct node Node;

Node *create()
{
    Node *new;
    new=(Node *)malloc(sizeof(Node));
    new->left=new->right=new;
    return new;
}

void display(Node* head)
{
    Node *temp;
    if (head->right==head)
    {
        printf("List empty\n");
    }
    else
    {
        temp=head->right;
        while (temp!=head)
        {
            printf("%d->", temp->data);
        temp = temp->right;
        }
        
    }
    
}

Node *insertpos(Node *head,int pos,int item)
{
    Node *new,*temp;
    new=create();
    new->data=item;
    temp=head->right;
    if (pos<1 || pos>head->data+1)
    {
        printf("Invalid pos\n");
        return head;
    }
    for (int i = 1; i < pos; i++)
    {
        temp=temp->right;
    }
    temp->left->right=new;
    new->left=temp->left;
    new->right=temp;
    temp->left=new;
    head->data++;
    return head;
}

Node *delpos(Node *head,int pos)
{
    Node *new,*temp;
    temp=head->right;
    if (pos<1 || pos>head->data)
    {
        printf("Invalid pos\n");
        return head;
    }
    for (int i = 1; i < pos; i++)
    {
        temp=temp->right;
    }
    temp->left->right=temp->right;
    temp->right->left=temp->left;
    printf("The deleted node is %d\n",temp->data);
    free(temp);
    head->data--;
    return head;
}

Node *search(Node *head,int key)
{
    int pos=1;
    Node *temp;
    if (head->right==head)
    {
        printf("List empty\n");
        return head;
    }
    temp=head->right;
    if (temp->data==key)
    {
        pos=1;
        printf("Key found at pos %d\n",pos);
        return head;   
    }
    else
    {
        while (temp!=head && temp->data!=key)
        {
            temp=temp->right;
            pos++;
        }
        if (temp==head)
        {
            printf("Not found\n");
            return head;
        }
        else
        {
            printf("Found at pos %d\n",pos);
            return head;
        }
        
        
    }
    
}

Node *reverse(Node *head)
{
    Node *temp,*prev;
    if (head->right==head)
    {
        printf("List empty\n");
        return head;
    }
    temp=head;
    prev=head->left;
    do
    {
        temp->left=temp->right;
        temp->right=prev;
        prev=temp;
        temp=temp->left;
    } while (temp!=head);
    return head;
    
}

int main()
{
Node *head;
head=create();
head->data=0;
    int ch,i,pos,key,item;
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
            printf("Enter pos:");
            scanf("%d",&pos);
            printf("Enter item:");
            scanf("%d",&item);
            head=insertpos(head,pos,item);
            display(head);
            break;
        case 2:
            printf("Enter pos to delete:");
            scanf("%d",&pos);
            head=delpos(head,pos);
            display(head);
            break;
        case 3:
            printf("Enter key to find:");
            scanf("%d",&key);
            head=search(head,key);
            display(head);
            break;
        case 4:
            head=reverse(head);
            display(head);
            break;
        default:
            exit(1);
            break;
        }
    }
    
}
