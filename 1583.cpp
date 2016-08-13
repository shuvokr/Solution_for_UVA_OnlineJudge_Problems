#include <stdio.h>
int res[100001];
int main()
{
    int n=0,T=0,i=100000,ret=0,tmp;
    for(;i;i--)
    {
        n = ret = i;
        while(n)
        {
            tmp = n;
            n /= 10;
            ret += tmp - n * 10;
        }
        res[ret]=i;
    }
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d", &n);
        printf("%d\n", res[ n ]);
    }
    return 0;
}
