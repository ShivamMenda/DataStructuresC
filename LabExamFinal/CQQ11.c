/* Circular Queue*/

#include<stdio.h>
#include<stdlib.h>
int count=0;

struct cir_Q
{
 int *queue; 
 int front,rear,size;
};
typedef struct cir_Q CQ;

void insert(CQ *cq,int item)
{
 if((cq->front==0 && cq->rear==cq->size)||(cq->front==cq->rear+1))
 {
  printf("\nQueue overflow");
   return;
 }
  else
   {
     cq->rear = (cq->rear+1)%cq->size;
     *(cq->queue+cq->rear)=item;
     if(cq->front==-1)cq->front=0;
     count=count+1;
   }
 }
 
 void delete(CQ *cq)
 {
  int item;
  if(cq->front==-1)
  {
   printf("\nQueue is empty\n");
  }
  else
  {
   item=*(cq->queue+cq->front);
   cq->front=(cq->front+1) % cq->size;
   count--;
   printf("Deleted item is %d",item);
   }
 }         

void display(CQ *cq)
{ 
 int i,j;
 if(cq->front==-1)
 {
  printf("\nQueue empty\n");
  return;
 }
 printf("\nContents are :\n");
 j=cq->front;
 for(i=1;i<=count;i++)
{
 printf("Q[%d]=%d\t",j,*(cq->queue+j));
 j=(j+1)%cq->size;
 }
} 
 int main()
 {
  CQ cq;
  cq.front=-1;
  cq.rear=-1;
  printf("enter the size of the queue:");
  scanf("%d",&cq.size);
  cq.queue=(int *)calloc(cq.size,sizeof(int));
  int ele,choice;
  for(;;)
  {
   printf("\n1: Insert\n");
   printf("\n2: Delete\n");
   printf("\n3: Display\n");
   printf("\n4: Exit\n");
   printf("Enter your choice\n");
   scanf("%d",&choice);
   switch(choice)
   {
    case 1:
           if(count==cq.size)
           {
             printf("\nQueue overflow\n");
             break;
           } 
           printf("\nEnter the element\n");
           scanf("%d",&ele);
           insert(&cq,ele);
           break;
    case 2: delete(&cq);
           break;
    case 3: display(&cq);
           break;
    default: exit(0);
    }
    }
  }  
