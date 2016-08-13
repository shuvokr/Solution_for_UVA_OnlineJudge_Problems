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
#define maxn 51

void input();
bool cheak_result(int diraction, int i, int j);
bool isvalid(int i, int j);

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

char graph[ maxn ][ maxn ], in[ maxn ];
int row, col, len, pos;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    input();

    return 0;
}
void input()
{
    int T, i, j, k, tmp, n, r, c;
    bool result_cheak, space = false;
    sf("%d", &T);
    while(T--)
    {
        if( space ) puts("");
        else space = true;
        sf("%d %d", &row, &col);
        getchar();
        //memset(graph, 0, sizeof(graph));
        fo(i, row) gets( graph[ i ] );
        fo(i, row)
            fo(j, col)
                if(isupper(graph[ i ][ j ]))
                    graph[ i ][ j ] = graph[ i ][ j ] + 32;
        //fo(i, row) puts( graph[ i ] );
        sf("%d", &n); getchar();
        while(n--)
        {
            gets( in );
            len = strlen( in );
            fo(i, len)
                if(isupper(in[ i ]))
                    in[ i ] = in[ i ] + 32;

            fo(i, row)
                fo(j, col)
                {
                    if(graph[ i ][ j ] == in[ 0 ])
                    {
                        fo(k, 8)
                        {
                            pos = 1;
                            result_cheak = cheak_result( k, i, j );
                            if(result_cheak)
                            {
                                r = i + 1; c = j + 1;
                                k = 8; i = row; j = col;
                            }
                        }
                    }
                }
            pf("%d %d\n", r, c);
        }
    }
}
bool cheak_result(int diraction, int i, int j)
{
    int x, y;
    while(pos < len)
    {
        i = i + diraction1[ diraction ];
        j = j + diraction2[ diraction ];
        if(!isvalid(i, j)) return false;
        if(graph[ i ][ j ] != in[ pos ]) return false;
        pos++;
    }
    return true;
}
bool isvalid(int i, int j)
{
    if(i == row || i < 0 || j == col || j < 0) return false;
    return true;
}
