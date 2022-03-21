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
    nw->add=NULL;
    return nw;
}
Node *insertfront(Node *root,Node *nw)
{
    if (root==NULL)
    {
        root=nw;
    }
    else
    {
        nw->add=root;
        root=nw;
    }
    return root;
}

Node *insertrear(Node *root,Node *nw)
{
    Node *temp;
    if (root==NULL)
    {
        root=nw;
    }
    else
    {
        temp=root;
        while (temp->add!=NULL)
        {
            temp=temp->add;
        }
        temp->add=nw;
    }
    return root;
}

Node *deletefront(Node *root)
{
    Node *temp;
    if (root==NULL)
    {
        printf("No nodes to be deleted\n");
    }
    else if (root->add==NULL)
    {
        printf("The deleted node with info %d\n",root->info);
        free(root);
        root=NULL;
    }
    else
    {
        temp=root;
        printf("The node is deleted with info %d\n",temp->info);
        root=root->add;
        free(temp);
    }
    return root;
}
Node *deleterear(Node *root)
{
    Node *temp,*prev;
    if (root==NULL)
    {
        printf("No nodes to be deleted\n");
    }
    else if (root->add==NULL)
    {
        printf("The deleted node with info %d\n",root->info);
        free(root);
        root=NULL;
    }
    else
    {
        temp=root;
        while (temp->add!=NULL)
        {
            prev=temp;
            temp=temp->add;
        }
        prev->add=NULL;
        printf("The node is deleted with info %d\n",temp->info);
        free(temp);
        
    }
    return root;
}

int count(Node *root)
{
    Node *temp;
    int count=1;
    if (root==NULL)
    {
        count=0;
    }
    temp=root;
    while (temp!=NULL && temp->add!=NULL)
    {
        temp=temp->add;
        count++;
    }
    return count;
    
}

Node *insertatpos(Node *root,Node *nw,int pos)
{
    Node *temp;
    int i;
    if (root==NULL)
    {
        root=nw;
        return root;
    }
    else if (pos==1)
    {
        nw->add=root;
        root=nw;
        return root;
    }
    else if (pos<1 || pos>(count(root))+1)
    {
        printf("Invaild pos\n");
    }
    else
    {
        i=2;
        temp=root;
        while (temp->add!=NULL && i<pos)
        {
            temp=temp->add;
            i++;
        }
        nw->add=temp->add;
        temp->add=nw;
        return root;
    }
    return root;
    
}
Node *delatpos(Node *root,int pos)
{
    Node *temp,*next;
    int i;
    if (root==NULL)
    {
        printf("No nodes to be deleted\n");
    }
    else if (pos==1)
    {
        temp=root;
        printf("The node deleted with info is %d\n",temp->info);
        root=root->add;
        free(temp);
    }
    else if (pos<1 || pos>(count(root))+1)
    {
        printf("Invaild pos\n");
    }
    
    else
    {
        i=2;
        temp=root;
        next=temp->add;
        while (temp->add!=NULL && i<pos)
        {
            temp=temp->add;
            next=temp->add;
            i++;
        }
        if (next==NULL)
        {
            printf("Cannot delete node at pos %d\n",pos);
        }
        else
        {
            temp->add=next->add;
            printf("The node deleted with info %d\n",next->info);
            free(next);
        }
        
    }
    return root;
    
}

Node *search(Node *root,int item)
{
    int pos=1;
    Node *temp;
    if (root==NULL)
    {
        printf("List is empty\n");
        return root;
    }
    if (root->info==item)
    {
        pos=1;
        printf("search successful and found at pos %d\n",pos);
        return root;
    }
    
        temp=root;
        while (temp!=NULL && temp->info!=item)
        {
            temp=temp->add;
            pos++;
        }
        if (temp==NULL)
        {
            printf("Search unsuccessful\n");
            return root;
        }
        
        else if (temp->info==item)
        {
            printf("Search Successful and found at pos %d\n",pos);
            return root;
        }
        return root;
}
Node *reverse(Node *root)
{
    Node *first,*temp,*curr;
    first=root;
    curr=NULL;
    while (first!=NULL)
    {
        temp=first->add;
        first->add=curr;
        curr=first;
        first=temp;
    }
    root=curr;
    return root;
}
Node *update(Node *root,int item,int ele)
{
    Node *temp;
    if (root==NULL)
    {
        printf("List is empty\n");
        return root;
    }
    if (root->info==item)
    {
        root->info=ele;
        return root;
    }
    
        temp=root;
        while (temp!=NULL && temp->info!=item)
        {
            temp=temp->add;
        }
        if (temp==NULL)
        {
            printf("%d not found in the list\n",item);
            return root;
        }
        
        else if (temp->info==item)
        {
            temp->info=ele;
            return root;
        }
        return root;
}



void disp(Node *root)
{
    if (root==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while (root!=NULL)
        {
            printf("%d->",root->info);
            root=root->add;
        }
        
    }
    return;
}

Node *sort(Node *root)
{
    if (root==NULL)
    {
        printf("List empty\n");
        return NULL;
    }
    Node *cur,*next;
    int i,j,temp,flag=0;

    for (i = 0; i < count(root); i++)
    {
        cur=root;
        next=root->add;
        for ( j = 0; j< count(root); j++)
        {
            if (next->info>cur->info)
            {
                temp=cur->info;
                cur->info=next->info;
                next->info=temp;
                flag=1;
            }
            cur=cur->add;
            next=next->add;
        }
        if (flag==0)
        {
            return root;
        }
        
        
    }
    return root;
    
}

void dispmiddle(Node *root)
{
    Node *fast=root;
    Node *slow=root;
    if (root!=NULL)
    {
        while (fast!=NULL && fast->add!=NULL)
        {
            fast=fast->add->add;
            slow=slow->add;
        }
        printf("The middle element is %d\n",slow->info);   
    }
    
}

int sumnodes(Node *root)
{
    int sum=0;
    if (root==NULL)
    {
        printf("List empty\n");
        sum=0;
    }
    else
    {
        while (root!=NULL)
        {
            sum=(sum+(root->info));
            root=root->add;
        }
        
    }
    return sum;
}

int main()
{
    Node *root=NULL,*nw,*second=NULL;
    int ch,pos,item,index,key,size,sum;
    while (1)
    {
        printf("\n-----IMPLEMENTATION OF SLL-----\n");
        printf("1.Insert front\n");
        printf("2.Insert rear\n");
        printf("3.Insert at pos\n");
        printf("4.Delete front\n");
        printf("5.Delete rear\n");
        printf("6.Delete at pos\n");
        printf("7.Display\n");
        printf("8.Reverse\n");
        printf("9.Search\n");
        printf("10.Update\n");
        printf("11.Copy\n");
        printf("12.Find middle ele\n");
        printf("13.Count\n");
        printf("14.Sum of all nodes\n");
        printf("15.Sort\n");
        printf("16.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            nw=createnode();
            root=insertfront(root,nw);
            break;
        case 2:
            nw=createnode();
            root=insertrear(root,nw);
            break;
        case 3:
            nw=createnode();
            do
            {
                printf("Enter pos:");
                scanf("%d",&pos);
            } while (pos<1);
            root=insertatpos(root,nw,pos);
            break;
            
        case 4:
            root=deletefront(root);
            break;
        case 5:
            root=deleterear(root);
            break;
        case 6:
            do
            {
                printf("Enter pos:");
                scanf("%d",&pos);
            } while (pos<1);
            root=delatpos(root,pos);
            break;
        case 7:
            disp(root);
            break;
        case 8:
            root=reverse(root);
            break;
        case 9:
            printf("Enter Item to search:");
            scanf("%d",&item);
            root=search(root,item);
            break;
        case 10:
            printf("Enter item to replace:");
            scanf("%d",&item);
            printf("Enter ele to be updated");
            scanf("%d",&key);
            root=update(root,item,key);
            break;
        case 12:
            dispmiddle(root);
            break;
        case 13:
            size=count(root);
            printf("Size is %d",size);
            break;
        case 14:
            sum=sumnodes(root);
            printf("sum is %d",sum);
            break;
        case 15:
            root=sort(root);
            break;
        default:
            exit(1);
            break;
        }
    }
    

}