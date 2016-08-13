#include<stdio.h>
long long bigmod(long long b,long long p,long long m)
{
    long long int x,y;
    if(p==0)
    {
        return 1;
    }
    else if(p%2==0)
    {
        x=0;
        p=p/2;
        x=bigmod(b,p,m);
        x=(x*x)%m;
        return x;
    }
    else
    {
        y=0;
        p=p-1;
        y=bigmod(b,p,m);
        y=((b%m)*y)%m;
        return y;
    }
}
int main()
{
    long long int r,b,p,m;
    while(scanf("%lld%lld%lld",&b,&p,&m)==3)
    {
        r=bigmod(b,p,m);
        printf("%lld\n",r);
    }
    return 0;
}
