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
#define black 2

void input();
int BFS(int row);
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
    int i, j, r, c, T, tot;
    int res;
    bool ck;
    sf("%d", &T);
    while(T--)
    {
        sf("%d %d", &node, &edge);
        mem( Graph );
        fo(i, edge)
        {
            sf("%d%d", &r, &c);
            Graph[ r ][ c ] = 1;
            Graph[ c ][ r ] = 1;
        }

        tot = 0;
        fo(i, node)
        {
            ck = true;
            fo(j, node)
            {
                if(Graph[ i ][ j ] == 1)
                {
                    ck = false;
                    j = node;
                }
            }
            if( ck ) tot++;
        }

        //pf("    %d\n ", tot);

        fo(i, node)
        {
            fo(j, node)
            {
                if(Graph[ i ][ j ] == 1)
                {
                    res = BFS( i );
                    tot += res;
                    if(res == -1) i = j = node;
                }
            }
        }

        if(res == -1) puts("-1");
        else pf("%d\n", tot);
    }
}
int BFS(int row)
{
    int i, j, tmp1, total = 0, col = 0, blk = 0, wht = 1;
    queue < int > Q;
    int color[ 201 ]; fo(i, 201) color[ i ] = 3;
    Q.push( row );
    color[ row ] = white;
    while(!Q.empty())
    {
        tmp1 = Q.front(); Q.pop();
        total++;
        fo(i, node)
        {
            if( boder_cheak(tmp1, i) )
            if(Graph[ tmp1 ][ i ] == 1)
            {
                Graph[ tmp1 ][ i ] = 0;
                Graph[ i ][ tmp1 ] = 0;
                if(color[ tmp1 ] == color[ i ]) return -1;
                //if(color[ rmp1 ] == 3) color[ tmp1 ] = white;
                if(color[ i ] == 3)
                    if(color[ tmp1 ] == white) color[ i ] = black, blk++;
                    else if(color[ tmp1 ] == black) color[ i ] = white, wht++;
                Q.push( i );
            }
        }
    }

    //pf("%d %d %d\n", blk, wht, total);
    //if(wht != 1)
        blk = min(blk, wht);
    if(total == 1) return 1;
    else
    {
        int a = min(blk, total - blk);
        return a;
    }
}
bool boder_cheak(int x, int y)
{
    if(x == node || y == node || x < 0 || y < 0) return false;
    return true;
}


