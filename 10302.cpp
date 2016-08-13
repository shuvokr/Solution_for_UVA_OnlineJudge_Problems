#include<stdio.h>
int main()
{
    long long int a,b,i;
    while(scanf("%lld",&a)==1)
    {
        b=0;
        for(i=1;i<=a;i++)
        {
            b=b+(i*i*i);
        }
        printf("%lld\n",b);
    }
    return 0;
}
