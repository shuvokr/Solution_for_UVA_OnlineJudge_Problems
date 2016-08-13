#include <stdio.h>
#include <string.h>
#include <math.h>
int convert(int base);
char in[ 110 ];
int i, len, max, f, n, tmp;
int main()
{
    while(gets( in ))
    {
        len = strlen( in );
        if(len == 1 && in[ 0 ] == '0') return 0;
        f = max = 0;
        while(in[ f ] == 48) f++;
        for(i = f; i < len; i++) max = max > in[ i ] - 48 ? max : in[ i ] - 48;
        for(i = max + 1; i < 101; i++)
        {
            tmp = convert( i );
            n = sqrt( tmp );
            if(n * n == tmp) printf("%d\n", i), i = 101;
        }
    }
}
int convert(int base)
{
    int k, p = 0, ret = 0;
    for(k = f; k < len; k++)
        ret = ret * base + in[ k ] - 48;
    return ret;
}
