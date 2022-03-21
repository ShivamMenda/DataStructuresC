#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

typedef struct node Node;

Node *create()
{
    Node *last;
    last=(Node *)malloc(sizeof(Node));
    printf("Enter info:");
    scanf("%d",&last->info);
    last->link=last;
    return last;
}

Node *insertfront(Node *last)
{
    Node *new;
    new=create();
    if (last==NULL)
    {
        return new;
    }
    new->link=last->link;
    last->link=new;
    return last;
}

Node *insertrear(Node *last)
{
    Node *new;
    new=create();
    if (last==NULL)
    {
        return new;
    }
    new->link=last->link;
    last->link=new;
    return new;
}

Node *delfront(Node *last)
{
    Node *temp;
    if (last==NULL)
    {
        return last;
    }
    else if (last->link==last)
    {
        printf("The deleted node is %d\n",last->info);
        free(last);
        return NULL;
    }
    
    else
    {
        temp=last->link;
        last->link=temp->link;
        printf("The deleted node is %d\n",temp->info);
        free(temp);
        return last;
    }
    return last;
}

Node *delrear(Node *last)
{
    Node *temp;
    if (last==NULL)
    {
        return last;
    }
    else if (last->link==last)
    {
        printf("The deleted node is %d\n",last->info);
        free(last);
        return NULL;
    }
    
    else
    {
        temp=last->link;
        while (temp->link!=last)
        {
            temp=temp->link;
        }
        temp->link=last->link;
        printf("The deleted node is %d\n",last->info);
        free(last);
        return temp;
    }
    
}
Node *insertpos(Node *last,int pos)
{
    Node *ptr,*temp,*temp1,*new;
    int i=1,count=1;
    new=create();
    if (last==NULL)
    {
       return new;
    }
    ptr=last;
    while (ptr->link!=last)
    {
        ptr=ptr->link;
        count++;
    }
    if (pos<1 ||pos>count+1)
    {
        printf("Invalid pos\n");
        return last;
    }
    if (pos==1)
    {
        new->link=last->link;
        last->link=new;
        return last;
    }
    else
    {
        temp=last->link;
        temp1=last;
        while (i<pos)
        {
            temp1=temp;
            temp=temp->link;
            i++;
        }
        temp1->link=new;
        new->link=temp;
        return last;
        if (pos==count+1)
        {
           last=last->link;
        }
        return last;
    }   
       
    
}





void display(Node *last)
{
    Node *temp;
    if (last==NULL)
    {
        printf("List empty\n");
    }
    else
    {
        temp=last->link;
        do
        {
            printf("%d->",temp->info);
            temp=temp->link;
        } while (temp!=last->link);
        
    }
}


int main()
{
    int choice;
    int ele,pos,new_ele;
    Node *last=NULL,*second=NULL;
    for(;;)
    {
        printf("\n1.Display\n2.Insert from front\n3.Insert from rear\n4.Insert by Position\n5.Delete from front\n6.Delete from rear\n7.Delete by Position\n8.Delete By Element\n9.Reverse\n10.Update\n11.Search\n12.Copy\n13.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: display(last);
                    break;
            case 2: last=insertfront(last);
                    display(last);
                    break;
            case 3:last=insertrear(last);
                    display(last);
                    break;
            case 4: printf("Enter position: ");
                    scanf("%d",&pos);
                    last=insertpos(last,pos);
                    display(last);
                    break;
            case 5: last=delfront(last);
                    display(last);
                    break;
            case 6: last=delrear(last);
                    display(last);
                    break;
            // case 7: printf("Enter the position: ");
            //         scanf("%d",&pos);
            //         last=delete_pos(last,pos);
            //         display(last);
            //         break;
            // case 8: printf("Enter the Element to be Deleted: ");
            //         scanf("%d",&ele);
            //         last=delete_key(last,ele);
            //         display(last);
            //         break;
            // case 9: printf("The Reversed List is: \n");
            //         last=reverse(last);
            //         display(last);
            //         break;
            // case 10:printf("Enter the Element to be Replaced: ");
            //         scanf("%d",&ele);
            //         printf("Enter the new element: ");
            //         scanf("%d",&new_ele);
            //         last=update(last,ele,new_ele);
            //         display(last);
            //         break;
            // case 11:printf("Enter the key to be searched: ");
            //         scanf("%d",&ele);
            //         last=search(last,ele);
            //         display(last);
            //         break;;
            // case 12:printf("The copied list is: \n");
            //         second=copy(second,last);
            //         display(second);
            //         break;
            default:exit(0);
        }
    }
}