#include<stdio.h>
#include<stdlib.h>

struct student
{
    char name[20];
    int r;
    int m1,m2,m3;
};
typedef struct student stu;

void read(stu *sp,int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("For Student %d\n",(i+1));
        printf("Enter name:");
        scanf("%s",(sp+i)->name);
        printf("Enter reg no:");
        scanf("%d",&((sp+i)->r));
        printf("Enter Marks 1:");
        scanf("%d",&((sp+i)->m1));
        printf("Enter Marks 2:");
        scanf("%d",&((sp+i)->m2));
        printf("Enter Marks 3:");
        scanf("%d",&((sp+i)->m3));
    }
    
}

void display(stu *sp,int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("For Student %d\n",(i+1));
        printf("Name:%s\n",(sp+i)->name);
        printf("Register number:%d\n",((sp+i)->r));
        printf("Marks 1:%d\n",((sp+i)->m1));
        printf("Marks 2:%d\n",((sp+i)->m2));
        printf("Marks 3:%d\n",((sp+i)->m3));   
    }

}

void average(stu *sp,int n)
{
    int small,sum=0;
    float avg;
    for (int i = 0; i < n; i++)
    {
        printf("For student %d:\n",(i+1));
        if ((sp+i)->m1>=(sp+i)->m2)
        {
            small=(sp+i)->m2;
            if (small>=(sp+i)->m3)
            {
                small=(sp+i)->m3;
            }
            
        }
        else
        {
            small=(sp+i)->m1;
            if (small>=(sp+i)->m3)
            {
                small=(sp+i)->m3;
            }
            
        }
     sum=((sp+i)->m1+(sp+i)->m2+(sp+i)->m3)-small;
     avg=sum/2;
     printf("Average=%0.2f\n",avg);   
    }
    
    
}


int main()
{
    stu *sp;
    int n,i,ch;
    while (1)
    {
        printf("-----Student Details--------\n");
        printf("1.Read\n");
        printf("2.Display\n");
        printf("3.Calculate Average\n");
        printf("4.Exit\n");
        printf("Enter choice:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter the number of students:");
            scanf("%d",&n);
            sp=(stu *)calloc(n,sizeof(stu));
            read(sp,n);
            break;
        case 2:
            display(sp,n);
            break;
        case 3:
            average(sp,n);
            break;

        
        default:
            exit(1);
            break;
        }

    }
    
}