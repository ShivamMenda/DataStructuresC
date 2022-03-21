#include<stdio.h>
#include<stdlib.h>

struct student
{
    int usn;
    char name[10];
    int m1,m2,m3;
};
typedef struct student st;

void read(st *s,int n)
{
    int i;
    for ( i = 0; i < n; i++)
    {
        printf("For student %d enter:\n",i+1);
        printf("Name:");
        scanf("%s",(s+i)->name);
        printf("USN:");
        scanf("%d",&((s+i)->usn));
        printf("M1:");
        scanf("%d",&((s+i)->m1));
        printf("M2:");
        scanf("%d",&((s+i)->m2));
        printf("M3:");
        scanf("%d",&((s+i)->m3));
    }
    
}

void display(st *s,int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Student %d\n",i+1);
        printf("Name:%s\n",(s+i)->name);
        printf("USN:%d\n",(s+i)->usn);
        printf("M1:%d\n",(s+i)->m1);
        printf("M2:%d\n",(s+i)->m2);
        printf("Name:%d\n",(s+i)->m3);
    }
}

void search(st *s,int n)
{
    int i,m,pos;
    printf("Enter USN to find:");
    scanf("%d",&m);
    for (i = 0; i < n; i++)
    {
        if ((s+i)->usn==m)
        {
        printf("Student %d\n",i+1);
        printf("Name:%s\n",(s+i)->name);
        printf("USN:%d\n",(s+i)->usn);
        printf("M1:%d\n",(s+i)->m1);
        printf("M2:%d\n",(s+i)->m2);
        printf("M3:%d\n",(s+i)->m3);
        return;
        }
    }
    printf("not found\n");
    
}

int main()
{
    int ch,n,res;
    st *sp;
    printf("Enter the number of students:");
    scanf("%d",&n);
    while (1)
    {
        printf("1.Read\n");
        printf("2.Display\n");
        printf("3.Search\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            sp=(st *)calloc(n,sizeof(st));
            read(sp,n);
            break;
        case 2:
            display(sp,n);
            break;
        case 3:
            search(sp,n);
            break;
        default:
            exit(1);
            break;
        }
    }
    
}