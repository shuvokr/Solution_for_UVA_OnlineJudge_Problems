#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define long long lld
#define llu unsigned long long
#define fo(i, n) for(i = 0; i < n; i++)
#define of(i, n) for(i = n - 1; i >= 0; i--)
#define mem(n, v) memset(n, v, sizeof( n ))
#define eps 1e-8
#define INF 5000
#define maxn 100+2

void input();
void DFS(int src);

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

int node, edge;
bool graph[ maxn ][ maxn ], mark[ maxn ], vis[ maxn ];
stack <int> res;

int main()
{
    input();

    return 0;
}
void input()
{
    int i, j, k, tmp, to, from;
    while(sf("%d %d", &node, &edge) != EOF)
    {
        if(node == 0 && edge == 0 ) break;
        for(i = 1; i <= node; i++)
            for(j = 1; j <= node; j++) graph[ i ][ j ] = false;
        for(i = 1; i <= node; i++) vis[ i ] = false, mark[ i ] = true;
        fo(i, edge)
        {
            sf("%d %d", &from, &to);
            graph[ from ][ to ] = true;
        }

        for(i = 1; i <= node; i++)
        {
            for(j = 1; j <= node; j++)
            {
                if(graph[ i ][ j ]) DFS( i );
            }
        }

        if(!res.empty())
        {
            pf("%d", res.top()); res.pop();
            while(!res.empty())
            {
                pf(" %d", res.top()); res.pop();
            }
        }
        if(edge == 0)
        {
             pf("1");
             for(i = 2; i <= node; i++) if(mark[ i ]) pf(" %d", i);
             puts("");
             continue;
        }
        for(i = 1; i <= node; i++) if(mark[ i ]) pf(" %d", i);
        puts("");
    }
}
void DFS(int src)
{
    for(int i = 1; i <= node; i++)
    {
        if(graph[ src ][ i ])
        {
            graph[ src] [ i ] = false;
            DFS( i );
        }
    }
    if( mark[ src ] )res.push( src );
    mark[ src ] = false;
    return;
}
