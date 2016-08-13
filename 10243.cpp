#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int dp(int pos, int flag);

typedef vector <int> vi;

vector <vi> graph;
int node, cou, par[ 1010 ], mamo[ 1010 ][ 2 ];
bool mark[ 1010 ][ 1010 ];

int main()
{
    while(~scanf("%d", &node) && node)
    {
        graph.assign(node + 5, vi());
        memset(mamo, -1, sizeof mamo);
        memset(par, -1, sizeof par);
        memset(mark, true, sizeof mark);

        for(int i = 0; i < node; i++)
        {
            scanf("%d", &cou);
            for(int j = 0, u; j < cou; j++)
            {
                scanf("%d", &u);
                if(mark[i + 1][ u ])
                {
                    mark[i + 1][ u ] = mark[ u ][i + 1] = false;
                    graph[ i + 1 ].push_back( u );
                    graph[ u ].push_back( i + 1 );
                }
            }
        }
        if(node == 1) puts("1");
        else printf("%d\n", min(dp(1, 0), dp(1, 1)));
    }
    return 0;
}
int dp(int pos, int flag)
{
    int len = graph[ pos ].size();
    if( !len ) return 0;
    if(mamo[ pos ][ flag ] != -1) return mamo[ pos ][ flag ];
    int ret = 0;
    for(int i = 0; i < len; i++)
    {
        int v = graph[ pos ][ i ];
        if(v != par[ pos ])
        {
            par[ v ] = pos;
            if( !flag ) ret += dp(v, 1);
            else ret += min(dp(v, 0), dp(v, 1));
        }
    }
    return mamo[ pos ][ flag ] = ret + flag;
}
