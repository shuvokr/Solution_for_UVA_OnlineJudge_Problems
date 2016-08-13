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

void input();
void horseBFS(int index1, int index2);
void kingBFS(int index1, int index2);
bool isvalid(int m, int n);

int row, col, end_point1, end_point2;
char graph[ 101 ][ 101 ];
int cost[ 101 ][ 101 ];

int kingd1[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int kingd2[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

int main()
{
    input();

    return 0;
}
void input()
{
    int T, i, j;
    sf("%d", &T);
    while( T-- )
    {
        sf("%d %d", &row, &col);
        getchar();
        fo(i, row) gets( graph[ i ] );

        fo(i, row)
        {
            fo(j, col)
            {
                if(graph[ i ][ j ] == 'Z')
                {
                    horseBFS(i, j);
                }
            }
        }

        fo(i, row) fo(j, col) cost[ i ][ j ] = INF;

        end_point1 = -1;
        end_point2 = -1;
        fo(i, row)
        {
            fo(j, col)
            {
                if(graph[ i ][ j ] == 'A')
                {
                    kingBFS(i, j);
                    i = row; j = col;
                }
            }
        }
        if(end_point1 == -1 && end_point2 == -1) puts("King Peter, you can't go now!");
        else pf("Minimal possible length of a trip is %d\n", cost[ end_point1 ][ end_point2 ]);
    }
}
void horseBFS(int index1, int index2)
{
    int i, j, tmp1, tmp2;
    queue < int > Q;
    Q.push( index1 ); Q.push( index2 );

    while(!Q.empty())
    {
        tmp1 = Q.front(); Q.pop();
        tmp2 = Q.front(); Q.pop();

        fo(i, 8)
        {
            index1 = tmp1 + horsed1[ i ];
            index2 = tmp2 + horsed2[ i ];

            if(isvalid( index1, index2 ))
            {
                if(graph[ index1 ][ index2 ] == '.')
                {
                    graph[ index1 ][ index2 ] = '#';
                }
                else if(graph[ index1 ][ index2 ] == 'Z')
                {
                    graph[ index1 ][ index2 ] = '#';
                    Q.push( index1 ); Q.push( index2 );
                }
            }
        }
    }
}
void kingBFS(int index1, int index2)
{
    int i, j, tmp1, tmp2;
    queue < int > Q;
    Q.push( index1 ); Q.push( index2 );
    cost[ index1 ][ index2 ] = 0;

    while(!Q.empty())
    {
        tmp1 = Q.front(); Q.pop();
        tmp2 = Q.front(); Q.pop();

        fo(i, 8)
        {
            index1 = tmp1 + kingd1[ i ];
            index2 = tmp2 + kingd2[ i ];

            if( isvalid( index1, index2 ) )
            {
                if(graph[ index1 ][ index2 ] == '.')
                {
                    Q.push( index1 ); Q.push( index2 );
                    if(cost[ index1 ][ index2 ] == INF)
                        cost[ index1 ][ index2 ] = cost[ tmp1 ][ tmp2 ] + 1;
                    graph[ index1 ][ index2 ] = '#';
                }
                else if(graph[ index1 ][ index2 ] == 'B')
                {
                    graph[ index1 ][ index2 ] = '#';
                    end_point1 = index1;
                    end_point2 = index2;
                    if(cost[ index1 ][ index2 ] == INF)
                        cost[ index1 ][ index2 ] = cost[ tmp1 ][ tmp2 ] + 1;
                }
            }
        }
    }
}
bool isvalid(int m, int n)
{
    if(m >= row || n >= col || m < 0 || n < 0) return false;
    return true;
}

