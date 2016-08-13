/*
        Shuvo
        uva 11953, Problem name: BattelShip, (DFS)
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
#define INF 5000
#define maxn 100+2

void input();

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

void input();
void DFS(int i, int j);
bool isvalid(int i, int j);

int rc;
char ship[ maxn ][ maxn ];

int main()
{
    input();

    return 0;
}
void input()
{
    int i, j, T, cou, kag = 0;
    sf("%d", &T);
    while(T--)
    {
        sf("%d", &rc);
        getchar(); cou = 0;
        fo(i, rc) gets( ship[ i ] );
        fo(i, rc)
        {
            fo(j, rc)
            {
                if(ship[ i ][ j ] == 'x')
                {
                    cou++;
                    DFS(i, j);
                }
            }
        }
        pf("Case %d: %d\n", ++kag, cou);
    }
}
void DFS(int i, int j)
{
    int k;
    if(!isvalid(i, j) || ship[ i ][ j ] == '.') return;
    ship[ i ][ j ] = '.';
    fo(k, 4) DFS(i+diraction1[ k ], j + diraction2[ k ]);
}
bool isvalid(int i, int j)
{
    if(i == rc || j == rc || i < 0 || j < 0) return false;
    return true;
}
