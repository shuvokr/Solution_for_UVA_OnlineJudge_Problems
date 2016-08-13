#include <stdio.h>

int main()
{
    int len, x, y, ans, T, kag = 0, i, tmp;
    char a[ 110 ], b[ 110 ]; scanf("%d", &T);
    while( T-- )
    {
        scanf("%d %s %s", &len, a, b);
        ans = 0;
        for(i = 0; i < len; i++)
        {
            x = a[ i ] - 48;
            y = b[ i ] - 48;
            int s = 0, ss = 0;
            int xx = x, yy = y;
            while(xx != yy)
            {
                xx++;
                s++;
                if(xx == 10) xx = 0;
            }

            xx = x, yy = y;
            while(xx != yy)
            {
                xx--;
                ss++;
                if(xx == -1) xx = 9;
            }
            ans += s < ss ? s : ss;
        }
        printf("Case %d: %d\n", ++kag, ans);
    }
    return 0;
}
