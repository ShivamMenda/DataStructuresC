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
    printf("Enter data:");
    scanf("%d",&new->data);
    new->left=NULL;
    new->right=NULL;
    return new;
}
void display(Node *first)
{
    Node *temp;
    if(first == NULL)
    {
        printf("\nThe list is empty\n");
        return;
    }
    temp = first;
    printf("\nThe elements of the list are:\n");
    while(temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->right;
    }
    return;
}

Node *insertfront(Node *root)
{
    Node *new;
    new=create();
    count++;
    if (root==NULL)
    {
        return new;
    }
    else
    {
        new->right=root;
        root->left=new;
        return new;
    }
}

Node *insert_rear(Node *first)
{
    Node *temp, *new;
    new = create();
    count++;
    if(first == NULL)
    {
        display(new);
        return new;
    }
    temp = first;
    while(temp->right != NULL)
    {
        temp = temp->right;
    }
    temp->right = new;
    new->left = temp;
    return first;
}

Node *delete_front(Node *first)
{
    Node *temp;
    if(first == NULL)
    {
        printf("\nList Empty\n");
        return NULL;
    }
    count--;
    if(first->right == NULL)
    {
        printf("\nNode with %d is deleted\n", first->data);
        free(first);
        display(NULL);
        return NULL;
    }
    temp = first;
    first = first->right;
    first->left = NULL;
    free(temp);
    display(first);
    return first;
}

Node* delete_rear(Node* first)
{
    Node* temp;
    if(first == NULL)
    {
        printf("\nList Empty\n");
        return NULL;
    }
    count--;
    if(first->right == NULL)
    {
        printf("\nNode with %d is deleted\n", first->data);
        free(first);
        display(NULL);
        return NULL;
    }
    temp = first;
    while(temp->right != NULL)
    {
        temp = temp->right;
    }
    temp->left->right = NULL;
    free(temp);
    display(first);
    return first;
}
Node * delete_pos(Node * first, int pos)
{
    int i;
    Node * temp;
    temp = first;
    if(pos<1 || pos>count)
    {
        printf("\nInvalid position\n");
        return first;
    }
    if(first == NULL)
    {
        printf("\nList Empty\n");
        return NULL;
    }
    if(pos == 1)
    {
        first = delete_front(first);
        return first;
    }
    if(pos == count)
    {
        first = delete_rear(first);
        return first;
    }
    for(i=1; i<pos; i++)
    {
        temp = temp->right;
    }
    temp->left->right = temp->right;
    temp->right->left = temp->left;
    free(temp);
    count--;
    display(first);
    return first;
}

int search(Node* first, int key)
{
    Node* temp;
    int pos=1;
    if (first == NULL)
    {
       printf("\nList Empty\n");
       return -1;
    }
    temp = first;
    while(temp != NULL && temp->data != key)
    {
        temp = temp->right;
        pos++;
    }
    if(temp == NULL)
        return 0;
    else
        return pos;
    
}

Node *delbykey(Node *first,int key)
{
    int pos;
    pos=search(first,key);
    if (pos==-1)
    {
        return NULL;
    }
    else if (pos==0)
    {
        printf("Not found\n");
        return first;
    }
    first=delete_pos(first,pos);
    return first;
    
}

Node *reverse(Node *first)
{
    Node *temp, *prev;
    if(first == NULL)
    {
        printf("\nList Empty\n");
        return NULL;
    }
    temp = first;
    prev = NULL;
    while(temp != NULL)
    {
        temp->left = temp->right;
        temp->right = prev;
        prev = temp;
        temp = temp->left;
    }
    display(prev);
    return prev;
}


int main()
{
    Node *root=NULL;
    int ch,i,pos,key,item;
    while (1)
    {
        printf("\n----DLL-----\n");
        printf("1.Insert at front\n");
        printf("2.Insert at rear\n");
        printf("3.Delete by key\n");
        printf("4.Reverse\n");
        printf("5.Delete front\n");
        printf("6.Delete rear\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            root=insertfront(root);
            display(root);
            break;
        case 2:
            root=insert_rear(root);
            display(root);
            break;
        case 3:
            printf("Enter key to delete:");
            scanf("%d",&key);
            root=delbykey(root,key);
            break;
        case 4:
            root=reverse(root);
            break;
        case 5:
            root=delete_front(root);
            break;
        case 6:
            root=delete_rear(root);
            break;
        default:
            exit(1);
            break;
        }
    }
    
}