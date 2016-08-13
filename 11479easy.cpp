#include<stdio.h>
#include<stdlib.h>
int main()
{
    long long int a,b,c,a1,b1,c1,a2,b2,c2;
    int T,l=0;
    scanf("%d",&T);
    if(T>=0 && T<20)
    {
    while(T!=l)
    {
        l++;
    scanf("%lld%lld%lld",&a,&b,&c);
    c1=a+b;
    b1=a+c;
    a1=b+c;
    c2=abs(a-b);
    b2=abs(a-c);
    a2=abs(b-c);
    if((c1>c && c2<c) || (b1>b && b2<b) || (a1>a && a2<a))
    {
        if(a==b & a==c)
        {
            printf("Case %d: Equilateral\n",l);
        }
        else if((a==b && a!=c) || (a==c && a!=b) || (b==c && b!=a))
        {
            printf("Case %d: Isosceles\n",l);
        }
        else
        {
            printf("Case %d: Scalene\n",l);
        }
    }
    else
    {
         printf("Case %d: Invalid\n",l);
    }
    }
    }
    return 0;
}
