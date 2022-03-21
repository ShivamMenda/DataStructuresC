#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};

typedef struct node * NODE;

NODE create()
{
    NODE new;
    new=(NODE)malloc(sizeof(struct node));
    if (new==NULL)
    {
        printf("Memory Error!");
        exit(0);
    }
    new->llink=new;
    new->rlink=new;
    return new;
}

NODE insert_front(NODE head, int item)
{
    NODE new,cur;
    new=create();
    new->info=item;
    cur=head->rlink;
    new->rlink=cur;
    cur->llink=new;
    head->rlink=new;
    new->llink=head;
    head->info++;
    return head;
}

NODE insert_rear(NODE head, int item)
{
    NODE new,cur;
    new=create();
    new->info=item;
    cur=head->llink;
    cur->rlink=new;
    new->llink=cur;
    head->llink=new;
    new->rlink=head;
    head->info++;
    return head;
}

NODE delete_front(NODE head)
{
    NODE cur;
    if (head->rlink==head)
    {
        printf("List is empty\n");
        return head;
    }
    cur=head->rlink;
    head->rlink=cur->rlink;
    (cur->rlink)->llink=head;
    printf("The deleted node is %d\n",cur->info);
    free(cur);
    head->info--;
    return head;
}

NODE delete_rear(NODE head)
{
    NODE cur;
    if (head->rlink==head)
    {
        printf("List is empty\n");
        return head;
    }
    cur=head->llink;
    head->llink=cur->llink;
    (cur->llink)->rlink=head;
    printf("The deleted node is %d\n",cur->info);
    free(cur);
    head->info--;
    return head;
}

void display(NODE head)
{
    NODE temp;
    temp=head->rlink;
    if (head->rlink==head)
    {
        printf("List is empty\n");
        return ;
    }
    printf("The Elements of the list are: ");
    while (temp!=head)
    {
        printf("%d -> ",temp->info);
        temp=temp->rlink;
    }
    return ;
}

NODE insert_pos(NODE head, int pos, int item)
{
    NODE cur,prev,new;
    int i;
    new=create();
    new->info=item;
    if(pos<1 || pos>(head->info+1))
    {
        printf("Invalid Position\n");
        return head;
    }
    prev=head;
    cur=head->rlink;
    for (i=1;i<pos;i++)
    {
        prev=cur;
        cur=cur->rlink;
    }
    new->rlink=cur;
    prev->rlink=new;
    cur->llink=new;
    new->llink=prev;
    head->info++;
    return head;
}

NODE delete_pos(NODE head, int pos)
{
    NODE cur,prev;
    int i;
    if (pos<1 || pos>(head->info))
    {
        printf("Invalid Position\n");
        return head;
    }
    prev=head;
    cur=head->rlink;
    for ( i = 1; i < pos; i++)
    {
        prev=cur;
        cur=cur->rlink;
    }
    prev->rlink=cur->rlink;
    (cur->rlink)->llink=prev;
    printf("The deleted node is %d\n",cur->info);
    free(cur);
    head->info--;
    return head;
}

NODE delete_key(NODE head, int key)
{
    NODE cur, prev, next;
    cur=head->rlink;
    while (key!=cur->info && cur!=head)
    {
        cur=cur->rlink;
    }
    if (cur==head)
    {
        printf("Element not found\n");
        return head;
    }
    prev=cur->llink;
    next=cur->rlink;
    prev->rlink=next;
    next->llink=prev;
    free(cur);
    head->info--;
    return head;
}

NODE reverse(NODE head)
{
    NODE t, cur, p, temp;
    cur=p=NULL;
    t=head->rlink;
    while (t!=head)
    {
        temp=t;
        t=t->rlink;
        temp->rlink=cur;
        if (temp->rlink==NULL)
        {
            p=temp;
            p->llink=temp;
        }
        head->rlink=temp;
        temp->llink=head;
        cur=temp;
        cur->llink=temp;
    }
    head->llink=p;
    p->rlink=head;
    return head;
}

NODE search(NODE head, int key)
{
    NODE temp;
    int pos=1;
    if (head->rlink==head)
    {
        printf("List is empty\n");
        return head;
    }
    temp=head->rlink;
    if (temp->info==key)
    {
        pos=1;
        printf("Search Successful and key found in position %d\n",pos);
        return head;
    }
    while(temp!=head && temp->info!=key)
    {
        temp=temp->rlink;
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

NODE copy(NODE second, NODE head)
{
    NODE temp,cur,n;
    if (head->rlink==head)
    {
        printf("List is empty\n");
        return head;
    }
    cur=head;
    if (second==NULL)
    {
        second=create();
        second->info=0;

    }
    second->info=cur->info;
    cur=cur->rlink;
    n=second; 
    while(cur!=head)
    {
        temp=create(); 
        temp->info=cur->info; 
        n->rlink=temp;   
        temp->llink=n;
        n=n->rlink;      
        cur=cur->rlink;
    }
    n->rlink = second;   
    second->llink=n;
    return second;
}

NODE ordered_list(NODE head,int item)
{
    NODE temp,cur,prev,first;
    temp=create();
    temp->info=item;
    first=head->rlink;
    if (head->rlink==head)
    {
        head->rlink=temp;
        temp->llink=head;
        temp->rlink=head;
        head->llink=temp;
        head->info++;
        return head;
    }
    if (temp->info<first->info)
    {
        temp->rlink=first;
        first->llink=temp;
        temp->llink=head;
        head->rlink=temp;
        head->info++;
        return head;
    }
    prev=head;
    cur=head->rlink;
    while (cur!=head && temp->info>cur->info)
    {
        prev=cur;
        cur=cur->rlink;
    }
    prev->rlink=temp;
    temp->llink=prev;
    temp->rlink=cur;
    cur->llink=temp;
    head->info++;
    return head;
}


void main()
{
    int choice;
    int ele,pos,new_ele;
    NODE head=NULL,second=NULL;
    head=create();
    head->info=0;
    for (;;)
    {
        printf("\n1.Display\n2.Insert from front\n3.Insert from rear\n4.Insert at a Position\n5.Delete from front\n6.Delete from rear\n7.Delete by Position\n8.Delete By Element\n9.Reverse\n10.Search\n11.Copy\n12.Ordered List\n13.Exit\n");
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
            case 11:printf("The copied list is: \n");
                    second=copy(second,head);
                    display(second);
                    break;
            case 12:printf("Enter the element to be inserted in order: ");
                    scanf("%d",&ele);
                    head=ordered_list(head,ele);
                    display(head);
                    break;
            default: exit(0);
        }
    }
}