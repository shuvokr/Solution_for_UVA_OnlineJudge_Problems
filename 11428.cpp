#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
#define LL unsigned long long int
#define sf scanf
#define pf printf

int main()
{
    LL neg, n, a, b, i, j, ck;
    while(sf("%llu",&n) == 1)
    {
        if(n == 0) return 0;

        a = 0; b = 0; i = 1; ck = 0, j = 1;

        for(; i <= 10000; i++)
        {
            a = n + pow(i, 3);
            j = i+1;
                while(pow(j, 3) <= a)
                {
                    if(pow(j, 3) == a)
                    {
                        printf("%llu %llu\n",j,i); ck = 1;
                        break;
                    }
                    j++;
                }
                if(ck == 1) break;

        }
        if(ck == 0) puts("No solution");
    }
    return 0;
}
