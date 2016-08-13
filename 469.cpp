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

void input();
void BFS(int inedx1, int index2);
bool isvalid(int x, int y);

int diraction1[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int diraction2[] = {-1, 0, 1, -1, 1, -1, 0, 1};
char graph[ 101 ][ 101 ];
int row, col;

int main()
{
    input();

    return 0;
}
void input()
{
    int T, i, j, tmp, r, c, max;
    bool space = false;
    char in[ 101 ];
    sf("%d", &T); getchar(); getchar();
    while(T--)
    {
        if( space ) puts("");
        space = true;
        row = 0; mem( graph );
        col = 0;
        while(gets( in ) != NULL)
        {
            if(in[ 0 ] == 0) break;
            if(in[ 0 ] == 'L' || in[ 0 ] == 'W')
            {
                strcpy(graph[ row++ ], in);
                max = strlen( in );
                if(col < max) col = max;
            }
            else
            {
                sscanf(in, "%d %d", &r, &c);
                r--; c--;
                if(graph[ r ][ c ] == 'L') puts("0");
                else BFS(r, c);
            }
        }
    }
}

void BFS(int index1, int index2)
{
    int i, j, tmp1, tmp2, cou = 0;
    bool mark[ 101 ][ 101 ];
    fo(i, 101)
        fo(j, 101)
            mark[ i ][ j ] = true;
    queue < int > Q;
    Q.push( index1 ); Q.push( index2 );
    while(!Q.empty())
    {
        tmp1 = Q.front(); Q.pop(); tmp2 = Q.front(); Q.pop();
        fo(i, 8)
        {
            index1 = tmp1 + diraction1[ i ];
            index2 = tmp2 + diraction2[ i ];
            if( isvalid(index1, index2) )
            if(graph[ index1 ][ index2 ] == 'W' && mark[ index1 ][ index2 ])
            {
                cou++;
                mark[ index1 ][ index2 ] = false;
                Q.push( index1 ); Q.push( index2 );
            }
        }
    }
    if(cou == 0) puts("1");
    else pf("%d\n", cou);
}
bool isvalid(int x, int y)
{
    if(x == row || x < 0 || y == col || y < 0) return false;
    return true;
}

