#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int stack[20];
int top=-1;
void push(int x)
{
    stack[++top]=x;
}

int pop()
{
    return stack[top--];
}

void post()
{
    char exp[20];
    int n1,n2,n3,num;
    printf("enter postfix expression");
    scanf("%s",exp);
   for(int i=0;exp[i]!='\0';i++)
    {
        if (isdigit(exp[i]))
        {
            num=exp[i]-48;
            push(num);
        }
        else
        {
            n1=pop();
            n2=pop();
            switch (exp[i])
            {
            case '+':
                n3=n2+n1;
                break;
             case '-':
                n3=n2-n1;
                break;
             case '*':
                n3=n2*n1;
                break;
             case '/':
                n3=n2/n1;
                break;
             case '%':
                n3=n2%n1;
                break;
             case '^':
                n3=pow(n2,n1);
                break;
            }
            push(n3);
        }
        
    }
    printf("The result is %s=%d\n",exp,pop());
}

void pre()
{
    char exp[20];
    
    int n1,n2,n3,num;
    printf("enter prefix expression:");
    scanf("%s",exp);
    for (int i=strlen(exp)-1;i>=0;i--)
    {
        if (isdigit(exp[i]))
        {
            num=exp[i]-48;
            push(num);
        }
        else
        {
            n1=pop();
            n2=pop();
            switch (exp[i])
            {
            case '+':
                n3=n2+n1;
                break;
             case '-':
                n3=n2-n1;
                break;
             case '*':
                n3=n2*n1;
                break;
             case '/':
                n3=n2/n1;
                break;
             case '%':
                n3=n2%n1;
                break;
             case '^':
                n3=pow(n2,n1);
                break;
            }
            push(n3);
        }
        
    }
    printf("The result is %s=%d\n",exp,pop());
}




int main()
{
    int ch;
    while (1)
    {
        printf("POSTFIX PREFIX EVAL\n");
        printf("1.Postfix Eval\n");
        printf("2.Prefix Eval\n");
        printf("3.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            post();
            break;
        case 2:
            pre();
            break;
        default:
            exit(1);
            break;
        }
    }

}