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
template <class T> T gcd( T a, T b ) { return b == 0 ? a : gcd(b, a % b); }
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

void DFS(int row, int col);

int r, c, cost[ 110 ][ 110 ], graph[ 110 ][ 110 ], maxres;

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
    int T, s, e, val;
    string name;
    scanf("%d", &T);
    while(T--)
    {
        cin >> name >> r >> c;
        val = -1;
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                scanf("%d", &graph[ i ][ j ]);

        CLR(cost, -1); maxres = -1;
        bool mark = true;
        while( true )
        {
            mark = true; val = -1;
            for(int i = 0; i < r; i++)
                for(int j = 0; j < c; j++)
                {
                    if(cost[ i ][ j ] == -1 && val < graph[ i ][ j ])
                    {
                        mark = false;
                        s = i; e = j;
                        val = graph[ i ][ j ];
                    }
                }
            if(mark) break;
            else
            {
                cost[ s ][ e ] = 0;
                DFS(s, e);
            }
        }
        maxres++;
        cout << name << ": " << maxres << endl;
    }
}
void DFS(int row, int col)
{
    for(int i = 0; i < 4; i++)
    {
        int u = row + diraction1[ i ];
        int v = col + diraction2[ i ];
        //pf("  %d %d\n", u, v);
        if(u >= 0 && u < r && v >= 0 && v < c)
        if(graph[ u ][ v ] < graph[ row ][ col ])
        {
            if(cost[ u ][ v ] <= cost[ row ][ col ])
            {
                cost[ u ][ v ] = cost[ row ][ col ] + 1;
                maxres = maxres < cost[ u ][ v ] ? cost[ u ][ v ] : maxres;
                DFS(u, v);
            }
        }
    }
}
/*
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
template <class T> T gcd( T a, T b ) { return b == 0 ? a : gcd(b, a % b); }
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

void DFS(int row, int col);

int r, c, cost[ 110 ][ 110 ], graph[ 110 ][ 110 ], maxres;

int main()
{
    //#ifdef localhost
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    //#endif
    input();

    return 0;
}
void input()
{
    int T, s, e, val;
    string name;
    scanf("%d", &T);
    while(T--)
    {
        cin >> name >> r >> c;
        val = -1;
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                scanf("%d", &graph[ i ][ j ]);

        maxres = -1;

            for(int i = 0; i < r; i++)
                for(int j = 0; j < c; j++)
                {
                    CLR(cost, -1);
                    cost[ i ][ j ] = 0;
                    DFS(i, j);
                }
        maxres++;
        cout << name << ": " << maxres << endl;
    }
}
void DFS(int row, int col)
{
    for(int i = 0; i < 4; i++)
    {
        int u = row + diraction1[ i ];
        int v = col + diraction2[ i ];
        if(u >= 0 && u < r && v >= 0 && v < c)
        if(graph[ u ][ v ] < graph[ row ][ col ])
        {
            if(cost[ u ][ v ] < cost[ row ][ col ])
            {
                cost[ u ][ v ] = cost[ row ][ col ] + 1;
                maxres = maxres < cost[ u ][ v ] ? cost[ u ][ v ] : maxres;
                DFS(u, v);
            }
        }
    }
}
*/
