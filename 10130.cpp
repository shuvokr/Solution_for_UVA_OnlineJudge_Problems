#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define sf scanf
#define pf printf
int main()
{
    int T, item, prw[1005][2], member, mw, i, j, k, temp, sum, x, y, res[1005][33];
    sf("%d", &T);
    while(T--)
    {
        sf("%d", &item);
        for(i = 1; i <= item; i++)
            for(j = 1; j <= 2; j++)
                sf("%d", &prw[i][j]);

        sf("%d", &member);
        sum = 0;
        for(k = 1; k <= member; k++)
        {
            sf("%d", &mw);
            res[item+1][mw+1] = 0;
            for(i = 1; i <= item; i++)
                for(j = 1; j <= mw; j++)
                    if(prw[i][2] > j)
                        res[i][j] = res[i-1][j];
                    else
                    {
                        x = prw[i][1] + res[i-1][j - (prw[i][2])];
                        y = res[i-1][j];
                        if(x > y)
                            res[i][j] = x;
                        else res[i][j] = y;
                    }
            sum += res[item][mw];
        }
        pf("%d\n", sum);
    }
    return 0;
}
