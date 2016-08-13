#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
vector < vi > graph;
struct data
{
    int u, v, cost;
}in[ 25005 ];
int node, edge, cst, i, j, T, source, kag, u, v, len;
int main()
{
    queue <int> Q;
    kag = 0;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d %d %d", &node, &edge, &source);
        graph.assign(node + 2, vi()); j = 1;
        for(i = 0; i < edge; i++)
        {
            scanf("%d %d %d", &u, &v, &cst);
            in[ i ].cost = 0;
            in[ i ].u = u; in[ i ].v = v;
            graph[ u ].push_back( v );
            graph[ v ].push_back( u );
        }
        Q.push( source );
        cst = 1;
        while(!Q.empty())
        {
            u = Q.front(); Q.pop();
            len = graph[ u ].size();
            for(i = 0; i < len; i++)
            {
                v = graph[ u ][ i ];
                for(j = 0; j < edge; j++)
                {
                    if(((in[j].u == u && in[j].v == v) || (in[j].u == v && in[j].v == u)) && !in[j].cost)
                    {
                        in[ j ].cost = cst++;
                        Q.push( v );
                        j = edge;
                    }
                }
            }
            if(cst == edge-1)
                while(!Q.empty())
                    Q.pop();
        }
        printf("Case %d:\n", ++kag);
        for(i = 0; i < edge; i++)
            if( !in[i].cost ) printf("%d %d %d\n", in[i].u, in[i].v, cst), cst++;
            else printf("%d %d %d\n", in[i].u, in[i].v, in[i].cost);
    }
    return 0;
}
