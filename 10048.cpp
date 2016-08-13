#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> vi;
#define CLR(n, v) memset(n, true, v)
int find_repragentative(int child);
void find_res(int x, int y);
void DFS(int u);
struct data
{
    int u, v, cost;
    bool operator< (const data &sk) const
    {
        return cost < sk.cost;
    }
}edge[ 1010 ];
int par[ 1010 ], res, val[ 105 ][ 105 ], tt, pare[ 1010 ];
vector <vi> graph;
bool mark[ 110 ], tag, space = false;
int main()
{
    //freopen("out.txt", "w", stdout);
    int node, EDGE, Query, u, v, cst, kag = 0;
    while( ~scanf("%d %d %d", &node, &EDGE, &Query) && (node || Query || EDGE))
    {
        if(space) puts("");
        else space = true;
        for(int i = 0; i < EDGE; i++)
            scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].cost),
            val[edge[i].u][edge[i].v] = edge[i].cost,
            val[edge[i].v][edge[i].u] = edge[i].cost;
        for(int i = 1; i <= node; i++) par[ i ] = i;
        sort(edge, edge + EDGE);
        graph.assign(node + 3, vi());
        for(int i = 0; i < EDGE; i++)
        {
            u = find_repragentative(edge[i].u);
            v = find_repragentative(edge[i].v);
            if(u != v)
            {
                par[ v ] = u;
                graph[ edge[i].u ].push_back( edge[i].v );
                graph[ edge[i].v ].push_back( edge[i].u );
            }
        }
        printf("Case #%d\n", ++kag);
        for(int i = 0; i < Query; i++)
        {
            scanf("%d %d", &u, &v);
            if(!u || !v)
            {
                puts("0");
                continue;
            }
            if(find_repragentative( u ) == find_repragentative(v))
            {
                CLR(mark, node+2);
                memset(pare, -1, node + 2);
                res = -1; tag = false; tt = v;
                mark[ u ] = false;
                DFS( u );
                mark[ u ] =true;
                find_res( u, v );
                printf("%d\n", res);
            }
            else puts("no path");
        }
    }
    return 0;
}
int find_repragentative(int child)
{
    if(par[ child ] == child) return child;
    else return find_repragentative(par[ child ]);
}
void DFS(int u)
{
    int i, len = graph[ u ].size();
    for(i = 0; i < len; i++)
    {
        int v = graph[ u ][ i ];
        if(mark[ v ] && !tag)
        {
            pare[ v ] = u;
            if(v == tt) tag = true;
            mark[ v ] = false;
            DFS( v );
            mark[ v ] = true;
        }
    }
}
void find_res(int x, int y)
{
    if(y == x)
    {
        //res = val[ x ][ y ] < res ? res : val[ x ][ y ];
        return ;
    }
    else
    {
        res = val[ y ][ pare[ y ] ] < res ? res : val[ y ][ pare[ y ] ];
        //printf("%d ", y);
        return find_res(x, pare[ y ]);
    }
}
