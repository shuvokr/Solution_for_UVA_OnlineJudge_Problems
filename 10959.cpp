#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define LLD long long
#define LD long
#define fo(i, n) for(i = 0; i < n; i++)
#define of(i, n) for(i = n - 1; i >= 0; i--)
#define mem(n) memset(n, 0, sizeof(n))
#define maxn 1000+2
#define maxe 499500+2
#define INF 2147483647

#define white 1
#define red 2

typedef vector < int > vi;

void input();
void BFS();

int node, edge, cost[ maxe ], graph[ maxn ][ maxn ];

int main()
{
    input();

    return 0;
}
void input()
{
    int T, i, j, r, c;
    sf("%d", &T);
    while(T--)
    {
        sf("%d%d", &node, &edge);
        fo(i, node)
            fo(j, node) graph[ i ][ j ] = 0;
        fo(i, edge)
        {
            sf("%d%d", &r, &c);
            graph[ r ][ c ] = 1;
            graph[ c ][ r ] = 1;
        }
        fo(i, node) cost[ i ] = INF;
        BFS();
        for(i = 1; i <  node; i++) pf("%d\n", cost[ i ]);
        if( T ) puts("");
    }
}
void BFS()
{
    int i, j, tmp;
    queue < int > Q;
    Q.push( 0 ); cost[ 0 ] = 0;
    while(!Q.empty())
    {
        tmp = Q.front(); Q.pop();
        fo(i, node)
        {
            if(graph[ tmp ][ i ] == 1 && cost[ i ] > cost[ tmp ] + 1)
            {
                cost[ i ] = cost[ tmp ] + 1;
                Q.push( i );
            }
        }
    }
}

