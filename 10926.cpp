/************************************

    Shuvo
    Problem name :  How Many Dependencies?
    Problem ID   :  10926
    Problem algo :  Graph( DFS )
    Note         :  Empty

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

template <class T> T sq(T x) {return x * x;}
template <class T> T gcd( T a, T b ) { while ( b ) { a = a % b; swap ( a, b ); } return a;}
template <class T> T lcm ( T a, T b ) { return ( a / gcd ( a, b ) ) * b; }
template <class T> T power ( T a, T p ) { int res = 1, x = a; while ( p ) { if ( p & 1 ) res = res * x; x = x * x; p >>= 1; } return res;}
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

void print();
void input();

/**************************Templet end*********************************/

void DFS(int u);

vector <vi> graph;
bool vis[ 105 ];
int cou, res, n;

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
    int i, j, u, v, tmp;
    while(~scanf("%d", &n) && n)
    {
        graph.assign(n + 5, vi());
        fo(i, n)
        {
            u = i + 1; vis[ u ] = true;
            scanf("%d", &tmp);
            fo(j, tmp)
            {
                scanf("%d", &v);
                graph[ u ].push_back( v );
            }
        }
        res = 0;
        //print();
        fo(i, n)
        {
            u = i + 1;
            cou = 0;
            CLR(vis, true);
            vis[ u ] = false;
            DFS( u );
            if(res < cou)
            {
                tmp = u;
                res = cou;
            }
        }
        printf("%d\n", tmp);
    }
}
void DFS(int u)
{
    int i, v, len = graph[ u ].size();
    bool ck = true;
    fo(i, len)
    {
        v = graph[ u ][ i ];
        if(vis[ v ])
        {
            ck = false;
            vis[ v ] = false;
            cou++; DFS( v );
        }
    }
}
void print()
{
    int i, len;
    fo(i, n)
    {
        len = graph[i + 1].size();
        printf("%d ", len);
    }
    puts("");
}
