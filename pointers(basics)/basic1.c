#include<stdio.h>

int main()
{
    int x,y;
    int *p;
    x=10;
    p=&x;
    y=*p;
    printf("%d\n",x);
    printf("%d\n",y);
    *p=25;
    y=*p;
    printf("%d %d",x,y);




}