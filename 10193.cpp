#include <stdio.h>
#include <string.h>
int gcd( int a, int b ) { return b == 0 ? a : gcd(b, a % b); }
char s1[ 35 ], s2[ 35 ];
int T, len, kag, i, bit, val1, val2;
int main()
{
    kag = 0;
    scanf("%d", &T); getchar();
    while( T-- )
    {
        gets( s1 ); gets( s2 );

        len = strlen( s1 );
        bit = val1 = 0;
        for(i = len - 1; i > -1; i--)
        {
            val1 += s1[ i ] == '1' ? 1 << bit : 0;
            bit++;
        }

        len = strlen( s2 );
        bit = val2 = 0;
        for(i = len - 1; i > -1; i--)
        {
            val2 += s2[ i ] == '1' ? 1 << bit : 0;
            bit++;
        }
        printf("Pair #%d: ", ++kag);
        puts(gcd(val1, val2) == 1 ? "Love is not all you need!" : "All you need is love!");
    }
    return 0;
}
