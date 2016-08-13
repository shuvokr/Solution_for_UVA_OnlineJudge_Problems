#include <stdio.h>
#include <string.h>
int main()
{
    char num[ 1010 ];
    int T, n, div, sk, len, i, j, mod, cou;
    scanf("%d", &T);
    while( T-- )
    {
        getchar();
        gets( num ); len = strlen( num );
        scanf("%d", &n); sk = cou = 0;
        for(i = 0; i < n; i++)
        {
            scanf("%d", &div);
            if( !sk )
            {
                mod = 0;
                for(j = 0; j < len; j++)
                    mod = (mod * 10 + (num[ j ] - '0')) % div;
                cou += !mod ? 1 : 0;
                sk = !mod ? 0 : 1;
            }
        }
        ( cou == n ) ? printf("%s - Wonderful.\n", num) : printf("%s - Simple.\n", num);
    }
    return 0;
}
