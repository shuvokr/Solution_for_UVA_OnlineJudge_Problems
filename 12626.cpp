#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    int map[ 92 ], i, len, T, res, tmp;
    char in[ 602 ];
    scanf("%d", &T); getchar();

    while(T--)
    {
        gets( in ); res = 100000;
        len = strlen( in );
        for(i = 65; i < 91; i++) map[ i ] = 0;
        for(i = 0; i < len; i++) map[ in[ i ] ]++;
        tmp = map[ 'M' ];
        if(res > tmp) res = tmp;
        tmp = map[ 'A' ] / 3;
        if(res > tmp) res = tmp;
        tmp = map[ 'R' ] / 2;
        if(res > tmp) res = tmp;
        tmp = map[ 'G' ];
        if(res > tmp) res = tmp;
        tmp = map[ 'I' ];
        if(res > tmp) res = tmp;
        tmp = map[ 'T' ];
        if(res > tmp) res = tmp;
        printf("%d\n", res);
    }

    return 0;
}
