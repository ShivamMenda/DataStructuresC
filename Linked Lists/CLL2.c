#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

typedef struct node * NODE;

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

NODE insert_front(NODE last, int item)
{
    NODE new;
    new=create();
    new->info=item;
    if (last==NULL)
    {
        return new;
    }
    new->link=last->link;
    last->link=new;
    return last;
}

NODE insert_rear(NODE last, int item)
{
    NODE new;
    new=create();
    new->info=item;
    if (last==NULL)
    {
        return new;
    }
    new->link=last->link;
    last->link=new;
    return new;
}

NODE insert_pos(NODE last, int pos, int item)
{
    NODE new,temp,temp1,ptr;
    int i=1,count=1;
    ptr=last;
    new=create();
    new->info=item;
    if (last==NULL)
    {
        return new;
    }
    while (ptr->link!=last)
    {
        ptr = ptr ->link;
        count++;
    }
    if (pos<1 || pos>count+1)
    {
        printf("Invalid Position\n");
        return last;
    }
    
    if(pos==1)
    {
        new->link=last->link;
        last->link=new;
        return last;
    }
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
    if (pos==count+1)
    {
        last=last->link;
    }
    return last;
}

NODE delete_pos(NODE last,int pos)
{
    NODE cur,prev,ptr;
    int i=1,count=1;
    ptr=last;
    if (last==NULL)
    {
        printf("List is empty\n");
        return last;
    }
    while (ptr->link!=last)
    {
        ptr = ptr ->link;
        count++;
    }
    if (pos<1 || pos>count)
    {
        printf("Invalid Position\n");
        return last;
    }
    if (pos==1)
    {
        cur=last->link;
        last->link=cur->link;
        printf("The deleted node is %d\n",cur->info);
        free(cur);
        return last;
    }
    cur=last->link;
    prev=last;
    while (i<pos)
    {
        prev=cur;
        cur=cur->link;
        i++;
    }
    if (cur==last)
    {
        last=prev;
    }
    prev->link=cur->link;
    printf("The deleted node is %d\n",cur->info);
    free(cur);
    return last;
}

NODE delete_front(NODE last)
{
    NODE temp,new;
    if (last==NULL)
    {
        printf("List is empty\n");
        return last;
    }
    if (last->link==last)
    {
        printf("The deleted node is %d",last->info);
        free(last);
        return NULL;
    }
    new=last->link;
    last->link=new->link;
    free(new);
    return last;
}

NODE delete_rear(NODE last)
{
    NODE temp;
    if (last==NULL)
    {
        printf("List is empty\n");
        return last;
    }
    if (last->link==last)
    {
        printf("The deleted node is %d",last->info);
        free(last);
        return NULL;
    }
    temp=last->link;
    while (temp->link!=last)
    {
        temp=temp->link;
    }
    temp->link=last->link;
    free(last);
    return temp;
}

void display(NODE last)
{
    if (last==NULL)
    {
        printf("List is empty\n");
        return ;
    }
    
    NODE temp;
    temp=last->link;
    do
    {
        printf("%d -> ",temp->info);
        temp=temp->link;
    } while (temp!=last->link);
    return ;
}

NODE update(NODE last,int key,int item)
{
    NODE temp;
    if (last==NULL)
    {
        printf("List is Empty\n");
        return last;
    }
    temp=last;
    
    if (temp->info==key)
    {
        temp->info=item;
        return last;
    }
    while (temp->link!=last)
    {
        if (temp->info==key)
        {
            temp->info = item;
            return last;
        }
        temp=temp->link;

    }
    printf("%d not found in the list\n",key);
    return last;
}

NODE reverse(NODE last)
{
    NODE head,cur,prev,temp;
    if (last==NULL)
    {
        printf("List is empty\n");
        return last;
    }
    temp=last->link;
    head=last->link;
    cur=head->link;
    prev=head;
    head=head->link;
    while (head!=temp)
    {
        head=head->link;
        cur->link=prev;
        prev=cur;
        cur=head;
        cur->link=prev;
        head=prev;
        
    }
    return prev;
}

NODE delete_key(NODE last,int key)
{
    NODE temp,prev;
    if(last==NULL)
    {
        printf("List is Empty\n");
        return last;
    }
    if (last->info==key)
    {
        temp=last;
        last=last->link;
        free(temp);
        return last;
    }
    temp=last;
    prev=NULL;
    while (temp->link!=last && temp->info!=key)
    {
        prev=temp;
        temp=temp->link;
    }
    if(temp==last)
    {
        printf("%d not found in the list\n",key);
        return last;
    }
    else
    {
        prev->link=temp->link;
        free (temp);
        return last;
    }
}

NODE search(NODE last,int key)
{
    int pos=1;
    NODE temp;
    if (last==NULL)
    {
        printf("List is empty\n");
        return last;
    }
    if (key==last->info)
    {
        pos=1;
        printf("Search Successful and key foung in position %d\n",pos);
        return last;
    }
    temp=last;
    while(temp->link!=last && temp->info!=key)
    {
        temp=temp->link;
        pos++;
    }
    if (temp==last)
    {
        printf("Search Unsuccessful\n");
        return last;
    }
    else
    {
        printf("Search Successful and key found in position %d\n",pos);
        return last;
    }
}

NODE copy(NODE second,NODE last)
{
    NODE temp,cur,prev;
    if (last==NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    cur=last->link;
    temp=create();
    temp->info=cur->info;
    temp->link=cur->link;
    cur=cur->link;
    second=temp;
    prev=second;
    while(cur->link!=last)
    {
        temp=create();
        temp->info=cur->info;
        prev->link=temp;
        cur=cur->link;
        prev=prev->link;
    }
    return second;
}

void main()
{
    int choice;
    int ele,pos,new_ele;
    NODE last=NULL,second=NULL;
    for(;;)
    {
        printf("\n1.Display\n2.Insert from front\n3.Insert from rear\n4.Insert by Position\n5.Delete from front\n6.Delete from rear\n7.Delete by Position\n8.Delete By Element\n9.Reverse\n10.Update\n11.Search\n12.Copy\n13.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: display(last);
                    break;
            case 2: printf("Enter the elements to be inserted: ");
                    scanf("%d",&ele);
                    last=insert_front(last,ele);
                    display(last);
                    break;
            case 3: printf("Enter the elements to be inserted: ");
                    scanf("%d",&ele);
                    last=insert_rear(last,ele);
                    display(last);
                    break;
            case 4: printf("Enter the element and position: ");
                    scanf("%d %d",&ele,&pos);
                    last=insert_pos(last,pos,ele);
                    display(last);
                    break;
            case 5: last=delete_front(last);
                    display(last);
                    break;
            case 6: last=delete_rear(last);
                    display(last);
                    break;
            case 7: printf("Enter the position: ");
                    scanf("%d",&pos);
                    last=delete_pos(last,pos);
                    display(last);
                    break;
            case 8: printf("Enter the Element to be Deleted: ");
                    scanf("%d",&ele);
                    last=delete_key(last,ele);
                    display(last);
                    break;
            case 9: printf("The Reversed List is: \n");
                    last=reverse(last);
                    display(last);
                    break;
            case 10:printf("Enter the Element to be Replaced: ");
                    scanf("%d",&ele);
                    printf("Enter the new element: ");
                    scanf("%d",&new_ele);
                    last=update(last,ele,new_ele);
                    display(last);
                    break;
            case 11:printf("Enter the key to be searched: ");
                    scanf("%d",&ele);
                    last=search(last,ele);
                    display(last);
                    break;;
            case 12:printf("The copied list is: \n");
                    second=copy(second,last);
                    display(second);
                    break;
            default:exit(0);
        }
    }
}