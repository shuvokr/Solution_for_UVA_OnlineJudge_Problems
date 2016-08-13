#include <stdio.h>
#include <string.h>
int main()
{
    long long res, i, save[ 25 ], alpha[ 28 ];
    save[ 1 ] = 1;
    for(i = 2; i < 21; i++) save[ i ] = save[i - 1] * i;
    char in[ 25 ];
    int T, kag = 0;
    scanf("%d", &T); getchar();
    while( T-- )
    {
        gets( in );
        res = save[ strlen( in ) ];
        for(i = 0; i < 27; i++) alpha[ i ] = 0;
        for(i = 0; i < strlen( in ); i++) alpha[ in[ i ] - 'A' ]++;
        for(i = 0; i < 27; i++)
            if(alpha[ i ] > 1) res /= save[ alpha[ i ] ];
        printf("Data set %d: %lld\n", ++kag, res);
    }
    return 0;
}
