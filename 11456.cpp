#include <stdio.h>
int v[ 2048 ], lds[ 2048 ], lis[ 2048 ];
int min(int x, int y){ return x < y ? x : y; }
int max(int x, int y){ return x > y ? x : y; }
int main(void)
{
    int t, i, j, ans, n; scanf("%d", &t);
    for(; t-- ; )
    {
        scanf("%d", &n);
        for(i = 0; i < n; ++i) scanf("%d", &v[i]), lis[i] = lds[i] = 1;
        for(i = n - 1; i > -1; --i)
            for(j = i - 1; j > -1; --j)
                if(v[ i ] > v[ j ]) lis[ j ] = max(lis[ j ], lis[ i ] + 1);
                else if(v[ j ] > v[ i ]) lds[ j ] = max(lds[ j ], lds[ i ] + 1);
        ans = 0;
        for(i = 0; i < n; ++i) ans = max(ans, lis[ i ] + lds[ i ] - 1);
        printf("%d\n", ans);
    }
    return 0;
}

