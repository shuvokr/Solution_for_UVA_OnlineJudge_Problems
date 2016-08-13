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

/**************************Templet end*********************************/

struct MST
{
    int u, v, cost;
}edge[ 6247505 ];

void input();
void solve();
void reset();
void BFS(int n, int m);
bool isok(int i, int j);
void make_edge(int n, int m);
void solve_MST();
int Union_find(int n);
bool cmp(const MST &x, const MST &y)
{
    return (x.cost < y.cost);
}

char grid[ 51 ][ 55 ];
int node_name[ 52 ][ 52 ], r, c, T, cost[ 52 ][ 52 ], ind, str, ed, par[ 2510 ], res;

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
    scanf("%d", &T);
    while( T-- )
    {
        str = 0;
        scanf("%d %d", &c, &r); getchar();
        for(int i = 0; i < r; i++)
        {
            gets( grid[ i ] );
            for(int j = 0; j < c; j++) if(grid[ i ][ j ] == 'A' || grid[ i ][ j ] == 'S') node_name[ i ][ j ] = ++str;
        }
        solve(); printf("%d\n", res);
    }
}
void solve()
{
    ind = 1; ed = 0;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if(grid[ i ][ j ] == 'A' || grid[ i ][ j ] == 'S')
            {
                reset(); cost[ i ][ j ] = 0;
                BFS(i, j); str = 0; make_edge(i, j); ind++;
            }

    solve_MST();
}
void reset()
{
    for(int i = 0; i < 51; i++)
        for(int j = 0; j < 51; j++) cost[ i ][ j ] = 1 << 30;
}
void BFS(int n, int m)
{
    cost[ n ][ m ] = 0;
    queue <int> Q;
    Q.push( n ); Q.push( m );
    while(!Q.empty())
    {
        n = Q.front(); Q.pop();
        m = Q.front(); Q.pop();
        for(int k = 0, a, b; k < 4; k++)
        {
            a = n + diraction1[ k ];
            b = m + diraction2[ k ];
            if(isok(a, b))
            {
                if(cost[ a ][ b ] == 1 << 30)
                {
                    cost[ a ][ b ] = cost[ n ][ m ] + 1;
                    Q.push( a ); Q.push( b );
                }
            }
        }
    }
}
bool isok(int i, int j)
{
    if(i > -1 && i < r && j > -1 && j < c && grid[ i ][ j ] != '#') return true;
    return false;
}
void make_edge(int n, int m)
{
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
        {
            if(grid[ i ][ j ] == 'A' || grid[ i ][ j ] == 'S')
            {
                str += str + 1 == ind ? 2 : 1;
                if(i != n || j != m)
                {
                    edge[ ed ].u = node_name[ n ][ m ];
                    edge[ ed ].v = node_name[ i ][ j ]; edge[ ed++ ].cost = cost[ i ][ j ];
                }
            }
        }
}
void solve_MST()
{
    res = 0;
    sort(edge, edge + ed, cmp);
    for(int i = 1; i < ind; i++) par[ i ] = i;
    for(int i = 0, a, b; i < ed; i++)
    {
        a = Union_find( edge[ i ].u ); b = Union_find( edge[ i ].v );
        if(a != b)
        {
            par[ a ] = b;
            res += edge[ i ].cost;
        }
    }
}
int Union_find(int n)
{
    if(n == par[ n ]) return n;
    else return par[ n ] = Union_find( par[ n ] );
}
