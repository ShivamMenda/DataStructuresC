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
    Node *temp;
    temp=(Node *)malloc(sizeof(Node));
    printf("Enter info:");
    scanf("%d",&temp->info);
    temp->add=NULL;
    return temp;
}
Node *reverse(Node *root){
    Node *first,*curr,*temp;
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
int get(Node *root,int index){
    Node *temp;
    int count=0;
    if (root==NULL)
    {
        printf("List is empty\n");
        return -1;
    }
    temp=root;
    while (temp!=NULL)
    {
        if (count==index)
        {
            return(temp->info);
        }
        count++;
        temp=temp->add;
        
    }
    return -1;
    
}

Node *insertfront(Node *root,Node *nw){
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
Node *insertrear(Node *root,Node *nw){
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

Node *insertatpos(Node *root,Node *nw,int pos){
    Node *temp;
    int i;
    if (root==NULL)
    {
        root=nw;
    }
    else if (pos==1)
    {
        nw->add=root;
        root=nw;
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
    }

    return root;
}

Node *delfront(Node *root)
{
    Node *temp;
    if (root==NULL)
    {
        printf("No nodes to be deleted\n");
    }
    else
    {
        temp=root;
        printf("The deleted node is with info %d\n",temp->info);
        root=root->add;
        free(temp);
    }
    return root;
}
Node *delatpos(Node *root,int pos){
    Node *temp,*next;
    int i;
    if (root==NULL)
    {
        printf("nodes do not exist\n");
    }
    else if (pos==1)
    {
       temp=root;
       printf("Deleted node is %d\n",temp->info);
       root=root->add;
       free(temp);
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
            printf("Cannot delete at pos=%d\n",pos);
        }
        else
        {
            temp->add=next->add;
            printf("Deleted node is %d\n",next->info);
            free(next);
        }
        
    }

    return root;
}

Node *delrear(Node *root)
{
    Node *temp,*prev;
    if (root==NULL)
    {
        printf("No nodes to be deleted\n");
    }
    else if (root->add==NULL)
    {
        printf("Deleted node with info %d\n",root->info);
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
       printf("deleted node is %d\n",temp->info);
       free(temp);
    }
    return root;
}
void disp(Node *root)
{
    if(root==NULL){
        printf("List is empty\n");
    }
    else
    {
        while (root!=NULL)
        {
            printf("%d->",root->info);
            root=root->add;
        }
        printf("\n");
        
    }
    
}

int main()
{
    Node *root=NULL,*nw;
    int ch,pos,index,res;
    while (1)
    {
        printf("Implemetation of SLL\n");
        printf("1.Insert at front\n");
        printf("2.Insert at rear\n");
        printf("3.Display the nodes\n");
        printf("4.Delete at front\n");
        printf("5.Delete at rear\n");
        printf("6.Insert at desired pos\n");
        printf("7.Delete at desired pos\n");
        printf("8.Reverse\n");
        printf("9.Get nth node info\n");
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
            disp(root);
            break;
        case 4:
            root=delfront(root);
            break;
        case 5:
            root=delrear(root);
            break;
        case 6:
            nw=createnode();
            do
            {
                printf("Enter the pos");
                scanf("%d",&pos);
            } while (pos<1);
            root=insertatpos(root,nw,pos);
            break;
        case 7:
            do
            {
                printf("Enter the pos");
                scanf("%d",&pos);
            } while (pos<1);
            root=delatpos(root,pos);
            break;

            
        case 8:
            root=reverse(root);
            break;
        case 9:
            printf("enter Index:");
            scanf("%d",&index);
            res=get(root,index);
            res!=-1?printf("%d\n",res):printf("Not found\n");
            break;
        
        default:
            exit(1);
            break;
        }
    }
}
