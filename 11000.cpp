#include<stdio.h>
int main()
{
    long long int n,a=1,b=1,r,i,t,total=0,male=0;
    scanf("%lld",&n);
    while(n!=-1)
    {
        if(n==0)
        {
            printf("0 1\n");
        }
        else
        {
            total=0;male=0;a=1;b=1;
            for(i=1 ; i<=n ; i++)
            {
                male = a+b-1;
                t =a;
                a = b;
                b = b+t;
                total = a+b-1;
            }
            printf("%lld %lld\n",male,total);
        }

       scanf("%lld",&n);
    }
    return 0;
}
