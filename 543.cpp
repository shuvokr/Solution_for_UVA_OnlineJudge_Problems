#include<stdio.h>
#include<math.h>
long long isprime(long long n)
{
    long long int i;
    for(i=2; i*i<=n; i++)
        if(n%i==0)
    return 0;

    return 1;
}
int main()
{
    long long int n,k=0;
    scanf("%lld",&n);
    while(n!=0)
    {
        long long int i,r,x,y;
        y=n;
        k=0;
        for(i=n-3; i>0; i--)
        {
            r=isprime(i);
            if(r==1)
            {
                long long int z;
                x=y-i;
                z=isprime(x);
                if(z==1)
                {
                    printf("%lld = %lld + %lld\n",y,x,i);
                    k=1;
                    break;
                }
            }
        }
        if(k==0)
        {
            printf("Goldbach's conjecture is wrong.\n");
        }
        scanf("%lld",&n);
    }
    return 0;
}
