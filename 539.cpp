#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
typedef vector<int> vi;
void DFS(int u);
vector <vi> graph;
bool vis[ 27 ], mark[ 27 ][ 27 ];
int node, edge, lenth, res;
int main()
{
    //freopen("input.txt", "r", stdin);
    int i, u, v;
    for(i = 0; i < 26; i++) for(int j = 0; j < 26; j++) mark[ i ][ j ] = true;
    while( ~scanf("%d %d", &node, &edge) && (node || edge) )
    {
        graph.assign(node + 1, vi());
        for(i = 0; i < edge; i++)
        {
            scanf("%d %d", &u, &v);
            graph[ u ].push_back( v );
            graph[ v ].push_back( u );
        }
        res = -1;
        for(i = 0; i < node; i++)
        {
            lenth = 0;
            memset(vis, true, node); DFS( i );
            res = lenth > res ? lenth : res;
        }
        printf("%d\n", res);
    }
    return 0;
}
void DFS(int u)
{
    vis[ u ] = false;
    int i = 0, v, len = graph[ u ].size();
    for(; i < len; i++)
    {
        v = graph[ u ][ i ];
        if(mark[ u ][ v ] || mark[ v ][ u ])
        {
            lenth++;
            mark[ u ][ v ] = false;
            mark[ v ][ u ] = false;
            DFS( v );
            res = lenth > res ? lenth : res;
            lenth--;
            mark[ u ][ v ] = true;
            mark[ v ][ u ] = true;
        }
    }
}
