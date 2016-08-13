#include <stdio.h>
int main()
{
    int n, m, graph[ 23 ][ 23 ], kag = 0;
    char name[ 23 ][ 25 ];
    while(scanf("%d %d", &n, &m) && n)
    {
        getchar(); n++;
        for(int i = 1; i < n; i++)
        {
            gets(name[ i ]);
            for(int j = 1; j < n; j++) graph[ i ][ j ] = 1 << 29;
        }
        printf("Case #%d : ", ++kag);
        if( !m )
        {
            puts(name[ 1 ]); continue;
        }
        graph[ 1 ][ 1 ] = graph[ 2 ][ 2 ] = graph[ 3 ][ 3 ] = graph[ 4 ][ 4 ] = 0;
        graph[ 8 ][ 8 ] = graph[ 7 ][ 7 ] = graph[ 6 ][ 6 ] = graph[ 5 ][ 5 ] = 0;
        graph[ 9 ][ 9 ] = graph[ 10 ][ 10 ] = graph[ 11 ][ 11 ] = graph[ 12 ][ 12 ] = 0;
        graph[ 16 ][ 16 ] = graph[ 15 ][ 15 ] = graph[ 14 ][ 14 ] = graph[ 13 ][ 13 ] = 0;
        graph[ 17 ][ 17 ] = graph[ 18 ][ 18 ] = graph[ 19 ][ 19 ] = graph[ 20 ][ 20 ] = 0;
        graph[ 22 ][ 22 ] = graph[ 21 ][ 21 ] = 0;
        for(int i = 0, u, v, cost; i < m; i++)
            scanf("%d %d %d", &u, &v, &cost), graph[ u ][ v ] = graph[ v ][ u ] = cost;

        for(int k = 1; k < n; k++)
            for(int i = 1; i < n; i++)
                for(int j = 1, x, y; j < n; j++)
                {
                    x = graph[ i ][ k ] + graph[ k ][ j ]; y = graph[ i ][ j ];
                    graph[ i ][ j ] = x < y ? x : y;
                }

        int min = 1 << 29, ind = 1;
        for(int i = 1; i < n; i++)
        {
            int sum = 0;
            for(int j = 1; j < n; j++) sum += graph[ i ][ j ];
            if(sum < min) min = sum, ind = i;
        }
        puts(name[ ind ]);
    }
    return 0;
}
