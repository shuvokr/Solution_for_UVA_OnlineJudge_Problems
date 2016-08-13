#include <stdio.h>

int n, t;
long long fact[ 13 ];
long long ar[] = {0, 1, 2, 9, 44, 265, 1854, 14833, 133496, 1334961, 14684570, 176214841};

int main()
{
    long long i;
    fact[ 1 ] = 1;
    for(i = 2; i < 13; i++) fact[ i ] = fact[i - 1] * i;

    int T; scanf("%d", &T);
    while( T-- )
    {
        scanf("%d", &n);
        printf("%lld/%lld\n", ar[n - 1], fact[ n ]);
    }

    return 0;
}

