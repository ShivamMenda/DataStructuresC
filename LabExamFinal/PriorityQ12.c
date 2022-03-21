#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int *queue;
    int f,r,size;
};

typedef struct queue Q;

void insert(Q *q,int item)
{
    int pos;
    if (q->r==q->size-1)
    {
        printf("Queue full\n");
    }
    pos=q->r;
    q->r++;
    while (pos>=0 && *(q->queue+pos)>=item )
    {
        *(q->queue+(pos+1))=*(q->queue+(pos));
        pos=pos-1;
    }
    *(q->queue+(pos+1))=item;
    printf("Insertion successful\n");
    
}

void dequeue(Q *q)
{
    if (q->f==q->r+1 || q->r==-1)
    { 
        printf("Queue underflow\n");
    }
    else
    {
        q->f++;
        printf("The deleted ele is %d\n",*(q->queue+q->f-1));
        if (q->f>q->r)
        {
            q->f=0;
            q->r=-1;
        }
        
    }
}

void display(Q *q)
{
    if (q->f==q->r+1 || q->r==-1)
    {
        printf("Queue empty\n");
    }
    else
    {
        for (int i = q->f; i <=q->r; i++)
        {
            printf("%d \t",*(q->queue+i));
        }
        
    }
    
}

int main()
{
    Q q;
    q.f=0;
    q.r=-1;
    printf("Enter the size of the queue:");
    scanf("%d",&q.size);
    q.queue=(int *)calloc(q.size,sizeof(int));
    int ch,item;
    while (1)
    {
        printf("\n-----PRIORITY QUEUE------\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Status\n");
        printf("4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter item to be inserted:");
            scanf("%d",&item);
            insert(&q,item);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            display(&q);
            break;
        
        default:
            exit(1);
            break;
        }

    }
}