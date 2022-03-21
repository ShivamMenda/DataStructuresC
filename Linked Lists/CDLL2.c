#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *prev;
    struct node *next;
};

typedef struct node Node;

Node *createnode()
{
    Node *new;
    new=(Node *)malloc(sizeof(Node));
    printf("Enter info:");
    scanf("%d",&new->info);
    new->prev=new;
    new->next=new;
    return new;
}

Node *insertfront(Node *last,Node *nw)
{
    Node *first;
    if (last==NULL)
    {
        return nw;
    }
        first=last->next;
        nw->next=first;
        last->next=nw;
        first->prev=nw;
        nw->prev=last;
        return last;
}

void disp(Node *last)
{
    Node *temp;
    if (last==NULL)
    {
        printf("list empty\n");
    }
    else
    {
        temp=last->next;
        while (temp!=last)
        {
            printf("%d->",temp->info);
            temp=temp->next;
        } 
        
        
    }
    
}

int main(){
    int choice, pos, item;
    Node * last = NULL;
    Node *nw;

    for(;;){
        printf("           MENU           \n");
        printf("1.Insert Front\n2.Insert Rear\n3.Insert by Position\n4.Delete Front\n5.Delete Rear\n6.Delete by Position\n7.Delete by Value\n8.Search by Value\n9.Copy List\n10.Reverse List\nEnter your choice>> ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                nw=createnode();
                last = insertfront(last, nw);
                disp(last);
                break;

            // case 2:
            //     printf("Enter the data>> ");
            //     scanf("%d", &item);
            //     first = insertRear(first, item);
            //     print(first);
            //     break;

            // case 3:
            //     printf("Enter the data>> ");
            //     scanf("%d", &item);
            //     printf("Enter the position>> ");
            //     scanf("%d", &pos);

            //     first = insertPos(first, pos, item);
            //     print(first);
            //     break;

            // case 4:
            //     first = deleteFront(first);
            //     print(first);
            //     break;

            // case 5:
            //     first = deleteRear(first);
            //     print(first);
            //     break;

            // case 6:
            //     printf("Enter the position>> ");
            //     scanf("%d", &pos);

            //     first = deletePos(first, pos);
            //     print(first);
            //     break;

            // case 7:
            //     printf("Enter the Data>> ");
            //     scanf("%d", &item);

            //     first = deleteValue(first, item);
            //     print(first);
            //     break;

            // case 8:
            //     printf("Enter the data>> ");
            //     scanf("%d", &item);

            //     first = search(first, item);
            //     break;

            // case 9:
            //     break;

            // case 10:
            //     break;

            default:
                exit(0);
                break;
            }
    }
}