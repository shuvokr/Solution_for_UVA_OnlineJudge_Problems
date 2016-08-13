/*
        Shuvo
        1174 - Commandos
*/
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
#define INF -1
#define maxn 100+2

void input();
void SBFS(int sorce);
void BFS(int sorce);

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

int graph[ maxn ][ maxn ], node, edge, end, scost[ maxn ], ecost[ maxn ], maximum;
queue < int > Q;

int main()
{
    input();

    return 0;
}
void input()
{
    int i, j, r, c, T, kag = 0, src;
    sf("%d", &T);
    while(T--)
    {
        sf("%d %d", &node, &edge);
        fo(i, node)
        {
            scost[ i ] = INF;
            ecost[ i ] = INF;
            fo(j, node)
            {
                graph[ i ][ j ] = 0;
            }
        }

        fo(i, edge) sf("%d %d", &r, &c), graph[ r ][ c ] = 1, graph[ c ][ r ] = 1;

        sf("%d %d", &src, &end);
        scost[ src ] = 0;
        ecost[ end ] = 0;
        maximum = INF;
        SBFS( src );
        BFS( end );

        fo(i, node)
        {
            //pf("%d >> %d %d\n", i, scost[ i ], ecost[ i ]);
            maximum = max(maximum, scost[ i ] + ecost[ i ]);
        }

        pf("Case %d: %d\n", ++kag, maximum);
    }
}
void SBFS(int sorce)
{
    int i, j, tmp;
    queue <int> Q;
    bool mark[ maxn ];
    fo(i, node) mark[ i ] = true;
    Q.push( sorce );
    while(!Q.empty())
    {
        tmp = Q.front(); Q.pop();
        mark[ tmp ] = false;
        fo(i, node)
        {
            if(graph[ tmp ][ i ] == 1 && scost[ i ] == INF)
            {
                scost[ i ] = scost[ tmp ] + 1;
                Q.push( i );
            }
        }
    }
}
void BFS(int sorce)
{
    int i, j, tmp;
    queue <int> Q;
    bool mark[ maxn ];
    fo(i, node) mark[ i ] = true;
    Q.push( sorce );
    while(!Q.empty())
    {
        tmp = Q.front(); Q.pop();
        mark[ tmp ] = false;
        fo(i, node)
        {
            if(graph[ tmp ][ i ] == 1 && ecost[ i ] == INF)
            {
                ecost[ i ] = ecost[ tmp ] + 1;
                Q.push( i );
            }
        }
    }
}
