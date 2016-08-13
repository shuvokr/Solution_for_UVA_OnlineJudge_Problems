/*
    Shuvo
    Problem Algo: Ad Hoq
*/
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    char mappign[ 128 ], A[ 100 ], B[ 100 ];
    int T, lenA, lenB, i;

    scanf("%d", &T);
    getchar();
    getchar();
    while( T-- )
    {
        gets( A ); gets( B );
        lenA = strlen( A ); lenB = strlen( B );
        for(i = 0; i < 128; i++) mappign[ i ] = i;
        for(i = 0; i < lenA || i < lenB; i++)
        {
            A[ i ] = lenA <= i ? ' ' : A[ i ];
            B[ i ] = lenB <= i ? ' ' : B[ i ];
            mappign[ A[ i ] ] = B[ i ];
        }
        puts( B ); puts( A );
        while( gets( A ) )
        {
            lenA = strlen( A );
            if( !lenA ) break;
            for(i = 0; i < lenA ; i++) printf("%c", mappign[ A[ i ] ]);
            puts("");
        }
        if( T ) puts("");
    }
    return 0;
}
