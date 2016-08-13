#include<stdio.h>
int main()
{
    long long int a,b,n,k;
    while(scanf("%lld%lld",&n,&k)==2)
    {
        a=n;
        while(n>=k)
        {
            b=n%k;
            n=n/k;
            a=a+n;
            n=n+b;
        }
        printf("%lld\n",a);
    }
    return 0;
}

