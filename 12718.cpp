#include <stdio.h>
#include <string.h>
int T, len, i, j, map[ 124 ], res, odd, kag, k;
char in[ 1005 ];
int main()
{
    kag = 0;
    scanf("%d", &T); getchar();
    while( T-- )
    {
        gets( in );
        len = strlen( in ); res = 0;
        for(i = 0; i < len; i++)
        {
            odd = 0;
            for(k = 97; k < 123; k++) map[ k ] = 0;
            for(j = i; j < len; j++)
            {
                map[ in[ j ] ]++;
                if(map[ in[ j ] ] == j - i + 1)
                {
                    res++;
                    odd += map[ in[ j ] ] % 2 ? 1 : -1;
                    continue;
                }
                odd += map[ in[ j ] ] % 2 ? 1 : -1;
                res += !odd || odd == 1  ? 1 : 0;
            }
        }
        printf("Case %d: %d\n", ++kag, res);
    }
    return 0;
}
