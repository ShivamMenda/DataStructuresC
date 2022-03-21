#include<stdio.h>
#include<stdlib.h>
#define size 5

struct queue
{
    int data[size];
    int front,rear;
};
typedef struct queue Queue;

void insertrear(Queue *q,int item)
{
    if (q->rear==size-1)
    {
        printf("Queue full\n");
    }
    q->rear++;
    q->data[q->rear]=item;    
    
}

void delfront(Queue *q)
{
    if (q->front==q->rear+1 || q->rear==-1)
    { 
        printf("Queue underflow\n");
    }
    else
    {
        q->front++;
        printf("The deleted ele is %d\n",q->data[q->front-1]);
        if (q->front>q->rear)
        {
            q->front=0;
            q->rear=-1;
        }
        
    }
    
}
void delrear(Queue *q)
{
    if (q->front==q->rear+1 || q->rear==-1)
    { 
        printf("Queue underflow\n");
    }
    else
    {
        q->rear--;
        printf("The deleted ele is %d\n",q->data[q->rear+1]);
        if (q->front>q->rear)
        {
            q->front=0;
            q->rear=-1;
        }
        
    }
    
}
void insertfront(Queue *q,int item)
{
    if (q->front==0 && q->rear==-1)
    {
        q->data[++(q->rear)]=item;
    }
    else if (q->front!=0)
    {
        q->data[--(q->front)]=item;
    }
    else
    {
        printf("cannot insert\n");
    }
    
    
}

void display(Queue q)
{
    if (q.front==q.rear+1 || q.rear==-1)
    {
        printf("Queue empty\n");
    }
    else
    {
        for (int i = q.front; i <=q.rear; i++)
        {
            printf("%d \t\n",q.data[i]);
        }
        
    }
    
}

int main()
{
    Queue q;
    q.front=0;
    q.rear=-1;
    int ch,item;
    while (1)
    {
        printf("-----Linear QUEUE------\n");
        printf("1.Insert front\n");
        printf("2.Del front\n");
        printf("3.Insert rear\n");
        printf("4.Del rear\n");
        printf("5.Display\n");
        printf("6.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter item to be inserted:");
            scanf("%d",&item);
            insertfront(&q,item);
            break;
        case 2:
            delfront(&q);
            break;
        case 3:
            printf("Enter item to be inserted:");
            scanf("%d",&item);
            insertrear(&q,item);
            break;
        case 4:
            delrear(&q);
            break;
        case 5:
            display(q);
            break;
        default:
            exit(1);
            break;
        }

    }
    
}