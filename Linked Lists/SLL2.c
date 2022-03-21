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
    NODE first;
    first = (NODE) malloc (sizeof(struct node));
    if (first==NULL) 
    {
        printf("Memory Error!");
        exit (0);
    }
    first -> link = NULL;
    return first;
}

NODE insert_front(NODE first, int item)
{
    NODE temp;
    temp=create();
    temp -> info = item;
    if (first == NULL)
    {
        return temp;
    }
    temp -> link = first;
    return temp;
}

NODE insert_rear(NODE first,int item)
{
    NODE temp,ptr;
    temp=create();
    temp ->info=item;
    if (first == NULL) 
    {
        return temp;
    }
    else
    {
        ptr = first;
        while (ptr!=NULL && ptr->link!=NULL)
        {
            ptr = ptr ->link;
        }
        ptr ->link=temp;
        return first;
    }
}

NODE delete_front(NODE first)
{
    NODE temp;
    if (first == NULL)
    {
        printf("The list is empty\n");
        return NULL;
    }
    temp=first;
    first = first -> link;
    printf("The deleted node is %d",temp->info);
    free(temp);
    return first;
}

NODE delete_rear(NODE first)
{
    NODE cur,prev;
    if (first == NULL)
    {
        printf("The list is empty\n");
        return NULL;
    }
    if (first->link==NULL)
    {
        printf("The deleted node is %d",first->info);
        free(first);
        return NULL;
    }
    cur = first;
    prev=NULL;
    while (cur -> link !=NULL)
    {
        prev=cur;
        cur = cur -> link;
    }
    prev -> link = NULL;
    printf("The deleted node is %d",cur->info);
    free(cur);
    return first;
}

void display(NODE first)
{
    NODE temp;
    if (first==NULL)
    {
        printf("List is empty\n");
        return ;
    }
    else
    {
        temp=first;
        while(temp!=NULL)
        {
            printf("%d\t",temp->info);
            temp=temp->link;
        }
        return ;
    }
}

// Inserting a node in a specified position

NODE insert_pos(NODE x,int pos,int item)
{
    NODE new,prev,cur,ptr;
    int i=1,count=1;
    ptr=x;
    while (ptr!=NULL && ptr->link!=NULL)
    {
        ptr = ptr ->link;
        count++;
    }
    printf("%d\n",count);
    if (pos<1 || pos>count+1)
    {
        printf("Invalid Position\n");
        return x;
    }
    new=create();
    new->info=item;
    if (pos==1)
    {
        new->link=x;
        count++;
        return new;
    }
    prev=NULL;
    cur=x;
    while (i<pos)
    {
        prev=cur;
        cur=cur->link;
        i++;
    }
    new->link=cur;
    prev->link=new;
    count++;
    return x;
}

// Deleting a node in a specified position

NODE delete_pos(NODE x,int pos)
{
    NODE temp,cur,prev,ptr;
    int i=1,count=1;
    ptr=x;
    while (ptr!=NULL && ptr->link!=NULL)
    {
        ptr = ptr ->link;
        count++;
    }
    printf("%d\n",count);
    if (pos<1 || pos>count)
    {
        printf("Invalid Position\n");
        return x;
    }
    if (pos==1)
    {
        temp=x;
        x=x->link;
        printf("Deleted Element is %d",temp->info);
        free(temp);
        count--;
        return x;
    }
    cur=x;
    prev=NULL;
    while(i<pos)
    {
        prev=cur;
        cur=cur->link;
        i++;
    }
    prev->link=cur->link;
    free(cur);
    count--;
    return x;
}

NODE reverse(NODE x)
{
    NODE temp,cur;
    cur=NULL;
    while(x!=NULL)
    {
        temp=x;
        x=x->link;
        temp->link=cur;
        cur=temp;
    }
    return cur;
}

NODE update(NODE x,int key,int item)
{
    NODE temp;
    if (x==NULL)
    {
        printf("List is Empty\n");
        return x;
    }
    temp=x;
    while(temp->info!=key && temp!=NULL)
    {
        temp=temp->link;
    }
    if (temp==NULL)
    {
        printf("%d not found in the list.",key);
        return x;
    }
    else 
    {
        temp->info=item;
        return x;
    }
}

NODE delete_key(NODE x,int key)
{
    NODE temp,prev;
    if(x==NULL)
    {
        printf("List is Empty\n");
        return x;
    }
    temp=x;
    prev=NULL;
    while (temp->info!=key && temp!=NULL)
    {
        prev=temp;
        temp=temp->link;
    }
    if(temp==NULL)
    {
        printf("%d not found in the list.",key);
        return x;
    }
    else
    {
        prev->link=temp->link;
        return x;
    }
}

NODE search(NODE x,int key)
{
    int pos=1;
    NODE temp;
    if (x==NULL)
    {
        printf("List is empty\n");
        return x;
    }
    if (key==x->info)
    {
        pos=1;
        printf("Search Successful and key foung in position %d",pos);
        return x;
    }
    temp=x;
    while(temp!=NULL && temp->info!=key)
    {
        temp=temp->link;
        pos++;
    }
    if (temp==NULL)
    {
        printf("Search Unsuccessful\n");
        return x;
    }
    else
    {
        printf("Search Successful and key found in position %d",pos);
        return x;
    }
}

NODE ordered_list(NODE x,int item)
{
    NODE new,prev,cur;
    new=create();
    new->info=item;
    if (x==NULL)
    {
        return new;
    }
    if (item<x->info)
    {
        new->link=x;
        return new;
    }
    prev=NULL;
    cur=x;
    while(cur->link!=NULL && item>(cur->info))
    {
        prev=cur;
        cur=cur->link;
    }
    if (cur->link==NULL)
    {
        cur->link=new;
    }
    else
    {
        prev->link=new;
        new->link=cur;
    }
    return x;
}

int main()
{
    int choice;
    int ele,pos,new_ele;
    NODE first=NULL;
    for (;;)
    {
        printf("\n1.Display\n2.Insert from front\n3.Insert from rear\n4.Insert at a Position\n5.Delete from front\n6.Delete from rear\n7.Delete by Position\n8.Delete By Element\n9.Reverse\n10.Update\n11.Search\n12.Ordered List\n13.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: display(first);
                    break;
            case 2: printf("Enter the element to be inserted: ");
                    scanf("%d",&ele);
                    first=insert_front(first,ele);
                    break;
            case 3: printf("Enter the element to be inserted: ");
                    scanf("%d",&ele);
                    first=insert_rear(first,ele);
                    break;
            case 4: printf("Enter the element to be inserted and position: ");
                    scanf("%d",&ele);
                    scanf("%d",&pos);
                    first=insert_pos(first,pos,ele);
                    break;
            case 5: first=delete_front(first);
                    break;
            case 6: first=delete_rear(first);
                    break;
            case 7: printf("Enter the position for the element to be deleted: ");
                    scanf("%d",&pos);
                    first=delete_pos(first,pos);
                    break;
            case 8: printf("Enter the Element to be Deleted: ");
                    scanf("%d",&ele);
                    first=delete_key(first,ele);
                    break;
            case 9: printf("The Reversed List is: \n");
                    first=reverse(first);
                    break;
            case 10:printf("Enter the Element to be Replaced: ");
                    scanf("%d",&ele);
                    printf("Enter the new element: ");
                    scanf("%d",&new_ele);
                    first=update(first,ele,new_ele);
                    break;
            case 11:printf("Enter the key to be found: ");
                    scanf("%d",&ele);
                    first=search(first,ele);
                    break;
            case 12:printf("Enter the element to be inserted: ");
                    scanf("%d",&ele);
                    first=ordered_list(first,ele);
                    break;
            default: exit(0);
        }
    }
}