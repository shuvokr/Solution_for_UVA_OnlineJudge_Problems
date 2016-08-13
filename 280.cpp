#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

typedef vector< int > vi;

void DFS(int u);

bool mark[ 105 ];
vector < vi > graph;
int node, cou;

int main()
{
    int u, v, i, n;
    while( ~scanf("%d", &node) && node )
    {
        node++;
        graph.assign(node, vi());
        while(~scanf("%d", &u) && u)
        {
            while(~scanf("%d", &v) && v) graph[ u ].push_back( v );
        }
        scanf("%d", &i);
        while( i-- )
        {
            scanf("%d", &n); cou = 0;
            memset(mark, true, sizeof mark);
            DFS( n );
            printf("%d", node - cou - 1);
            for(u = 1; u < node; u++) if(mark[ u ]) printf(" %d", u);
            puts("");
        }
    }
    return 0;
}
void DFS(int u)
{
    for(int i = 0; i < graph[ u ].size(); i++)
    {
        int v = graph[ u ][ i ];
        if(mark[ v ])
        {
            mark[ v ] = false; cou++;
            DFS( v );
        }
    }
}
