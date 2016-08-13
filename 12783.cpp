#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1010;
void input();
void reset();
void DFS( int u );

int dfs_num[ maxn ], dfs_low[ maxn ], parents[ maxn ], dfs_counter, node, res_number, edge;
vector <int> graph[ maxn ];
vector <int> res[ maxn ];

int main()
{
    input();

    return 0;
}
void input()
{
    int i, j, u, n, v, T, k = 0, kag = 0;

    while(~scanf("%d %d", &node, &edge) && (node || edge))
    {
        reset();
        for(i = 0; i < edge; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            graph[ a ].push_back( b );
            graph[ b ].push_back( a );
        }
        dfs_counter = res_number = 0;
        for(i = 0; i < node; i++)
            if(graph[ i ].size() > 0) DFS( i );

        printf("%d", res_number);
        if(res_number > 0)
        {
            sort(res, res + res_number);
            for(i = 0; i < res_number; i++)
                printf(" %d %d", res[ i ][ 0 ], res[ i ][ 1 ]);
        }
        puts("");
    }
}

void reset()
{
    int i;
    for(i = 0; i < node; i++)
    {
        graph[ i ].clear();
        res[ i ].clear();
        parents[ i ] = -1;
        dfs_low[ i ] = 0;
        dfs_num[ i ] = -1;
    }
}
void DFS(int u)
{
    dfs_low[ u ] = dfs_counter;
    dfs_num[ u ] = dfs_counter;
    dfs_counter++;
    int i, ll = graph[ u ].size();
    for(i = 0; i <  ll; i++)
    {
        int v = graph[ u ][ i ];
        if( dfs_num[ v ] == -1 )
        {
            parents[ v ] = u;
            DFS( v );
            if(dfs_num[ u ] < dfs_low[ v ])
            {
                if(u < v)
                {
                    res[ res_number ].push_back( u );
                    res[ res_number ].push_back( v );
                }
                else
                {
                    res[ res_number ].push_back( v );
                    res[ res_number ].push_back( u );
                }
                res_number++;
            }
            dfs_low[ u ] = min(dfs_low[ u ], dfs_low[ v ]);
        }
        else if(parents[ u ] != v)
        {
            dfs_low[ u ] = min(dfs_low[ u ], dfs_num[ v ]);
        }
    }
}
