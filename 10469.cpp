#include<stdio.h>
int main()
{
    int a,b,*c,d;
    while(scanf("%d%d",&a,&b)==2)
    {
        d=a^b;
        c=&d;
        printf("%d\n",*c);
    }
    return 0;
}
