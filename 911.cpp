#include <stdio.h>
int gcd( int a, int b ) { return b == 0 ? a : gcd(b, a % b); }
int main()
{
    int res, p, ar[ 105 ], g, n, s, k, i, j, x[ 105 ], sum;
    while(~scanf("%d %d", &n, &k))
    {
        sum = n++;
        for(i = 2; i < n; i++) ar[ i ] = i;
        for(i = 0; i < k; i++)
            scanf("%d", &x[ i ]), sum -= x[ i ];
        if(sum){ puts("0"); continue; }
        for(p = 0; p < k; p++)
        {
            sum -= x[ p ]++;
            for(i = 2; i < x[ p ]; i++)
            {
                j = i;
                for(s = 2; s < n; s++)
                {
                    g = gcd(ar[ s ], j);
                    ar[ s ] /= g; j /= g;
                    s = j == 1 ? n : s;
                }
            }
        }
        res = 1;
        for(i = 2; i < n; i++) res *= ar[ i ];
        printf("%d\n", res);
    }
    return 0;
}
