/*
    Shuvo
    Problem algo: DFS(Easy)
*/
#include <stdio.h>
#include <string.h>

using namespace std;

void DFS(int i, int j);

char graph[ 26 ][ 26 ];
int dir[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dic[] = {1, -1, 0, 0, -1, 1, 1, -1}, len;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T, i, j, r, max_res;
    scanf("%d", &T);
    getchar(); getchar();
    while( T-- )
    {
        memset(graph, -1, sizeof graph);
        r = 0; max_res = 0;
        while( gets(graph[ r ]))
        {
            i = strlen( graph[ r ]);
            if( !i ) break;
            r++;
        }
        for(i = 0; i < r; i++)
            for(j = 0; graph[ i ][ j ] == '1'; j++)
            {
                len = 1;
                DFS( i, j );
                max_res = max_res < len ? len : max_res;
            }

        printf("%d\n", max_res);
        if( T ) puts("");
    }
    return 0;
}
void DFS(int i, int j)
{
    graph[ i ][ j ] = '0';
    for(int k = 0; k < 8; k++)
    {
        int a = dir[ k ] + i, b = dic[ k ] + j;
        if(graph[ a ][ b ] == '1')
            len++, DFS(a, b);
    }
}
