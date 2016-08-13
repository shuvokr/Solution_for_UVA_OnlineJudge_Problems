#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
    long long i, j, pascal_tryangle[ 55 ][ 55 ];
    pascal_tryangle[ 1 ][ 0 ] = 1;
    pascal_tryangle[ 2 ][ 0 ] = 1;
    pascal_tryangle[ 2 ][ 1 ] = 1;
    for(i = 3; i < 52; i++)
    {
        pascal_tryangle[ i ][ 0 ] = pascal_tryangle[ i ][i - 1] = 1;
        for(j = 1; j < i - 1; j++) pascal_tryangle[ i ][ j ] = pascal_tryangle[i - 1][j - 1] + pascal_tryangle[i - 1][ j ];
    }
    char in[ 110 ], a[ 110 ], b[ 110 ], tmp[ 5 ];
    int T, kag = 0, k, x, y;
    scanf("%d", &T); getchar();
    while( T-- )
    {
        gets( in );

        i = 1; j = 0;
        while( in[ i ] != '+') a[ j++ ] = in[ i++ ]; a[ j ] = NULL; i++; j = 0;
        while( in[ i ] != ')') b[ j++ ] = in[ i++ ]; b[ j ] = NULL; i += 2; j = 0;
        while(i < strlen( in )) tmp[ j++ ] = in[ i++ ]; tmp[ j ] = NULL; k = atoi( tmp );

        //printf("%s %s %d\n", a, b, k);

        printf("Case %d: ", ++kag);
        x = k; y = 0; k++;
        if(x == 1) printf("%s", a);
        else if( x ) printf("%s^%d", a, x);
        x--;
        for(y = 1; y < k; y++)
        {
            putchar('+');
            if(pascal_tryangle[ k ][ y ] > 1) printf("%lld*", pascal_tryangle[ k ][ y ]);
            if(x == 1) printf("%s", a);
            else if( x ) printf("%s^%d", a, x);

            if( y && x ) putchar('*');
            if(y == 1) printf("%s", b);
            else if( y ) printf("%s^%d", b, y);
            x--;
        }
        puts("");
    }
    return 0;
}
