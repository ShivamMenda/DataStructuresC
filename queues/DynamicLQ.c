#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int *queue;
    int front,rear,size;
};
typedef struct queue Queue;

void enqueue(Queue *q,int item)
{
    if (q->rear==q->size-1)
    {
        printf("Queue full\n");
    }
    q->rear++;
    *(q->queue+q->rear)=item;    
    
}

void dequeue(Queue *q)
{
    if (q->front==q->rear+1 || q->rear==-1)
    { 
        printf("Queue underflow\n");
    }
    else
    {
        q->front++;
        printf("The deleted ele is %d\n",*(q->queue+q->front-1));
        if (q->front>q->rear)
        {
            q->front=0;
            q->rear=-1;
        }
        
    }
    
}

void display(Queue *q)
{
    if (q->front==q->rear+1 || q->rear==-1)
    {
        printf("Queue empty\n");
    }
    else
    {
        for (int i = q->front; i <=q->rear; i++)
        {
            printf("%d \t\n",*(q->queue+i));
        }
        
    }
    
}

int main()
{
    Queue q;
    q.front=0;
    q.rear=-1;
    int ch,item;
    printf("Enter the size of the queue:");
    scanf("%d",&q.size);
    q.queue=(int *)calloc(q.size,sizeof(int)); 
    while (1)
    {
        printf("-----Linear QUEUE------\n");
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
            enqueue(&q,item);
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