#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define lu unsigned long int
#define sf scanf
#define pf printf

int main()
{
    lu T, n, i, j;
    sf("%lu",&T);
    while(T--)
    {
        lu res[10] = {0};
        sf("%lu", &n);
        if(n == 0) puts("1 0 0 0 0 0 0 0 0 0");
        else
        {
            for(i = 1; i <= n; i++)
            {
                lu len, kk, m;
                m = i;
                len = log10(m) + 1;
                for(j = 0; j < len; j++)
                {
                    kk = m % 10;
                    m = m / 10;
                    res[kk] += 1;
                }
            }
            pf("%lu", res[0]);
            for(i = 1; i < 10; i++)
                pf(" %lu", res[i]);
            pf("\n");
        }
    }
    return 0;
}
