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
template <class T> T gcd( T a, T b ) { return b == 0 ? a : gcd(b, a % b); }
template <class T> T lcm ( T a, T b ) { return ( a / gcd ( a, b ) ) * b; }
template <class T> T power ( T a, T p ) { int res = 1, x = a; while ( p ) { if ( p & 1 ) res = res * x; x = x * x; p >>= 1; } return res;}
template <class T> T cordinatlenth(T a, T b, T c, T d) { return sqrt( sq(a - c) + sq(b - d) ); }
template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
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
//const int pr = 500001;
//int prime[ 41539 ], ind;
//bool mark[ pr ];
//void primelist()
//{
//    for(int i = 4; i < pr; i += 2) mark[ i ] = false;
//    for(int i = 3; i < pr; i += 2) mark[ i ] = true; mark[ 2 ] = true;
//    for(int i = 3, sq = sqrt( pr ); i < sq; i += 2)
//        if(mark[ i ])
//            for(int j = i * i; j < pr; j += i + i) mark[ j ] = false;
//    prime[ 0 ] = 2; ind = 1;
//    for(int i = 3; i < pr; i += 2)
//        if(mark[ i ]) ind++; printf("%d\n", ind);
//}

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

void input();

/**************************Templet end*********************************/

void DFS(int s); // for tarzan
void second_DFS(int s); // for tarzan

vector <vi> graph;
vector <vi> rgraph;
vector <int> save_starting_node;
bool mark[ 1010 ];
int node, edge;
map <string, int> si;
char a[ 100 ], b[ 100 ];

int main()
{
    //#ifdef monkey
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    //#endif
    input();

    return 0;
}
void input()
{
    while(sf("%d %d", &node, &edge) && node)
    {
        graph.assign(node + 5, vi());
        rgraph.assign(node + 5, vi());
        si.clear();
        getchar();
        for(int i = 0; i < node; i++)
        {
            gets( a );
            si[ a ] = i + 1;
        }
        for(int i = 0; i < edge; i++)
        {
            gets( a ); gets( b );
            int u = si[ a ], v = si[ b ];
            graph[ u ].pb( v );
            rgraph[ v ].pb( u );
        }
        int res = 0;
        CLR(mark, true);
        for(int i = 0; i < node; i++)
        {
            if(mark[i + 1])
            {
                mark[ i + 1 ] = false;
                DFS(i + 1);
            }
        }
        int len = save_starting_node.size();
        for(int i = len - 1; i > -1; i--)
        {
            if( !mark[ save_starting_node[ i ] ] )
            {
                mark[ save_starting_node[ i ] ] = true;
                second_DFS(save_starting_node[ i ]); res++;
            }
        }
        printf("%d\n", res);
    }
}
void DFS(int s)
{
    for(int i = 0; i < graph[ s ].size(); i++)
    {
        int e = graph[ s ][ i ];
        if(mark[ e ])
        {
            mark[ e ] = false;
            DFS( e );
        }
    }
    save_starting_node.pb( s );
}
void second_DFS(int s)
{
    for(int i = 0; i < rgraph[ s ].size(); i++)
    {
        int e = rgraph[ s ][ i ];
        if( !mark[ e ] )
        {
            mark[ e ] = true;
            second_DFS( e );
        }
    }
}
