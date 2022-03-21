#include<stdio.h>
#include<stdlib.h>
#define stsize 5

int st[stsize],top=-1;

int main()
{
    int ch;
    void push();
    void pop();
    void peek();
    void status();

    while (1)
    {
        printf("ENTER CHOICE:\n");
        printf("-------------\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Status\n");
        printf("5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            status();
            break;
        case 5:
            exit(1);
            break;
        
        default:
            printf("Invaild input");
            break;
        }
    }
    
}

void push()
{
    int x;
    if (top==stsize-1)
    {
        printf("overflow\n");
    }
    else
    {
        printf("Enter element to be pushed:");
        scanf("%d",&x);
        top++;
        st[top]=x;
    }
    
}

void pop()
{
    if (top==-1)
    {
        printf("Underflow\n");
    }
    else
    {
        top=top-1;
        printf("The element popped is %d\n",st[top+1]);
    }
}

void peek()
{
    if (top==-1)
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("The topmost element is %d\n",st[top]);
    }
}

void status()
{
    int i;
    if (top==-1)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("The elem are:\n");
        for (i = top; i>=0; i--)
        {
            printf("%d",st[i]);
            printf("\n");
        }
        
    }
}