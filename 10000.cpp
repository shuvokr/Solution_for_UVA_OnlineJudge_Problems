/*****************************************

    Shuvo
    Problem name: Longest Paths
    Problem ID: 10000
    Problem algo: Graph (Easy: DFS)
    Note: Empty

******************************************/
#include <stdio.h>
#include <vector>
using namespace std;
typedef vector<int> vi;
void DFS(int u);
vector<vi> graph;
int point, cou, cost[ 102 ], start;
int main()
{
    int i, node, u, v, kag = 0;
    while( ~scanf("%d", &node) && node )
    {
        graph.assign(node + 2, vi());
        scanf("%d", &start);
        while(~scanf("%d %d", &u, &v) && (u || v)) graph[ u ].push_back( v );
        node++; for(i = 1; i < node; i++) cost[ i ] = 0;
        cou = 0; DFS( start );
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", ++kag, start, cou, point);
    }
    return 0;
}
void DFS(int u)
{
    int i = 0, len = graph[ u ].size();
    for(; i < len; i++)
    {
        int v = graph[ u ][ i ];
        if(v != start)
        if(cost[ v ] < cost[ u ] + 1)
        {
            cost[ v ] = cost[ u ] + 1;
            if(cou < cost[ v ])
            {
                cou = cost[ v ];
                point = v;
            }
            if(cou == cost[ v ])
                if(point > v) point = v;
            DFS( v );
        }
    }
}
