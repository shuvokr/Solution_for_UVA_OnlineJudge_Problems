/************************************

    Shuvo
    Problem name :
    Problem ID   :
    Problem algo :
    Note         :

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

void BFS(int u);
void print(int u);

vector <vi> graph;
map <string, int> numbering;
map <int, string> name;
int route, point, a, b, par[ 10010 ];
char start[ 4 ], end[ 4 ];
bool mark[ 10010 ], xk;

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
    bool space = false;
    while(~scanf("%d", &route))
    {
        if(space) puts(""); else space = true;
        point = 1; numbering.clear(); name.clear();
        graph.assign(route + route + 2, vi());
        for(int i = 0; i < route; i++)
        {
            scanf("%s %s", start, end);
            if(!numbering[ start ]) name[ point ] = start, numbering[ start ] = point++;
            if(!numbering[ end ]) name[ point ] = end, numbering[ end ] = point++;
            int u = numbering[ start ], v = numbering[ end ];
            graph[ u ].pb( v ); graph[ v ].pb( u );
        }
        scanf("%s %s", start, end); a = numbering[ start ]; b = numbering[ end ];
        memset(mark, true, point + 2);
        xk = false; BFS( a );
        if( xk ) print( b );
        else puts("No route");
    }
}
void BFS(int u)
{
    mark[ u ] = false;
    queue <int> Q;
    Q.push( u );
    par[ u ] = -1;
    while( !Q.empty() )
    {
        u = Q.front(); Q.pop();
        for(int i = 0, len = graph[ u ].size(); i < len; i++)
        {
            int v = graph[ u ][ i ];
            if(mark[ v ])
            {
                par[ v ] = u;
                mark[ v ] = false;
                Q.push( v );
            }
            if(v == b)
            {
                i = len; xk = true;
                while( !Q.empty() ) Q.pop();
            }
        }
    }
}
void print(int u)
{
    if(par[ u ] == -1) return;
    print(par[ u ]);
    cout << name[ par[ u ] ] << " " << name[ u ] << endl;
}
