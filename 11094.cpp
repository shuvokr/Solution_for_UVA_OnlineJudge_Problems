/*
        Shuvo
        Problem info: uva 11094 - Continents
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
#define INF -1

void input();
void DFS(int index1, int index2);

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

char graph[ 21 ][ 21 ], ch;
int row, col, cost[ 21 ][ 21 ], tempo;
bool mark[ 21 ][ 21 ];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    input();

    return 0;
}
void input()
{
    int i, j, pos1, pos2, res;
    while(sf("%d %d", &row, &col) != EOF)
    {
        getchar();
        fo(i, row) gets( graph[ i ] );
        sf("%d %d", &pos1, &pos2);
        ch = graph[ pos1 ][ pos2 ];
        res = tempo = 0;
        DFS(pos1, pos2);
        fo(i, row)
        {
            fo(j, col)
            {
                if(graph[ i ][ j ] == ch)
                {
                    tempo = 0;
                    DFS(i, j);
                    res = res < tempo ? tempo : res;
                }
            }
        }
        pf("%d\n", res);
    }
}
void DFS(int index1, int index2)
{
    int a, b, i, j;
    tempo++;
    graph[ index1 ][ index2 ] = '.';
    for(i = 0; i < 4; i++)
    {
        a = diraction1[ i ] + index1;
        b = diraction2[ i ] + index2;
        b %= col;
        b = b < 0 ? col - 1 : b;
        if(a >= 0 && a < row && graph[ a ][ b ] == ch)
            DFS(a, b);
    }
}
