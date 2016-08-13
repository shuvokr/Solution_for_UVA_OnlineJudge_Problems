#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<assert.h>
#define pf printf
#define sf scanf
#define lld long long int
int main()
{
    lld T = 0, n = 0, i = 0, res = 0, sqrtn = 0;
    sf("%lld", &T);
    while(T--)
    {
        sf("%lld", &n);
        if(n < 1) puts("0");
        else{
            sqrtn = sqrt(n);
            for(i = 1; i <= sqrtn; i++)
                res += n / i;
            res *= 2;
            sqrtn = pow(sqrtn, 2);
            res -= sqrtn;
            pf("%lld\n", res);
            res = 0;
        }
    }
    return 0;
}

