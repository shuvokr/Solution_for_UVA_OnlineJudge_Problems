/*
        Shuvo
        Problrm algo: Flood fill
        Problem ID: 785
        Problem name: Grid Colouring
*/
//Templet start
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
#define pb push_back
#define maxn 200000+2
#define row 30+2
#define col 80+2

#define white 0
#define black 1

typedef vector <int> vi;

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

//Templet end
void input();
void BFS(int x, int y);
bool isvalid(int x, int y);
void print();

char graph[ row ][ col ], take;
bool mark[ row ][ col ];
int k, co;

int main()
{
    input();

    return 0;
}
void input()
{
    int i, j, len, cou;
    bool ck = true;
    k = co = 0;
    while( gets(graph[ k ]))
    {
        len = strlen( graph[ k ] );
        //Cheak for stop input
        if(graph[ k ][ 0 ] == '_')
        {
            j = 0;
            fo(i, len) if(graph[ k ][ i ] == '_') j++;
            if(j != len)
            {
                co = max(co, len);
                continue;
            }
        }
        else
        {
            co = max(co, len);
            k++; continue;
        }
        //**********************

        fo(i, k) fo(j, co) mark[ i ][ j ] = true;
        fo(i, k)
        {
            fo(j, strlen(graph[ i ]))
            {
                if(graph[ i ][ j ] != ' ' && graph[ i ][ j ] != 'X' && mark[ i ][ j ])
                {
                    take = graph[ i ][ j ];
                    BFS(i, j);
                }
            }
        }
        print();
        k = 0; co = 0; mem(graph, 0);
    }
}
void BFS(int x, int y)
{
    int i, j, tmp1, tmp2;
    queue <int> Q;
    mark[ x ][ y ] = false;
    graph[ x ][ y ] = take;
    Q.push( x ); Q.push( y );

    while(!Q.empty())
    {
        tmp1 = Q.front(); Q.pop();
        tmp2 = Q.front(); Q.pop();
        fo(i, 4)
        {
            x = tmp1 + diraction1[ i ];
            y = tmp2 + diraction2[ i ];
            if(isvalid(x, y))
            {
                mark[ x ][ y ] = false;
                graph[ x ][ y ] = take;
                Q.push( x ); Q.push( y );
            }
        }
    }
}
bool isvalid(int x, int y)
{
    if(x < 0 || y < 0 || x == k || y == strlen(graph[ x ]) || graph[ x ][ y ] == 'X' || !mark[ x ][ y ] || graph[ x ][ y ] == take) return false;
    return true;
}
void print()
{
    for(int i = 0; i <= k; i++) puts(graph[ i ]);
}
