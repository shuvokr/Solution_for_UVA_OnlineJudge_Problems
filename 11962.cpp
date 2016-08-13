#include <stdio.h>
#include <string.h>
long long power ( long long a, long long p ) { long long res = 1, x = a; while ( p ) { if ( p & 1 ) res = res * x; x = x * x; p >>= 1; } return res;}
int main()
{
    char in[ 35 ];
    long long len, ans, i;
    int T, kag = 0; scanf("%d", &T); getchar();
    while( T-- )
    {
        gets( in ); len = strlen( in ); ans = 0;
        for(i = 0; i < len; i++)
            if(in[ i ] == 'C') ans += power(4ll, len - i - 1);
            else if(in[ i ] == 'G') ans += 2ll * power(4ll, len - i - 1);
            else if(in[ i ] == 'T') ans += 3ll * power(4ll, len - i - 1);
        printf("Case %d: (%lld:%lld)\n", ++kag, len, ans);
    }
    return 0;
}
