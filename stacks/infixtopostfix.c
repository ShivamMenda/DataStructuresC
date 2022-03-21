#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int main(){
    char inf[30],pst[30];
    void convert(char[],char[]);
    
    int ch;
    while (1)
    {
        printf("INFIX TO POSTFIX\n");
        printf("1.Read Infix\n");
        printf("2.Display postfix\n");
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
            convert(inf,pst);
            printf("The pst is:%s\n",pst);
            break;
        
        default:
            exit(1);
            break;
        }

    }
}

void convert(char inf[],char pst[]){
    int i,j=0,top=-1,test,f=1;
    char st[30],ch,x;
    int check(char);
    int pre(char);

    for (i = 0; inf[i] !='\0'; i++)
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
        }while (f==0);
        st[++top]=ch;
        break;    
        }
    }
    while (top!=-1)
    {
       pst[j++]=st[top--];
       pst[j]='\0';
    }
    
    


}

int pre(char op){
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

int check(char ch){
    if (isalnum(ch))
    {
        return 1;
    }
    else if (ch=='(')
    {
        return 2;
    }
    else if (ch==')')
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