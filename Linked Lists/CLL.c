#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *add;
};

typedef struct node Node;
Node *createnode()
{
    Node *nw;
    nw=(Node *)malloc(sizeof(Node));
    printf("Enter info:");
    scanf("%d",&nw->info);
    nw->add=nw;
    return nw;
}

Node *insertatfront(Node *root,Node *nw)
{
    Node *temp;
    if (root==NULL)
    {
        return nw;
    }
    else
    {
        temp=root;
        while (temp->add!=root)
        {
            temp=temp->add;
        }
        nw->add=root;
        temp->add=nw;
        root=nw;
        return root;
    }
}

Node *insertatrear(Node *root,Node *nw){
    Node *temp;
    if (root==NULL)
    {
        return nw;
    }
    else
    {
        temp=root;
        while (temp->add!=root)
        {
            temp=temp->add;
        }
        temp->add=nw;
        nw->add=root;
        return root;
    }
}





Node *delatfront(Node *root)
{
    Node *temp,*cur;
    if (root==NULL)
    {
        printf("No nodes to be deleted\n");
        return root;
    }
    else if (root->add==root)
    {
        printf("the deleted node is %d\n",root->info);
        free(root);
        root=NULL;
        return root;
    }
    else
    {
       temp=root;
       while (temp->add!=root)
       {
           temp=temp->add;
       }
        cur=root;
        root=root->add;
        temp->add=root;
        printf("The deleted node is %d",cur->info);
        free(cur);
        return root;
    }
    
}
Node *delatrear(Node *root)
{
    Node *temp,*cur;
    if (root==NULL)
    {
        printf("No nodes to be deleted\n");
        return root;
    }
    else if (root->add==root)
    {
        printf("the deleted node is %d\n",root->info);
        free(root);
        root=NULL;
        return root;
    }
    else
    {
       temp=root;
       cur=root;
       while (temp->add!=root)
       {
           cur=temp;
           temp=temp->add;
       }
       cur->add=root;
       printf("The deleted node is %d\n",temp->info);
       temp->add=NULL;
       free(temp);
       return root;
        
    }
}
Node *insertatpos(Node *root,Node *nw,int pos)
{
    Node *cur,*temp;
    int i;
    int count=0;
    printf("Enter pos:");
    scanf("%d",&pos);
    temp=root;
    if (root==NULL)
    {
        return nw;
    }
    
    while (temp->add!=root)
    {
        temp=temp->add;
        count++;
    }
    if (pos<1|| pos>count+1)
    {
        printf("Invalid pos\n");
        return root;
    }
    
        if (pos==1)
        {
            root=insertatfront(root,nw);
            return root;
        }
        else
        {
            cur=root;
            for (i = 2; i <=pos-1; i++)
            {
                cur=cur->add;
            }
            nw->add=cur->add;
            cur->add=nw;
            return root;
        }
    }
    
Node *delatpos(Node *root,int pos)
{
    Node *cur,*temp,*prev;
    int i;
    int count=0;
    printf("Enter pos:");
    scanf("%d",&pos);
    temp=root;
    if (root==NULL)
    {
        printf("No nodes to be deleted\n");
        return root;
    }
    while (temp->add!=root)
    {
        temp=temp->add;
        count++;
    }
    if (pos<1|| pos>count+1)
    {
        printf("Invalid pos\n");
        return root;
    }
    if (pos==1)
    {
        root=delatfront(root);
        return root;
    }
    
    else
    {
        cur=root;
        prev=root;
        for (i = 2; i <=pos-1; i++)
        {
            prev=cur;
            cur=cur->add;
        }
        prev->add=cur->add;
        printf("The deleted node is %d\n",cur->info);
        free(cur);
        return root;
    }
    
    
} 
int search(Node *root,int key)
{
    int index=0;
    Node *cur;
    cur=root;
    do
    {
       if (cur==NULL)
       {
           return 0;
       }
       if (cur->info==key)
       {
           return index;
       }
       cur=cur->add;
       index++;
       
    } while (cur!=root);
    return -1;
}
Node *update(Node *root,int key,int item)
{
    Node *temp;
    if (root==NULL)
    {
        printf("Nothing to update\n");
        return root;
    }
    else if (root->info==item)
    {
        root->info=key;
        return root;
    }
    else
    {
        temp=root;
        while (temp->add!=root && temp->info!=item)
        {
            temp=temp->add;
        }
        if (temp==root)
        {
            printf("item not found\n");
            return root;
        }
        else
        {
            temp->info=key;
            return root;
        }
        

    }
    
}



void disp(Node *root)
{
    Node *temp;
    temp=root;
    if (temp==NULL)
    {
        printf("list empty\n");
    }
    else
    {
    do
    {
        printf("%d->",temp->info);
        temp=temp->add;
    } while (temp!=root);
    }
    
}

int main()
{
Node *root=NULL,*nw;
    int ch,item,pos,index,key;
    while (1)
    {
        printf("\n-----IMPLEMENTATION OF CLL-----\n");
        printf("1.Insert front\n");
        printf("2.Insert rear\n");
        printf("3.Display\n");
        printf("4.Del at front\n");
        printf("5.Del at rear\n");
        printf("6.Search\n");
        printf("7.Insert at pos\n");
        printf("8.Del at pos\n");
        printf("9.Update\n");
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
            printf("Enter item:");
            scanf("%d",&item);
            index=search(root,item);
            if (index==-1)
            {
                printf("Not found\n");
            }
            else
            {
                printf("Found at %d\n",(index+1));
            }
            
            break;
        case 7:
            nw=createnode();
            root=insertatpos(root,nw,pos);
            break;
        case 8:
            root=delatpos(root,pos);
            break;
        case 9:
            printf("Enter key to update:");
            scanf("%d",&item);
            printf("Enter updated value\n");
            scanf("%d",&key);
            root=update(root,key,item);
            break;
        default:
            exit(1);
            break;
        }
    }






}