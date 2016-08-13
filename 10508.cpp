#include <stdio.h>
char map[ 2000 ][ 2000 ];
int ind[ 2000 ];
int main()
{
    int N, n, M, m, i, j;
    while(~scanf(" %d %d",&N, &M))
    {
        gets( map[ 0 ] );
        gets( map[ 0 ] );
        ind[ 0 ] = 0;
        for(n = 1; n < N; n++)
        {
            gets(map[ n ]);
            int c = 0;
            for(i = 0; i < M; i++)
                c += map[ 0 ][ i ] != map[ n ][ i ] ? 1 : 0;
            ind[ c ] = n;
        }
        for(i = 0; i < N; i++) puts(map[ind[ i ]]);
    }
    return 0;
}
