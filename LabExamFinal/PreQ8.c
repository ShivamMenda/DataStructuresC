#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

void rev(char str[]){
    int n=strlen(str);
    for (int i = 0; i < n / 2; i++)
  {
    char ch = str[i];
    str[i] = str[n - i - 1];
    str[n - i - 1] = ch;
  }
}

int main(){
    char inf[30],pre[30];
    void convert(char[],char[]);
    int ch;
    while (1)
    {
        printf("INFIX TO PREFIX\n");
        printf("1.Read Infix\n");
        printf("2.Display prefix\n");
        printf("3.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter the infix exp:");
            scanf("%s",inf);
            break;
        case 2:
            printf("The infix entered is %s\n",inf);
            rev(inf);
            convert(inf,pre);
            rev(pre);
            printf("The pre is:%s\n",pre);
            break;
        default:
            exit(1);
            break;
        }
    }

}

void convert(char inf[],char pre[]){
    int i,j=0,top=-1,test,f=1;
    char st[30],ch,x;
    int check(char);
    int prec(char);

    for (i = 0; inf[i] !='\0'; i++)
    {
        ch=inf[i];
        test=check(ch);
        switch (test)
        {
        case 1:
            pre[j++]=ch;
            break;
        case 2:
            st[++top]=ch;
            break;
        case 3:
            while ((x=st[top--])!=')')
            {
                pre[j++]=x;
            }
            break;
        case 4:
        do
        {
            if (top==-1)
            {
                f=1;
            }
            else if (st[top]==')')
            {
                f=1;
            }
            else if (prec(ch)>=prec(st[top]))
            {
                f=1;
            }
            else
            {
                pre[j++]=st[top--];
                f=0;
            }
        }while (f==0);
        st[++top]=ch;
        break;
        }
    }
    while (top!=-1)
    {
       pre[j++]=st[top--];
       pre[j]='\0';
    }
    pre[j]='\0';
}

int prec(char op)
{
    if (op=='+'|| op=='-')
    {
        return 1;
    }
    else if (op=='*'|| op=='/'|| op=='%')
    {
        return 2;
    }
    else if (op=='^')
    {
        return 3;
    }
    return 0;
}

int check(char ch){
    if (isalnum(ch))
    {
        return 1;
    }
    else if (ch==')')
    {
        return 2;
    }
    else if (ch=='(')
    {
        return 3;
    }
    else if (ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='%'||ch=='^')
    {
        return 4;
    }
    else
    {
        return 5;
    }
}