/************************************

    Shuvo
    Problem name : Domino efect
    Problem ID   : 318
    Problem algo : graph traverse
    Note         : code defivulty - Midium

*************************************/

/**********************************Templet start***********************************/
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
#include <set>
#include <algorithm>

using namespace std;

#define phl puts("Hello")
#define sf scanf
#define pf printf
#define fo(i, n) for(i = 0; i < n; i++)
#define of(i, n) for(i = n - 1; i >= 0; i--)
#define CLR(n, v) memset(n, v, sizeof( n ))
#define CLRL(n, v, len) memset(n, v, len)
#define INF 1 << 30
#define pb push_back
#define maxn 200+2
#define lim(v) v.begin(), v.end()
#define sz(v) ((int)v,size())
#define equals(a, b) (fabs(a-b)<eps)

#define white 0
#define black 1

const double PI = 2 * acos ( 0.0 );
const double eps = 1e-9;

typedef long long lld;
typedef unsigned long long llu;
typedef pair<int, int> pi;
typedef  vector<int> vi;
typedef vector<pi> vpi;

template <class T> T jog(T a, T b) { return a + b; }
template <class T> T bog(T a, T b) { return a - b; }
template <class T> T gon(T a, T b) { return a * b; }
template <class T> T sq(T x) {return x * x;}
template <class T> T gcd( T a, T b ) { while ( b ) { a = a % b; swap ( a, b ); } return a;}
template <class T> T lcm ( T a, T b ) { return ( a / gcd ( a, b ) ) * b; }
template <class T> T power ( T a, T p ) { int res = 1, x = a; while ( p ) { if ( p & 1 ) res = res * x; x = x * x; p >>= 1; } return res;}
template <class T> T cordinatlenth(T a, T b, T c, T d) { return sqrt( sq(a - c) + sq(b - d) ); }
lld bigmod ( lld a, lld p, lld mod )
{
    lld res = 1, x = a;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % mod;
        x = ( x * x ) % mod;
        p >>= 1;
    }
    return res;
}


int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

void input();

/**************************Templet end*********************************/

void dfs(int u);

bool vis[ 505 ];
int dist[ 505 ], node, edge, graph[ 505 ][ 505 ], maxd;

int main()
{
    //#ifdef localhost
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    //#endif
    input();

    return 0;
}
void input()
{
    int i, u, v, cost, kag = 0;
    while(~scanf("%d %d", &node, &edge) && (node || edge))
    {
        for(i = 1; i <= node; i++)
            for(int j = 1; j <= node; j++) graph[ i ][ j ] = -1;
        printf("System #%d\n", ++kag);
        if(!edge)
        {
            puts("The last domino falls after 0.0 seconds, at key domino 1.");
            puts("");
            continue;
        }
        for(i = 0; i < edge; i++)
        {
            scanf("%d %d", &u, &v);
            scanf("%d", &graph[ u ][ v ]);
            graph[ v ][ u ] = graph[ u ][ v ];
        }
        dist[ 1 ] = 0;
        for(i = 2; i <= node; i++) dist[ i ] = INF;
        dfs( 1 );
        long long res = 0;
        int resx=1, resy=1;

        for (int x = 1; x <= node; x++)
                if (2*dist[x] > res) { res = 2*dist[x]; resx = resy = x; }

        for (int x = 1; x <= node; x++)
            for (int y = x+1; y <= node; y++)
            {
                    if (graph[x][y] == INF) continue;

                    long long l = graph[x][y];
                    if (dist[x] + l > dist[y] && dist[y] + l > dist[x])
                    {
                        long long t = dist[x] + dist[y] + l;
                        if (t > res)
                        {
                                res = t;
                                resx = x;
                                resy = y;
                        }
                    }
            }
        printf("The last domino falls after %lld.%d seconds, ", res/2, (int)((res%2)*5));

        if (resx == resy)
            printf("at key domino %d.\n\n", resx);
        else
            printf("between key dominoes %d and %d.\n\n", resx, resy);
    }
}
void dfs(int u)
{
    for(int v = 1; v <= node; v++)
    {
        if(graph[ u ][ v ] != -1)
        {
            if(dist[ v ] > dist[ u ] + graph[ u ][ v ])
                dist[ v ] = dist[ u ] + graph[ u ][ v ], dfs( v );
        }
    }
}
