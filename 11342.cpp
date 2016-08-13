#include <stdio.h>
#include <math.h>

int main()
{
    int T, a, b, c, tmp, len, x, n, p;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d", &n); p = 1;
        len = sqrt( n ) + 1;
        for(a = 0; a < len; a++)
            for(b = a; b < len; b++)
            {
                tmp = a * a + b * b;
                c = n - tmp; x = sqrt( c );
                if(x * x == c && n == tmp + c) printf("%d %d %d\n", a, b, x), p = 0, a = b = c = len;
            }
        if( p ) puts("-1");
    }
    return 0;
}
