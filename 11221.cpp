#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
int isok();
char in[ 10010 ], sms[ 10010 ], ch, make[ 102 ][ 102 ];
int i, k, r, c, T, kag = 0, len, cou;
int main()
{
    scanf("%d", &T); getchar();
    while( T-- )
    {
        gets( in ); k = 0;
        len = strlen( in );
        for(i = 0; i < len; i++) isalpha( in[ i ] ) ? sms[ k++ ] = in[ i ] : 0;
        sms[ k ] = NULL;
        len = sqrt( k );
        printf("Case #%d:\n", ++kag);
        if(len*len != k)
        {
            puts("No magic :(");
            continue;
        }
        cou = isok();
        if( !cou ) puts("No magic :(");
        else printf("%d\n", len);
    }
    return 0;
}
int isok()
{
    int root = len, i, a, b, c;
    char wanted;
    for(i = 0; i < k; ++i){
        wanted = sms[i];
        a = k - i - 1, b = (i % root) * root + i / root, c = k - b - 1;
        if(sms[a] != wanted || sms[b] != wanted || sms[c] != wanted) return 0;
    }
    return 1;
}
