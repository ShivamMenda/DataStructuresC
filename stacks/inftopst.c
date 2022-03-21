#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int pre(char op)
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
}

int check(char op)
{
    if (isalnum(op))
    {
        return 1;
    }
    else if (op=='(')
    {
        return 2;
    }
    else if (op==')')
    {
        return 3;
    }
    else if (op=='+'|| op=='-'|| op=='/'|| op=='*' || op=='%' || op=='^')
    {
        return 4;
    }
    else
    {
        return 5;
    }
}

void convert(char inf[],char pst[])
{
    int i,j=0,top=-1,f=1,test;
    char st[30],ch,x;

    for (i = 0; inf[i]!='\0'; i++)
    {
        ch=inf[i];
        test=check(ch);
        switch (test)
        {
        case 1:
            pst[j++]=ch;
            break;
        case 2:
            st[++top]=ch;
            break;
        case 3:
            while ((x=st[top--])!='(')
            {
                pst[j++]=x;
            }
            break;
        case 4:
            do
            {
                if (top==-1)
                {
                    f=1;
                }
                else if (st[top]=='(')
                {
                    f=1;
                }
                else if (pre(ch)>pre(st[top]))
                {
                    f=1;
                }
                else
                {
                    pst[j++]=st[top--];
                    f=0;
                }
                
            } while (f==0);
            st[++top]=ch;
        
        
        }
    }
    while (top!=-1)
    {
        pst[j++]=st[top--];
        pst[j]='\0';
    }
    
}


int main()
{
    char inf[30],pst[30];
    printf("enter infix:");
    scanf("%s",inf);
    convert(inf,pst);
    printf("The postfix:%s",pst);

}