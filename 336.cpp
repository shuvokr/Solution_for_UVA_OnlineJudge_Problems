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

int input();
void BFS( int sorce );

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

int edge, node, TTL, cost[ 31 ];
bool graph[ 31 ][ 31 ];

int main()
{
    input();

    return 0;
}
int input()
{
    int i, j, k, r, c, kag = 0;
    while(sf("%d", &edge) != EOF)
    {
        if(edge == 0) return 0;
        map <int, int> nd;
        fo(i, 31) fo(j, 31) graph[ i ][ j ] = false;
        node = 1;
        fo(i, edge)
        {
            sf("%d %d", &r, &c);
            if(nd[ r ] == 0) nd[ r ] = node++;
            if(nd[ c ] == 0) nd[ c ] = node++;
            graph[ nd[ r ] ] [ nd[ c ] ] = graph[ nd[ c ] ][ nd[ r ] ] = true;
        }
        while(sf("%d %d", &r, &TTL) != EOF)
        {
            if(r + TTL == 0) break;
            mem(cost, -1);
            BFS( nd[ r ] );
            c = -1;
            fo(i, node)
            {
                if(cost[ i ] == -1 || cost[ i ] > TTL) c++;
            }
            pf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++kag, c, r, TTL);
        }
    }
}
void BFS( int sorce )
{
    int i, j, tmp;
    queue < int > Q;
    Q.push( sorce );
    cost[ sorce ] = 0;

    while(!Q.empty())
    {
        tmp = Q.front(); Q.pop();
        fo(i, node)
        {
            if(graph[ tmp ][ i ] && cost[ i ] == -1)
            {
                cost[ i ] = cost[ tmp ] + 1;
                Q.push( i );
            }
        }
    }
}
