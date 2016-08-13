#include <stdio.h>
#include <string.h>
int main()
{
    int kag = 0, i, T, tmp, d1, y1, d2, y2, res;
    char st[ 20 ], ls[ 20 ];
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%s %d,%d %s %d,%d", st, &d1, &y1, ls, &d2, &y2);
        if(strcmp(st, "January") && strcmp(st, "February")) y1++;
        if( (ls[ 0 ] == 'J' && ls[ 1 ] == 'a') || (ls[ 0 ] == 'F' && d2 < 29) ) y2--;
        y1--;
        res = y2 / 4 - y1 / 4;
        res -= y2 / 100 - y1 / 100;
        res += y2 / 400 - y1 / 400;
        printf("Case %d: %d\n", ++kag, res);
    }
    return 0;
}
