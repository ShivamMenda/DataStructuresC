#include<stdio.h>
#include<stdlib.h>

void read(int *s,int size)
{
    int i;
    printf("enter the array elements:\n");
    for (int i = 0; i < size; i++)
    {
        printf("a[%d]:",(i+1));
        scanf("%d",(s+i));
    }
    
}

void display(int *s,int size)
{
    int i;
    printf("\nThe array elements:\n");
    for (int i = 0; i < size; i++)
    {
        printf("a[%d]:%d\t",(i),*(s+i));
        
    }
}

int search(int *s,int item,int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (*(s+i)==item)
        {
            return i;
        }
        
    }
    return -1;
}
void insert(int *s,int *size,int key,int pos)
{
    if (pos>*(size))
    {
        printf("Insertion not possible\n");
    }
    for (int i = *size-1; i >=pos; i--)
    {
        *((s+i)+1)=*(s+i);
    }
    *(s+pos)=key;
    *size=*size+1;
}
void delete(int *s,int *size,int pos)
{
    if (pos>=*size)
    {
        printf("Deletion not possible\n");
    }
    for (int i = pos; i <*size; i++)
    {
        *(s+i)=*((s+i)+1);
    }
    *size=*size-1;
}

void sort(int *ptr,int size)
{
    int i,j,temp;
    for ( i = 0; i < size-1; i++)
    {
        for ( j = 0; j < (size-1-i); j++)
        {
            if (*(ptr+j)>*(ptr+1+j))
            {
                temp=*(ptr+j);
                *(ptr+j)=*((ptr+j)+1);
                *((ptr+j)+1)=temp;
            }
            
        }
        
    }
    
}



int main()
{
    int n,ch,item,pos,size;
    int *s;
    while (1)
    {
        printf("\nArray OP\n");
        printf("1.Read\n");
        printf("2.Display\n");
        printf("3.Search\n");
        printf("4.Insert pos\n");
        printf("5.Delete pos\n");
        printf("6.Sort\n");
        printf("7.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("enter the size:");
            scanf("%d",&size);
            s=(int *)calloc(size,sizeof(int));
            read(s,size);
            break;
        case 2:
            display(s,size);
            break;
        case 3:
            printf("Enter item to search:");
            scanf("%d",&item);
            pos=search(s,item,size);
            if (pos==-1)
            {
                printf("search unsuccessful\n");
            }
            else
            {
                printf("found at %d\n",(pos+1));
            }
            break;
        case 4:
            printf("Enter ele and pos:");
            scanf("%d %d",&item,&pos);
            insert(s,&size,item,pos);
            break;
        case 5:
            printf("Enter pos:");
            scanf("%d",&pos);
            delete(s,&size,pos);
            break;
        case 6:
            sort(s,size);
            break;
        
        default:
            exit(1);
            break;
        }

    }
    
}