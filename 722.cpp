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

int BFS(int x, int y);
bool isvalid(int x, int y);

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};

char graph[ 100 ][ 100 ];
int row, col;

int main()
{
    int i, j, T, r, c, len, res, a, b;
    bool ck = false;
    scanf("%d", &T);
    while(T--)
    {
        if( ck ) puts("");
        else ck = true;
        scanf("%d %d", &r, &c); r--; c--;
        getchar();
        row = 0; col = -1;
        while(gets( graph[ row ]))
        {
            if(graph[ row ][ 0 ] == 0) break;
            len = strlen( graph[ row ] );
            col = max(col, len);
            row++;
        }
        res = 0;
        if(graph[ r ][ c ] == '1')
        {
            for(i = 0; i < 2; i++)
            {
                a = r + diraction1[ i ];
                b = c + diraction2[ i ];
                if(graph[ a ][ b ] == '0') res = max(res, BFS(a, b));
            }
            if(res < 2) res++;
        }
        else {res = BFS(r, c); if(res == 0) res = 1;}
        printf("%d\n", res);
    }
    return 0;
}
int BFS(int x, int y)
{
    int i, j, tmp1, tmp2, cou = 0;
    queue <int> Q;
    Q.push( x ); Q.push( y );
    while(!Q.empty())
    {
        tmp1 = Q.front(); Q.pop();
        tmp2 = Q.front(); Q.pop();
        for(i = 0; i < 4; i++)
        {
            x = tmp1 + diraction1[ i ];
            y = tmp2 + diraction2[ i ];
            if( isvalid(x, y) )
            if(graph[ x ][ y ] == '0')
            {
                graph[ x ][ y ] = '1';
                cou++;
                Q.push( x ); Q.push( y );
            }
        }
    }
    return cou;
}
bool isvalid(int x, int y)
{
    if(x == row || x < 0 || y == col || y < 0) return false;
    return true;
}
