#include<stdio.h>
unsigned long int fib(unsigned long int n)
{
    unsigned long int i=1,j=0,k=0,h=1,t;
    while(n>0)
    {
    if(n%2==1)
    {
        t = j*h;
        j = (i*h) + (j*k) + t;
        i = (i*k) + t;
    }
    t = h*h;
    h = (2*k*h) + t;
    k = (k*k) + t;
    n=(int) n/2;
    }
    return j;
}
int main()
{
    unsigned long int n,res;
    scanf("%lu",&n);
    while(n!=0)
    {
        n=n+1;
        res = fib(n);
        printf("%lu\n",res);
        scanf("%lu",&n);
    }
    return 0;
}
