/*
        Shuvo
        Problem algo: BFS( 3D )
        Problem ID: 532
        Problem name:  Dungeon Master
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
#define maxn 30+1

#define white 0
#define black 1

typedef vector <int> vi;

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

int positionsX[6]= {0,0,0,-1,0,1};
int positionsY[6]= {0,0,-1,0,1,0};
int positionsZ[6]= {1,-1,0,0,0,0};

//Templet end
void input();
void print();
int BFS(int x, int y, int z);
bool isvalid(int x, int y, int z);

char graph[ maxn ][ maxn ][ maxn ];
int a, b, c, cost[ maxn ][ maxn ][ maxn ];

int main()
{
    input();

    return 0;
}
void input()
{
    int i, j, k;
    while(sf("%d %d %d", &a, &b, &c) != EOF)
    {
        if(a + b + c == 0) break;
        getchar();
        fo(i, a)
        {
            fo(j, b)
            {
                gets( graph[ i ][ j ] );
            }
            getchar();
        }
        print();
    }
}
void print()
{
    int res;
    for(int i = 0; i < a; i++)
    {
        for(int j = 0; j < b; j++)
        {
            for(int k = 0; k < c; k++)
            {
                if(graph[ i ][ j ][ k ] == 'S')
                {
                    res = BFS(i, j, k);
                    if(res == 1) pf("Escaped in 1 minute.\n");
                    else if( res ) pf("Escaped in %d minute(s).\n", res);
                    else puts("Trapped!");
                    i = a + 1;
                    j = b + 1;
                    k = c + 1;
                }
            }
        }
    }
}
int BFS(int x, int y, int z)
{
    int i, j, k, s, tmp1, tmp2, tmp3;
    queue <int> Q;
    Q.push( x ); Q.push( y ); Q.push( z );
    cost[ x ][ y ][ z ] = 0;
    graph[ x ][ y ][ z ] = '#';
    while(!Q.empty())
    {
        tmp1 = Q.front(); Q.pop();
        tmp2 = Q.front(); Q.pop();
        tmp3 = Q.front(); Q.pop();
        fo(s, 6)
        {
            x = tmp1 + positionsX[ s ];
            y = tmp2 + positionsY[ s ];
            z = tmp3 + positionsZ[ s ];
            if(isvalid(x, y, z))
            {
                cost[ x ][ y ][ z ] = cost[ tmp1 ][ tmp2 ][ tmp3 ] + 1;
                if(graph[ x ][ y ][ z ] == 'E') return cost[ x ][ y ][ z ];
                //pf("%c", graph[ x ][ y ][ z ]);
                graph[ x ][ y ][ z ] = '#';
                Q.push( x ); Q.push( y ); Q.push( z );
            }
        }
    }
    return 0;
}
bool isvalid(int x, int y, int z)
{
    if(x == a || x < 0 || y == b || y < 0 || z == c || z < 0 || graph[ x ][ y ][ z ] == '#') return false;
    return true;
}

