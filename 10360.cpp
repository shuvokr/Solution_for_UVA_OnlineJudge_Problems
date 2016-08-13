#include <cstdio>
#include <cstring>
int area[ 1025 ][ 1025 ];
int main()
{
    int T, x, y, d, n, die, res;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d %d", &d, &n);
        memset(area, 0, sizeof area);
        while( n-- )
        {
            scanf("%d %d %d", &x, &y, &die);
            for(int i = x - d; i < x + d + 1; i++)
                for(int j = y - d; j < y + d + 1; j++)
                    if(i > -1 && j > -1 && i < 1025 && j < 1025)
                        area[ i ][ j ] += die;
        }
        res = -1;
        for(int i = 0; i < 1025; i++)
            for(int j = 0; j < 1025; j++)
                if(area[ i ][ j ] > res)
                    x = i, y = j, res = area[ i ][ j ];
        printf("%d %d %d\n", x, y, res);
    }
    return 0;
}
