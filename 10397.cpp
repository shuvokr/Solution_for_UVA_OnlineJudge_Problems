
/************************************

    Shuvo
    Problem name : Connect the Campus
    Problem ID   : 10397
    Problem algo : MST
    Note         : Empty

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

void input();

/**************************Templet end*********************************/

int find(int dex);

struct data
{
    int x, y;
};

struct EDGE
{
    int u, v;
    double val;
    bool operator < (const EDGE &s) const
    {
        return val < s.val;
    }
};

int buldig, par[ 755 ];
data in[ 755 ];
EDGE edge[ 281630 ];

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
    while(~scanf("%d", &buldig))
    {
        for(int i = 0; i < buldig; i++)
        {
            scanf("%d %d", &in[ i ].x, &in[ i ].y );
            par[ i ] = i;
        }
        int m;
        scanf("%d", &m);
        for(int i = 0; i < m; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            a--; b--;
            a = find( a );
            b = find( b );
            if(a != b) par[ a ] = b;
        }
        int cou_edge = 0;
        for(int i = 0; i < buldig; i++)
        {
            int a = in[i].x, b = in[i].y;
            for(int j = i + 1; j < buldig; j++)
            {
                if(find(i) != find(j))
                {
                    int c = in[j].x, d = in[j].y;
                    double vl = sqrt( sq(a-c) + sq(b-d) );
                    edge[cou_edge].val = vl;
                    edge[cou_edge].u = i;
                    edge[cou_edge++].v = j;
                }
            }
        }
        sort(edge, edge + cou_edge);
        double result = 0.0;
        for(int i = 0; i < cou_edge; i++)
        {
            int p = find( edge[i].u );
            int q = find( edge[i].v );
            if(p != q)
            {
                par[ p ] = q;
                result += edge[i].val;
            }
        }
        printf("%.2lf\n", result);
    }
}
int find(int dex)
{
    if(par[ dex ] == dex) return dex;
    else return par[ dex ] = find( par[ dex ] );
}
