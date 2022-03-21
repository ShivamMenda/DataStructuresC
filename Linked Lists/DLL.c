#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *left,*right;
};
typedef struct node Node;

Node *createnode()
{
    Node *new;
    new=(Node *)malloc(sizeof(Node));
    printf("Enter info:");
    scanf("%d",&new->info);
    new->right=NULL;
    new->left=NULL;
    return new;
}

Node *insertatfront(Node *root,Node *new)
{
    if (root==NULL)
    {
        root=new;
    }
    else
    {
        new->right=root;
        root->left=new;
        root=new;
    }
    return root;
}
Node *insertatrear(Node *root,Node *new)
{
    Node *temp;
    if (root==NULL)
    {
        root=new;
    }
    else
    {
        temp=root;
        while (temp->right!=NULL)
        {
            temp=temp->right;
        }
        temp->right=new;
        new->left=temp;
    }
    return root;
}
Node *delatfront(Node *root)
{
    Node *temp;
    if (root==NULL)
    {
        printf("no nodes to be deleted\n");
        return root;
    }
    else if (root->left==NULL && root->right==NULL)
    {
        printf("The node deleted with info %d\n",root->info);
        free(root);
        root=NULL;
        return root;
    }
    else
    {
        temp=root;
        root=root->right;
        printf("The deleted node is %d\n",temp->info);
        free(temp);
        return root;
    }
    return root;
    
}
Node *delatrear(Node *root)
{
    Node *temp,*temp2;
    if (root==NULL)
    {
        printf("no nodes to be deleted\n");
        return root;
    }
    else if (root->left==NULL && root->right==NULL)
    {
        printf("The node deleted with info %d\n",root->info);
        free(root);
        root=NULL;
        return root;
    }
    else
    {
        temp=root;
        while (temp->right!=NULL)
        {
            temp=temp->right;
        }
        temp2=temp->left;
        temp2->right=NULL;
        printf("The deleted node is %d\n",temp->info);
        free(temp);
        temp=NULL;
        return root;
        
    }
    return root;
    
}

Node *reverse(Node *root)
{
    if (root==NULL)
    {
        printf("List empty\n");
        return root;
    }
    
    Node *ptr1=root;
    Node *ptr2=root->right;
    ptr1->right=NULL;
    ptr1->left=ptr2;
    while (ptr2!=NULL)
    {
        ptr2->left=ptr2->right;
        ptr2->right=ptr1;
        ptr1=ptr2;
        ptr2=ptr2->left;
    }
    root=ptr1;
    return root;
}


// Node *insertpos(Node *root,Node *new,int pos)
// {
//     Node *prev,*next,*temp;
//     int i=1,count=1;
//     printf("Enter pos:");
//     scanf("%d",&pos);
//     if (root==NULL)
//     {
//         root=new;
//         return root;
//     }
//     temp=root;
//     while (temp!=NULL)
//     {
//         temp=temp->right;
//         count++;
//     }
//     if (pos<1 || pos>count+1)
//     {
//         printf("Invalid pos\n");
//         return root;
//     }
//     else
//     {
//         if (pos==1)
//         {
//         new->right=root;
//         root->left=new;
//         root=new;
//         return root;
//         }
//             i=2;
//             while (prev!=NULL && i<pos)
//             {
//                 prev=prev->right;
//                 i++;
//             }
//             next=prev->right;
//             prev->right=new;
//             new->left=prev;
//             new->right=next;
//             next->left=new;
//             return root;
        
//     }
//     return root;
    
// }





void disp(Node *root)
{
    Node *temp;
    if (root==NULL)
    {
        printf("List empty\n");
    }
    else
    {
      temp=root;
      while (temp!=NULL)
      {
          printf("%d->",temp->info);
          temp=temp->right;
      }
        
    }
}

int main()
{
 Node *root=NULL,*nw;
    int ch,item,pos;
    while (1)
    {
        printf("\n-----IMPLEMENTATION OF DLL-----\n");
        printf("1.Insert front\n");
        printf("2.Insert rear\n");
        printf("3.Display\n");
        printf("4.Del at front\n");
        printf("5.Del at rear\n");
        printf("6.Reverse\n");
        printf("7.Insert at pos\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            nw=createnode();
            root=insertatfront(root,nw);
            break;
        case 2:
            nw=createnode();
            root=insertatrear(root,nw);
            break;
        case 3:
            disp(root);
            break;
        case 4:
            root=delatfront(root);
            break;
        case 5:
            root=delatrear(root);
            break;
        case 6:
            root=reverse(root);
            break;
        // case 7:
        //     nw=createnode();
        //     root=insertpos(root,nw,pos);
        //     break;
        default:
            exit(1);
            break;
        }
    }   
}