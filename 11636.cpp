#include<stdio.h>
int main()
{
    int n,s,h,c=1;
    scanf("%d",&n);

    while(n>=0)
    {
        if(n>0 && n<10001)
        {
        s=1;
        h=0;
        while(s<n)
    {
        s=s+s;
        h++;
    }
    printf("Case %d: %d\n",c,h);
        }
        c++;
    scanf("%d",&n);
    }
    return 0;
}
