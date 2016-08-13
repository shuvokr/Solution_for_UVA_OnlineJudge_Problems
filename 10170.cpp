#include<stdio.h>
int main()
{
    long long int s,d,c,k;
    while(scanf("%lld%lld",&s,&d)==2)
    {
        if(s<d)
        {
            c=s;
            while(d>s)
            {
                c=c+1;
                k=c;
                s=c+s;
            }
        printf("%lld\n",k);
        }
        else
        {
            printf("%lld\n",s);
        }
    }
    return 0;
}
