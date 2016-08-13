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

#define white 1
#define red 2

void input();
bool BFS(int row);
bool boder_cheak(int x, int y);

int node, edge, Graph[ 202 ][ 202 ];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    input();

    return 0;
}
void input()
{
    int i, j, r, c;
    bool res;
    while(sf("%d", &node) != EOF)
    {
        if(node == 0) break;
        res = true;
        sf("%d", &edge); mem( Graph );
        fo(i, edge)
        {
            sf("%d%d", &r, &c);
            Graph[ r ][ c ] = 1;
        }
        res = BFS( r );
        if( res ) puts("BICOLORABLE.");
        else puts("NOT BICOLORABLE.");
    }
}
bool BFS(int row)
{
    int i, j, tmp1, tmp2, mark;
    queue < int > Q;
    int color[ 201 ]; mem( color );
    Q.push( row );
    color[ row ] = white;
    while(!Q.empty())
    {
        tmp1 = Q.front(); Q.pop();
        fo(i, node)
        {
            if( boder_cheak(tmp1, i) )
            if(Graph[ tmp1 ][ i ] == 1)
            {
                Graph[ tmp1 ][ i ] = 0;
                if(color[ tmp1 ] == color[ i ]) return false;
                if(color[ tmp1 ] == white) color[ i ] = red;
                else color[ i ] = white;
                Q.push( i );
            }
        }
    }
    return true;
}
bool boder_cheak(int x, int y)
{
    if(x == node || y == node || x < 0 || y < 0) return false;
    return true;
}

