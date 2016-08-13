#include <stdio.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    int n, T, i, w, a, t, b, kag = 0;
    char in[ 15 ];
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d", &n); getchar();
        gets( in );
        a = b = t = w = 0;
        for(i = 0; i < n; i++)
        {
            in[ i ] == 'B' ? b++ :
                in[ i ] == 'A' ? a++ :
                    in[ i ] == 'T' ? t++ : w++;
        }
        a == n ? printf("Case %d: ABANDONED\n", ++kag) :
            b == w ? printf("Case %d: DRAW %d %d\n", ++kag, b, t) :
                a + b == n ? printf("Case %d: BANGLAWASH\n", ++kag) :
                    a + w == n ? printf("Case %d: WHITEWASH\n", ++kag) :
                        b > w ? printf("Case %d: BANGLADESH %d - %d\n", ++kag, b, w) :
                            printf("Case %d: WWW %d - %d\n", ++kag, w, b);
    }
    return 0;
}
