#include<stdio.h>
#include<stdlib.h>

struct student
{
    char name[50];
    int m1,m2,m3;
    int reg;
};

typedef struct student st;

void read(st *s,int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("For student %d enter:\n",i+1);
        printf("Name:");
        scanf("%s",(s+i)->name);
        printf("Reg:");
        scanf("%d",&((s+i)->reg));
        printf("M1:");
        scanf("%d",&((s+i)->m1));
        printf("M2:");
        scanf("%d",&((s+i)->m2));
        printf("M3:");
        scanf("%d",&((s+i)->m3));
    }    
}
void disp(st *s,int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Student %d\n",i+1);
        printf("Name:%s\n",(s+i)->name);
        printf("Reg:%d\n",(s+i)->reg);
        printf("M1:%d\n",(s+i)->m1);
        printf("M2:%d\n",(s+i)->m2);
        printf("Name:%d\n",(s+i)->m3);
    }
    
}
void sort(st *s,int n)
{
    int i,j,temp;
    for (i = 0; i < n-1; i++)
    {
        for ( j = 0; j< n-1-i; j++)
        {
            
        
        }
    }
    
}

int main()
{
    int ch,n;
    st *sp;
    printf("Enter the number of students:");
    scanf("%d",&n);
    while (1)
    {
        printf("1.Read\n");
        printf("2.Display\n");
        printf("3.Sort\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            sp=(st *)calloc(n,sizeof(st));
            read(sp,n);
            break;
        case 2:
            disp(sp,n);
            break;
        default:
            exit(1);
            break;
        }
    }
    
}
