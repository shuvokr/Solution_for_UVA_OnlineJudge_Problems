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
#define max 1002+8

void input();
void BFS(int index1, int index2);
bool isok(int m, int n);

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
bool graph[ max ][ max ];
int row, col, trow, cost[ max ][ max ];

int main()
{
    input();

    return 0;
}
void input()
{
    int i, j, from, to, tot, S1, S2, E1, E2;
    while(sf("%d %d", &row, &col) && row && col)
    {
        fo(i, row) fo(j, col) graph[ i ][ j ] = false;
        sf("%d", &trow);
        while(trow--)
        {
            sf("%d %d", &from, &tot);
            while(tot--)
            {
                sf("%d", &to);
                graph[ from ][ to ] = true;
            }
        }
        sf("%d %d", &S1, &S2);
        sf("%d %d", &E1, &E2);
        if(S1 == E1 && S2 == E2) puts("0");
        else
        {
            BFS(S1, S2);
            pf("%d\n", cost[ E1 ][ E2 ]);
        }
    }
}
void BFS(int index1, int index2)
{
    int i, tmp1, tmp2;
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
                if(!graph[ index1 ][ index2 ])
                {
                    graph[ index1 ][ index2 ] = true;
                    cost[ index1 ][ index2 ] = cost[ tmp1 ][ tmp2 ] + 1;
                    Q.push( index1 ); Q.push( index2 );
                }
        }
    }
}
bool isok(int m, int n)
{
    if(m == row || n == col || m < 0 || n < 0) return false;
    return true;
}

