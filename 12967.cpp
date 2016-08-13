#include <stdio.h>
int main()
{
    int T, n, i, j; scanf("%d", &T);
    long long ans[ 32 ], PT[ 32 ][ 32 ];
    PT[ 4 ][ 0 ] = 1; PT[ 4 ][ 1 ] = 3; PT[ 4 ][ 2 ] = 3; PT[ 4 ][ 3 ] = 1; PT[ 4 ][ 4 ] = 6;
    for(i = 5; i < 31; i++)
    {
        int sum = 0;
        PT[ i ][ 0 ] = PT[ i ][i - 1] = 1;
        for(j = 1; j < i - 1; j++) PT[ i ][ j ] = PT[i - 1][j - 1] + PT[i - 1][ j ], sum += PT[ i ][ j ];
        PT[ i ][ i ] = sum;
    }
    ans[ 1 ] = 1; ans[ 2 ] = 4; ans[ 3 ] = 12;
    for(i = 4; i < 31; i++)
    {
        ans[ i ] = 4ll + PT[ i ][ i ] * 4ll;
    }
    while( T-- )
    {
        scanf("%d", &n);
        printf("%lld\n", ans[ n ]);
    }
    return 0;
}

