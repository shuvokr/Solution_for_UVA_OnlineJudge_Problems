#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

#define sf scanf
#define pf printf
#define LL unsigned long long int
#define L long long int

unsigned long long sev[10000];

int main()
{
    LL i, j, temp;
    sev[0] = 0; sev[1] = 1;
    for(i = 2; i <= 40; i++)
    {
        sev[i] = sev[i-1] + sev[i-2];
    }
    LL n, T, res;
    sf("%llu", &T);
    while(T--)
    {
        sf("%llu", &n);
        for(i = 2; i > 0; i++)
        {
            if(sev[i] > n)
            {
                temp = i - 2;
                pf("%llu = 1", n);
                n = n - sev[temp+1];
                for(j = temp; j > 1; j--)
                {
                    if(n >= sev[j] && n != 0)
                    {
                        pf("1");
                        n = n - sev[j];
                    }
                    else pf("0");
                }
                pf(" (fib)\n"); break;
            }
        }
    }
    return 0;
}
