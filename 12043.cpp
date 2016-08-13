#include <cstdio>
#include <cstring>
#include <cmath>

int main()
{
    long long int n, b, c, d, i, j, k, l, max, cs, q, jog, jog1;
    int a[ 100001 ],sum[ 10001 ];
    scanf("%lld", &n);
    for(i = 1; i <= n; i++)
    {
        l = 0; jog = 0; jog1 = 0;
        scanf("%lld %lld %lld",&b, &c, &d);
        for(j = b; j <= c; j++)
        {
            if(!(j % d))
            a[ l++ ] = j;
        }
        for(k = 0; k < l; k++)
        {
            cs = 0;
            for(q = 1; q <= sqrt(a[ k ]) ; q++)
            {
                 if(a[ k ] % q == 0)
                 {
                     if(q != (a[ k ] / q))
                     {
                         sum[ cs++ ] = q;
                         sum[ cs++ ] =a[ k ] / q;
                         jog = jog + q + a[ k ] / q;
                     }
                     else
                     {
                         sum[ cs++ ] = q;
                         jog = jog + q;
                     }
                 }
            }
            jog1 = jog1 + cs;
        }
        printf("%lld %lld\n",jog1, jog);
    }
    return 0;
}
