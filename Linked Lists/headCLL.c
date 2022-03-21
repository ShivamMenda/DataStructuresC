#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int info;
    struct node *link;
};

typedef struct node *NODE;

NODE create()
{
    NODE last;
    last=(NODE)malloc(sizeof(struct node));
    if (last==NULL)
    {
        printf("Memory Error!");
        exit(0);
    }
    last->link=last;
    return last;
}

NODE insert_front(NODE head,int item)
{
    NODE new;
    new=create();
    new->info=item;
    new->link=head->link;
    head->link=new;
    head->info++;
    return head;
}

NODE insert_rear(NODE head,int item)
{
    NODE new,cur;
    new=create();
    new->info=item;
    cur=head->link;
    while (cur->link!=head)
    {
        cur=cur->link;
    }
    new->link=head;
    cur->link=new;
    head->info++;
    return head;
}

NODE delete_front(NODE head)
{
    NODE temp;
    if (head->link==head)
    {
        printf("List is empty\n");
        return head;
    }
    temp=head->link;
    head->link=temp->link;
    free(temp);
    head->info--;
    return head;
}

NODE delete_rear(NODE head)
{
    NODE cur,prev;
    if (head->link==head)
    {
        printf("List is empty\n");
        return head;
    }
    cur=head->link;
    prev=head;
    while (cur->link!=head)
    {
        prev=cur;
        cur=cur->link;
    }
    prev->link=cur->link;
    free(cur);
    head->info--;
    return head;
}

NODE insert_pos(NODE head, int pos, int item)
{
    NODE temp,prev,new;
    int i;
    new=create();
    new->info=item;
    if(pos<1 || pos>(head->info+1))
    {
        printf("Invalid Position\n");
        return head;
    }
    prev=head;
    temp=head->link;
    for (i=1;i<pos;i++)
    {
        prev=temp;
        temp=temp->link;
    }
    new->link=temp;
    prev->link=new;
    head->info++;
    return head;
}

NODE delete_pos(NODE head, int pos)
{
    NODE temp,prev;
    int i;
    if (pos<1 || pos>(head->info))
    {
        printf("Invalid Position\n");
        return head;
    }
    prev=head;
    temp=head->link;
    for ( i = 1; i < pos; i++)
    {
        prev=temp;
        temp=temp->link;
    }
    prev->link=temp->link;
    head->info--;
    return head;
}

NODE delete_key(NODE head, int key)
{
    NODE temp,prev;
    if (head->link==head)
    {
        printf("List is empty\n");
        return head;
    }
    temp=head->link;
    prev=NULL;
    if (temp->info==key)
    {
        head->link=temp->link;
        free(temp);
        head->info--;
        return head;
    }
    while (temp!=head && temp->info!=key)
    {
        prev=temp;
        temp=temp->link;
    }
    if(temp==head)
    {
        printf("%d not found in the list\n",key);
        return head;
    }
    else
    {
        prev->link=temp->link;
        free (temp);
        head->info--;
        return head;
    }
}

NODE reverse(NODE head)
{
    NODE temp,cur,t,p;
    t=head->link;
    cur=NULL;
    while (t!=head)
    {
        temp=t;
        t=t->link;
        temp->link=cur;
        if (temp->link==NULL)
        {
            p=temp;
        }
        cur=temp;
        head->link=cur;
    }
    p->link=head;
    return head;
}

void display(NODE head)
{
    NODE temp;
    temp=head->link;
    if (head->link==head)
    {
        printf("List is empty\n");
        return ;
    }
    printf("The Elements of the list are: ");
    while (temp!=head)
    {
        printf("%d -> ",temp->info);
        temp=temp->link;
    }
    return ;
}

NODE search(NODE head, int key)
{
    NODE temp;
    int pos=1;
    if (head->link==head)
    {
        printf("List is empty\n");
        return head;
    }
    temp=head->link;
    if (temp->info==key)
    {
        pos=1;
        printf("Search Successful and key found in position %d\n",pos);
        return head;
    }
    while(temp!=head && temp->info!=key)
    {
        temp=temp->link;
        pos++;
    }
    if (temp==head)
    {
        printf("Search Unsuccessful\n");
        return head;
    }
    else
    {
        printf("Search Successful and key found in position %d\n",pos);
        return head;
    }
}
int main()
{
    int choice;
    int ele,pos,new_ele;
    NODE head=NULL,second=NULL;
    head=create();
    head->info=0;
    for (;;)
    {
        printf("\n1.Display\n2.Insert from front\n3.Insert from rear\n4.Insert at a Position\n5.Delete from front\n6.Delete from rear\n7.Delete by Position\n8.Delete By Element\n9.Reverse\n10.Search\n11.Copy\n12.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: display(head);
                    break;
            case 2: printf("Enter the element to be inserted: ");
                    scanf("%d",&ele);
                    head=insert_front(head,ele);
                    display(head);
                    break;
            case 3: printf("Enter the element to be inserted: ");
                    scanf("%d",&ele);
                    head=insert_rear(head,ele);
                    display(head);
                    break;
            case 4: printf("Enter the element to be inserted and position: ");
                    scanf("%d",&ele);
                    scanf("%d",&pos);
                    head=insert_pos(head,pos,ele);
                    display(head);
                    break;
            case 5: head=delete_front(head);
                    display(head);
                    break;
            case 6: head=delete_rear(head);
                    display(head);
                    break;
            case 7: printf("Enter the position from which the element is to be deleted: ");
                    scanf("%d",&pos);
                    head=delete_pos(head,pos);
                    display(head);
                    break;
            case 8: printf("Enter the Element to be Deleted: ");
                    scanf("%d",&ele);
                    head=delete_key(head,ele);
                    display(head);
                    break;
            case 9: printf("The Reversed List is: \n");
                    head=reverse(head);
                    display(head);
                    break;
            case 10:printf("Enter the key to be searched: ");
                    scanf("%d",&ele);
                    head=search(head,ele);
                    display(head);
                    break;
            default: exit(0);
        }
    }
}