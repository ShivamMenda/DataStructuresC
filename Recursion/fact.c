#include<stdio.h>

long fact(int n)
{
    long int res;
    if (n==0)
    {
        res=1;
    }
    else
    {
        res=n*fact(n-1);
    }
    return res;
}
int main()
{
    int i,n;
    printf("Enter a number:");
    scanf("%d",&n);
    printf("the fact is %ld",fact(n));
}
