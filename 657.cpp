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
#define maxn 50+2

int input();
void DFS(int i, int j);
void xDFS(int i, int j);
bool isvalid(int i, int j);

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int row, col, cou;

char graph[ maxn ][ maxn ];

int main()
{
    input();

    return 0;
}
int input()
{
    int i, j, k, kag = 0;
    int ans[ 2502 ];
    while(sf("%d %d", &col, &row) != EOF)
    {
        if(row + col == 0) return 0;
        getchar(); k = 0; cou = 0;
        fo(i, row) gets( graph[ i ] );
        cou = 0;
        fo(i, row)
        {
            fo(j, col)
            {
                if(graph[ i ][ j ] != '.')
                {
                    cou = 0;
                    DFS(i, j);
                    ans[ k ++ ] = cou;
                }
            }
        }
        sort(ans, ans + k);
        pf("Throw %d\n", ++kag);
        pf("%d", ans[0]);
        for(i = 1; i < k; i++) pf(" %d", ans[ i ]);
        puts("");
        puts("");
    }
}
void DFS(int i, int j)
{
    if(!isvalid(i, j) || graph[ i ][ j ] == '.') return;
    int k;
    fo(k, 4)
    {
        if(graph[ i ][ j ] == 'X')
        {
            cou++;
            xDFS(i, j);
        }
    }
    graph [ i ][ j ] = '.';
    fo(k, 4) DFS(i + diraction1[ k ], j + diraction2[ k ]);
}
void xDFS(int i, int j)
{
    if(!isvalid(i, j) || graph[ i ][ j ] != 'X') return;
    int k;
    graph[ i ][ j ] = '*';
    for(int k = 0; k < 4; k++)
    {
        xDFS(i + diraction1[ k ], j + diraction2[ k ]);
    }
}
bool isvalid(int i, int j)
{
    if(i == row || i < 0 || j == col || j < 0) return false;
    return true;
}
