#include<stdio.h>
#include<string.h>
int main()
{
    int b = 0, s = 0, i = 0, z = 0, n = 0;
    while(scanf("%d%d",&b,&s) != EOF)
    {
        if(b == 0 && s == 0) return 0;

        int ck = 1, res = 0;

        scanf("%d",&res);
        for(i=1; i<b; i++)
        {
            scanf("%d",&n);
            if(res > n) res = n;
        }
        for(i=0; i<s; i++)
        {
            scanf("%d",&n);
        }
        if(b <= s) printf("Case %d: 0\n",++z);
        else printf("Case %d: %d %d\n",++z,b-s,res);
    }
    return 0;
}
