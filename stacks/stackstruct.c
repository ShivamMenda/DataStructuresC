#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int top;
    int maxsize;
    int *items;
};
typedef struct stack Stack;

Stack *create(int n)
{
    Stack *new;
    new=(Stack *)malloc(sizeof(Stack));
    new->maxsize=n;
    new->top=-1;
    new->items=(int*)calloc(n,sizeof(int));
    return new;
}

int size(Stack *s)
{
    return s->top+1;
}
int isempty(Stack *s)
{
    return s->top==-1;
}
int isfull(Stack *s)
{
    return s->top==s->maxsize-1;
}
void push(Stack *s,int x)
{
    if (isfull(s)==1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        printf("Inserting %d\n",x);
        s->items[++s->top]=x;
    }
    
}

void peek(Stack *s)
{
    if (isempty(s)==1) {
        printf("Stack empty");
        
    }
    else {
        printf("Top=%d",s->items[s->top]);
    }
}



void pop(Stack *s)
{
    if (isempty(s)==1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Removing %d",s->items[s->top]);
        s->items[s->top--];
    }
}

void print(Stack *s)
{
    if (isempty(s)==1)
    {
        printf("Stack empty");
    }
    else
    {
        for (int i = s->top; i>=0 ; i--)
        {
            printf("%d\n",s->items[i]);
        }
        
    }
}


int main(){
    int n;
    int data, choice;
    printf("Enter sizeof stack:");
    scanf("%d",&n);
    Stack *stack=create(n);
    while(1){
        printf("\n1.PUSH\n2.POP\n3.PEEK\n4.PRINT\n5.EXIT\nSelect Option>> ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter Data>> ");
                    scanf("%d",&data);
                    push(stack,data);
                    break;
            case 2: pop(stack);
                    break;
            case 3: peek(stack);
                    break;
            case 4: print(stack);
                    break;
            default: exit(0);
                        break;
        }
    }
}