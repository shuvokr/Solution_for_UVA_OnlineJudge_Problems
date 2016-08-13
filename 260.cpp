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
bool BFS(int row, int col);

char in[ 202 ][ 202];
int diraction1[] = {-1, -1, 0, 0, 1, 1};
int diraction2[] = {-1, 0, -1, 1, 0, 1};
int n;

int main()
{
    input();

    return 0;
}
void input()
{
    int kag = 0, i, j; bool cheak;
    while(sf("%d", &n) != EOF)
    {
        if(n == 0) break;
        getchar(); mem( in );
        fo(i, n) gets(in[ i ]); cheak = false;
        fo(i, n)
        {
            if(in[ i ][ 0 ] == 'w')
                cheak = BFS(i, 0);
            if(cheak) break;
        }
        if(cheak) pf("%d W\n", ++kag);
        else pf("%d B\n", ++kag);
    }
}
bool BFS(int row, int col)
{
    int i, j, tmp1, tmp2;
    bool mark[ 202 ][ 202 ];
    fo(i, 201) fo(j, 201) mark[ i ][ j ] = true;
    queue < int > Q;
    Q.push( row ); Q.push( col );
    mark[ row ][ col ] = false;
    while(!Q.empty())
    {
        tmp1 = Q.front(); Q.pop();
        tmp2 = Q.front(); Q.pop();
        fo(i, 6)
        {
            row = tmp1 - diraction1[ i ];
            col = tmp2 - diraction2[ i ];
            if(mark[ row ][ col ] && in[ row ][ col ] == 'w')
            {
                mark[ row ][ col ] = false;
                if(col == n - 1) return true;
                Q.push( row ); Q.push( col );
            }
        }
    }
    return false;
}
