#include <stdio.h>
#include <string.h>
void DFS(int s);
int cou[ 51 ];
int adjm[ 51 ][ 51 ], res[ 2020 ], k;

int main()
{
    int T, s, n, space = 0, i, a, b, c, kag = 0;
    scanf("%d", &T);
    while( T-- )
    {
        if(space) puts("");
        else space = 1;

        scanf("%d", &n);
        memset(cou, 0, 51);
        memset(adjm, 0, sizeof adjm);
        for(i = 0; i < n; i++)
        {
            scanf("%d %d", &a, &b);
            adjm[ a ][ b ]++;
            adjm[ b ][ a ]++;
            cou[ a ]++; cou[ b ]++;
            s = a;
        }
        printf("Case #%d\n", ++kag);
        for(i = 1; i < 51; i++)
            if(cou[ i ] % 2) space = 2, i = 51;
        if(space == 2)
        {
            puts("some beads may be lost");
            space = 1;
        }
        else
        {
            k = 0; DFS( s );
            for(i = 0; i < k - 1; i++) printf("%d %d\n", res[ i ], res[ i + 1 ]);
        }
    }
    return 0;
}
void DFS(int s)
{
    int i;
    for(i = 1; i < 51; i++)
    {
        if(adjm[ s ][ i ])
        {
            adjm[ s ][ i ]--; adjm[ i ][ s ]--;
            DFS( i );
        }
    }
    res[ k++ ] = s;
}
