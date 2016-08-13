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
#define maxn 1000+10
#define INF_max 2147483646

void input();
void FIRE_BFS(int index1, int index2);
int JOE_BFS(int index1, int index2);
bool isok(int m, int n);

char in[ maxn ][ maxn ];
int row, col;
int diraction1[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int diraction2[] = {0, 1, 0, -1, -1, 1, 1, -1};
int cost[ maxn ][ maxn ];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    input();

    return 0;
}
void input()
{
    int T, i, j, r, c, res, fire, x, y, tm1, tm2, a, b, xx, yy, cou;
    bool fck;
    sf("%d", &T);
    while(T--)
    {
        sf("%d%d", &row, &col);
        mem(in, 0);
        getchar();
        fo(i, row) gets( in[ i ] );

        fo(i, maxn) fo(j, maxn) cost[ i ][ j ] = INF_max;
        cou = 0; xx = -1; fck = true;
        fo(i, row)
        {
            fo(j, col)
            {
                if(in[ i ][ j ] == 'J')
                {
                    x = i; y = j;
                    cou++;
                }

                if(fck)
                    if(in[ i ][ j ] == 'F')
                    {
                        xx = i; yy = j;
                        cou++;
                        fck = false;
                    }
                if(cou == 2)
                {
                    i = row; j = col;
                }
            }
        }

        if(x == 0 || y == 0 || x == row - 1 || y == col - 1)
        {
            res = 1;
        }
        else
        {
            if(xx != -1) FIRE_BFS(xx, yy);

            res = JOE_BFS(x, y);
        }

        if(res == INF_max+1) puts("IMPOSSIBLE");
        else pf("%d\n", res);
    }
}
void FIRE_BFS(int index1, int index2)
{
    int i, j, tmp1, tmp2, maximum = INF_max;
    in[ index1 ][ index2 ] = '.';
    queue < int > Q;
    cost[ index1 ][ index2 ] = 0;
    Q.push( index1 ); Q.push( index2 );

    while(!Q.empty())
    {
        tmp1 = Q.front(); Q.pop();
        tmp2 = Q.front(); Q.pop();

        fo(i, 4)
        {
            index1 = tmp1 + diraction1[ i ];
            index2 = tmp2 + diraction2[ i ];

            if( isok( index1, index2 ) )
            {
                if(in[ index1 ][ index2 ] == 'F')
                {
                    cost[ index1 ][ index2 ] = 0;
                    in[ index1 ][ index2 ] = '.';
                    Q.push( index1 ); Q.push( index2 );
                }
                else if(in[ index1 ][ index2 ] == '.'  && cost[ tmp1 ][ tmp2 ] + 1 < cost[ index1 ][ index2 ])
                {
                    cost[ index1 ][ index2 ] = cost[ tmp1 ][ tmp2 ] + 1;
                    Q.push( index1 ); Q.push( index2 );
                }
            }
        }
    }
}
int JOE_BFS(int index1, int index2)
{
    int i, j, tmp1, tmp2, maximum = INF_max;
    queue < int > Q;
    cost[ index1 ][ index2 ] = 0;
    Q.push( index1 ); Q.push( index2 );

    while(!Q.empty())
    {
        tmp1 = Q.front(); Q.pop();
        tmp2 = Q.front(); Q.pop();

        fo(i, 4)
        {
            index1 = tmp1 + diraction1[ i ];
            index2 = tmp2 + diraction2[ i ];

            if( isok( index1, index2 ) )
                if(in[ index1 ][ index2 ] == '.' && cost[ index1 ][ index2 ] > cost[ tmp1 ][ tmp2 ] + 1)
                {
                    cost[ index1 ][ index2 ] = cost[ tmp1 ][ tmp2 ] + 1;

                    Q.push( index1 ); Q.push( index2 );
                    if(index1 == row - 1 || index2 == col - 1 || index1 == 0 || index2 == 0)
                        if(maximum > cost[ index1 ][ index2 ]) maximum = cost[ index1 ][ index2 ];
                }
        }
    }

    return maximum+1;
}
bool isok(int m, int n)
{
    if(m == row || n == col || m < 0 || n < 0) return false;
    return true;
}
