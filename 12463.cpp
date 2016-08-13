#include<stdio.h>

int main()
{
    int a,b,c,d,e,r,k;
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    while(a!=0 && b!=0 && c!=0 && d!=0 && e!=0)
    {
        r=a*b;
        r=r*c;
        k=d*d;
        r=r*k;
        k=e*e;
        r=r*k;
        printf("%d\n",r);
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    }
    return 0;
}
