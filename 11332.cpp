#include<stdio.h>
#include<math.h>
long long int fun(long long int n)
{
    long long int len,m,i,j,x,k;
    while(n!=0)
        {
            len=log10(n);
            j=0;
            for(k=0 ; k<=len ; k++)
            {
                i=n%10;
                j=i+j;
                n=n/10;
            }
        }
            return j;
}

int main()
{
        long long int len,m,n,i,j,x,k,f;
        scanf("%lld",&n);
        while(n!=0)
        {
            f=fun(n);
            len=log10(f);
            while(len>0)
            {
                f=fun(f);
                len=log10(f);
            }
            printf("%lld\n",f);
            scanf("%lld",&n);
        }
    return 0;
}

