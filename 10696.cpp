#include<stdio.h>
int main()
{
    long long int n,f;
    scanf("%lld",&n);
    while(n!=0)
    {
        if(n>=101)
        {
            f=n-10;
        }
        if(n<=100)
        {
                f=91;
        }
        printf("f91(%lld) = %lld\n",n,f);
        scanf("%lld",&n);
    }
    return 0;
}
