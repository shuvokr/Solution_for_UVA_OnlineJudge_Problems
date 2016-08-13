#include <stdio.h>
#include <string.h>
#include <ctype.h>

char in[ 100 ];
int res[ 35 ], len, i, r, k;
int main()
{
    k = 0; memset(res, 0, sizeof res);
    while(gets( in ))
    {
        if(in[ 0 ] == NULL) break;
        if(in[ 0 ] == '#')
        {
            if( k ) res[ k ]++;
            for(i = 1; i < 31; i++)
                if(res[ i ]) printf("%d %d\n", i, res[ i ]);
            puts("");
            memset(res, 0, sizeof res); k = 0;
        }
        else
        {
            len = strlen( in );
            for(i = 0; i < len; i++)
            {
                while(i < len && (isalpha(in[ i ]) || in[ i ] == 39 || in[ i ] == 45))
                {
                    i++;
                    k += in[ i ] != 39 && in[ i ] != 45 ? 1 : 0;
                }
                if(i != len || ( i == len && in[len - 1] != '-')) res[ k ]++, k = 0;
            }
        }
    }
    return 0;
}
