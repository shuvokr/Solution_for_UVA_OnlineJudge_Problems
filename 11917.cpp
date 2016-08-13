#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define sf scanf
#define pf printf
int main()
{
    int i, j, n, res, ar[102], T, D, k, z = 0;
    char ch[102][22], ck[22];
    sf("%d", &T);
    while(T--)
    {
        res = 0;

        sf("%d", &n);

        for(i = 0; i < n; i++)
        {
            sf("%s%d", ch[i], &ar[i]);
        }

        sf("%d%s", &D, ck);

        j = 0;

        for(i = 0; i < n; i++)
        {
            if(strcmp(ch[i],ck) == 0)
            {
                j = 1;
                res = ar[i];
                break;
            }
        }

        pf("Case %d: ", ++z);
        if(res <= D && j == 1) puts("Yesss");
        else if(res > D && res <= D+5 && j == 1) puts("Late");
        else puts("Do your own homework!");
    }
    return 0;
}
