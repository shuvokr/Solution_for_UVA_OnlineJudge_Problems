#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
bool isok(char n[])
{
    for(int i = 0; i < strlen( n ); i++) if(n[ i ] != '1') return false;
    return true;
}
int main()
{
    char a[ 12 ], b[ 12 ], c[ 12 ], tmp[ 12 ];
    int s, aa, bb, cc, T;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%s + %s = %s", a, b, c);
        int ok = 0, k = 0, carry = 0, p = 0;

        if(isok(a) && isok(b) && isok(c) && strlen(a) + strlen(b) == strlen(c))
        {
            puts("1");
            continue;
        }

        reverse(a, a + strlen(a));
        reverse(b, b + strlen( b ));
        int lena = strlen( a ), lenb = strlen( b ), len = max(lena, lenb);
        for(s = 2; s < 19; s++)
        {
            p = 0; k = 0;
            for(int j = 0; j < len; j++)
            {
                if(j < lena) p += a[ j ] - 48;
                if(j < lenb) p += b[ j ] - 48;
                p += carry; carry = 0;
                if(p >= s)
                {
                    p = p - s;
                    carry++;
                }
                if(p == 0) tmp[ k++ ] = 48;
                else
                while( p )
                {
                    tmp[ k++ ] = (p % 10) + 48;
                    p /= 10;
                }
                p = 0;
            }
            while( carry )
            {
                tmp[ k++ ] = (carry % 10) + 48;
                carry /= 10;
            }
            tmp[ k ] = NULL;
            reverse(tmp, tmp + strlen(( tmp )));
            if(strcmp(tmp, c) == 0)
            {
                printf("%d\n", s);
                ok = 1;
                s = 20;
            }
        }
        if( !ok ) puts("0");
    }
    return 0;
}
