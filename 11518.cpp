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
#define fo(i, n) for(i = 1; i <= n; i++)
#define of(i, n) for(i = n - 1; i >= 0; i--)
#define mem(n, v) memset(n, v, sizeof( n ))
#define eps 1e-8
#define INF 2147483646
#define maxn 10000+2

void input();
int BFS();

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

int node, edge, l, cou;
vector < int > graph[ maxn ];
queue <int> Q;

int main()
{
    input();

    return 0;
}
void input()
{
    int i, j, T, r, c;
    sf("%d", &T);
    while(T--)
    {
        sf("%d %d %d", &node, &edge, &l);
        fo(i, node) graph[ i ].clear();
        fo(i, edge)
        {
            sf("%d %d", &r, &c);
            graph[ r ].push_back( c );
        }
        while(!Q.empty()) Q.pop();
        fo(i, l)
        {
            sf("%d", &r);
            Q.push( r );
        }
        pf("%d\n", BFS());
    }
}
int BFS()
{
    int tmp, i;
    cou = 0;
    bool mark[ maxn ];
    fo(i, node) mark[ i ] = false;
    while(!Q.empty())
    {
        tmp = Q.front(); Q.pop();
        mark[ tmp ] = true;
        for(i = 0; i < graph[ tmp ].size(); i++)
        {
            if(graph[ tmp ][ i ] != 0)
            {
                Q.push( graph[ tmp ][ i ] );
                graph[ tmp ][ i ] = 0;
            }
        }
    }
    fo(i, node) if(mark[ i ]) cou++;
    return cou;
}
