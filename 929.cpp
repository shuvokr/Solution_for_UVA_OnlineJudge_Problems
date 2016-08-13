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
typedef pair<int, pi> pii;
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

struct data
{
    int u, v, cost;
    data(int a, int b, int co) : u( a ), v( b ), cost( co ) {}
    bool operator<(const struct data& other) const
    {
        return cost > other.cost;
    }
};

void dijkstra(int a, int b);
int cost[ 1002 ][ 1002 ], row, col, gcost[ 1002 ][ 1002 ];

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
    int T;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d %d", &row, &col);
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++) scanf("%d", &gcost[ i ][ j ]), cost[ i ][ j ] = 1 << 30;
        cost[ 0 ][ 0 ] = gcost[ 0 ][ 0 ];
        dijkstra(0, 0);
        printf("%d\n", cost[row - 1][col - 1]);
    }
}
void dijkstra(int a, int b)
{
    priority_queue< data > Q;
    Q.push(data(0, 0, gcost[ 0 ][ 0 ]));
    while(!Q.empty())
    {
        data tok = Q.top(); Q.pop();
        a = tok.u; b = tok.v;
        if(cost[ a ][ b ] == tok.cost)
        {
            for(int i = 0; i < 4; i++)
            {
                int x = a + diraction1[ i ];
                int y = b + diraction2[ i ];
                if(x >= 0 && x < row && y >=0 && y < col)
                {
                    if(cost[ x ][ y ] > cost[ a ][ b ] + gcost[ x ][ y ])
                    {
                        cost[ x ][ y ] = cost[ a ][ b ] + gcost[ x ][ y ];
                        Q.push(data(x, y, cost[ x ][ y ]));
                    }
                }
            }
        }
    }
}


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
typedef pair<int, pi> pii;
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

void dijkstra(int a, int b);
int cost[ 1002 ][ 1002 ], row, col, gcost[ 1002 ][ 1002 ];

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
    int T;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d %d", &row, &col);
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++) scanf("%d", &gcost[ i ][ j ]), cost[ i ][ j ] = 1 << 30;
        cost[ 0 ][ 0 ] = gcost[ 0 ][ 0 ];
        dijkstra(0, 0);
        printf("%d\n", cost[row - 1][col - 1]);
    }
}
void dijkstra(int a, int b)
{
    priority_queue<pii, vector<pii>, greater<pii> > Q;
    Q.push(make_pair(gcost[ 0 ][ 0 ], pi(0, 0)));
    while(!Q.empty())
    {
        pii tok = Q.top(); Q.pop();
        pi pir = tok.second;
        a = pir.first; b = pir.second;
        if(cost[ a ][ b ] == tok.first)
        {
            for(int i = 0; i < 4; i++)
            {
                int x = a + diraction1[ i ];
                int y = b + diraction2[ i ];
                if(x >= 0 && x < row && y >=0 && y < col)
                {
                    if(cost[ x ][ y ] > cost[ a ][ b ] + gcost[ x ][ y ])
                    {
                        cost[ x ][ y ] = cost[ a ][ b ] + gcost[ x ][ y ];
                        Q.push(make_pair(cost[ x ][ y ], pi(x, y)));
                    }
                }
            }
        }
    }
}
