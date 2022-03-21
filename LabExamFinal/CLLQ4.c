#include<stdio.h>
#include<stdlib.h>

int count=0;

struct node
{
    int data;
    struct node *add;
};

typedef struct node Node;

Node *create()
{
    Node *new;
    new=(Node *)malloc(sizeof(Node));
    printf("Enter data:");
    scanf("%d",&(new->data));
    new->add=new;
    return new;
}

void display(Node *last)
{
    Node *temp;
    if(last==NULL)
    {
        printf("List empty\n");
    }
    else
    {
        temp=last->add;
        do
        {
            printf("%d->",temp->data);
            temp=temp->add;
        } while (temp!=last->add);
        
    }
    
}


Node *insertpos(Node *last,int pos)
{
    Node *temp,*prev,*cur;
    temp=create();
    if (last==NULL)
    {
        count=1;
        return temp;
    }
    if (pos<1 || pos>count+1)
    {
        printf("Invalid pos\n");
        return last;
    }
    else
    {
    if (pos==1)
    {
        temp->add=last->add;
        last->add=temp;
        count++;
        return last;
    }
    
    else if (pos==count+1)
    {

        temp->add=last->add;
        last->add=temp;
        count++;
        return temp;
    }
    
    cur=last->add;    
    for (int i = 1; i < pos; i++)
    {
        prev=cur;
        cur=cur->add;
    }
    temp->add=cur;
    prev->add=temp;
    count++;
    return last; 
    
    }   
}


Node *delpos(Node *last,int pos)
{
    Node *prev,*cur;
     int i;
    if(pos<1 || pos>count)
    {
        printf("\nInvalid position\n");
        return last;
    }
    if(last == NULL)
    {
        printf("\nList Empty\n");
        return NULL;
    }
    if(last->add == last)
    {
        printf("\nThe node with %d is deleted\n", last->data);
        return NULL;
    }
    cur = last->add;
    if(pos == 1)
    {
        last->add = cur->add;
        free(cur);
        printf("\nThe node with %d is deleted\n", cur->data);
        count--;
        display(last);
        return last;
    }
    if(pos == count)
    {
        while(cur->add != last)
        {
            cur = cur->add;
        }
        cur->add = last->add;
        free(last);
        count--;
        display(cur);
        return cur;
    }
    for(i=1; i<pos; i++)
    {
        prev = cur;
        cur = cur->add;
    }
    prev->add = cur->add;
    free(cur);
    count--;
    display(last);
    return last;   
}

int search(Node *last,int key)
{
     Node* temp;
    int pos =1;
    if(last == NULL)
    {
        printf("\nList Empty\n");
        return -1;
    }
    temp = last->add;  if(temp->data == key) return 1;
    do
    {
        temp = temp->add;
        pos++;
    } while (temp->data != key && temp != last->add);
    if(temp == last->add)
        return 0;
    else
        return pos;    
        
        
}
    

Node *delbykey(Node *last,int key)
{
    int pos;
    pos = search(last, key);
    if(pos == -1)
        return last;
    if(pos == 0)
    {
        printf("\nThe element to deleted does not exist\n");
        return last;
    }
    else
    {
        last = delpos(last, pos);
        return last;
    }
}

Node *reverse(Node *last)
{
    if(last == NULL)
    {
        printf("\nList Empty\n");
        return last;
    }
    Node *temp, *cur, *ptr;
    cur = NULL;
    ptr = last;
    last = last->add;
    ptr->add = NULL;
    while(last != NULL)
    {
        temp = last;
        last = last->add;
        temp->add = cur;
        if(temp->add == NULL)
        {
            ptr = temp;
        }
        cur = temp;
    }
    ptr->add = cur;
    display(ptr);
    return ptr;
}

int main()
{
    Node *last=NULL;
    int ch,i,pos,key;
    while (1)
    {
        printf("\n----CSLL-----\n");
        printf("1.Insert by pos\n");
        printf("2.Delete by pos\n");
        printf("3.Del by key\n");
        printf("4.Reverse\n");
        printf("5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter pos:");
            scanf("%d",&pos);
            last=insertpos(last,pos);
            display(last);
            break;
        case 2:
            printf("Enter pos:");
            scanf("%d",&pos);
            last=delpos(last,pos);
            break;
        case 3:
            printf("Enter key to delete:");
            scanf("%d",&key);
            last=delbykey(last,key);
            break;
        case 4:
            reverse(last);
            break;
        default:
            exit(1);
            break;
        }
    }
    
}