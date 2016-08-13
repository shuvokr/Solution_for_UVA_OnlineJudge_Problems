/*
        Shuvo
        Problem algo: Flood fill
        Problem ID: 784
        Problem name: Maze Exploration
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

#define white 0
#define black 1

typedef vector <int> vi;

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

//Templet end
void input();
void flood_fill(int x, int y);
bool isvalid(int x, int y);

int row, col;
char graph[ 32 ][ 82 ];

int main()
{
    input();

    return 0;
}
void input()
{
    int i, j, T, len, cou;
    sf("%d", &T); getchar();
    while(T--)
    {
        col = i = 0;
        while( true )
        {
            gets( graph[ i ] );
            len = strlen( graph[ i ] );
            col = max(col, len);
            j = 0;
            while(graph[ i ][ j ] == '_')
            {
                j++;
            }
            i++;
            if(len == j) break;
        }
        row = i;
        //pf("%d %d\n", row, col);

        for(i = 0; i < row; i++)
        {
            for(j = 0; j < col; j++)
            {
                if(graph[ i ][ j ] == '*')
                {
                    //pf("%c", graph[ i ][ j ]);
                    flood_fill(i, j);
                    i = row; j = col;
                }
            }
        }

        //puts("Start");
        fo(j, row) puts( graph[ j ] );
        //puts("End");
    }
}
void flood_fill(int x, int y)
{
    int i, j, tmp1, tmp2;
    queue <int> Q;
    graph[ x ][ y ] = '#';
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
                graph[ x ][ y ] = '#';
                Q.push( x ); Q.push( y );
            }
        }
    }
}
bool isvalid(int x, int y)
{
    if(graph[ x ][ y ] == 'X' || graph[ x ][ y ] == '#') return false;
    return true;
}
