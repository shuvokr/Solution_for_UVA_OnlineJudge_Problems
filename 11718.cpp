#include <stdio.h>
long long bigmod ( long long a, long long p, long long md )
{
    long long res = 1, x = a;
    while ( p )
    {
        if ( p & 1 ) res = ( res * x ) % md;
        x = ( x * x ) % md;
        p >>= 1;
    }
    return res;
}

long long ans, mod, k, arlen, in[ 1010 ], sum;

int main()
{
    int T, kag = 0, n, i;
    scanf("%d", &T);
    arlen = 2;
    while( T-- )
    {
        scanf("%d %lld %lld", &n, &k, &mod);
        for(i = 0; i < n; i++) scanf("%lld", &in[ i ]), sum += in[ i ];

        if(k == 1) printf("Case %d: %lld\n", ++kag, sum % mod);
        else
        {
            sum = bigmod(n, k - 1, mod);
            sum *= k; sum %= mod;
            ans = 0;
            for(i = 0; i < n; i++)
            {
                ans += ((in[ i ] * sum) % mod);
                ans %= mod;
            }
            printf("Case %d: %lld\n", ++kag, ans % mod);
        }
    }
    return 0;
}
