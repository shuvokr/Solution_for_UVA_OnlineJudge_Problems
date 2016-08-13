#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    char in[ 1010 ];
    int i, num, len;
    while(gets( in ) && in[ 0 ] != '0')
    {
        len = strlen( in );
        num = in[ 0 ] - 48;
        if(len > 1 && !(len&1)) num = num * 10 + in[ 1 ] - 48;
        len = ((len + 1) >> 1) - 1;
        for(i = 0; i < len; i++) in[ i ] = '0';
        in[ len ] = NULL;
        printf("%d", (int)sqrt( num )); puts( in );
    }
    return 0;
}
