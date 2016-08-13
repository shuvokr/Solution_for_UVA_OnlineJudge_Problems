
/************************************

    Shuvo
    Problem name : Trip Routing
    Problem ID   : 186
    Problem algo : Dijkstra + string procage (Graph)
    Note         : So Intersting =D

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

void Dijkstra(int s, int e);
void print_path(int s, int e);

vector <vpi> graph;
map <string, int> mp;
map <int, string> name;
map <pi, string> route;
map <pi, int> ct;
char in[ 85 ], *tok;
int u, v, par[ 105 ], cost[ 105 ], tot;

struct data
{
    int nod, time;
    data() {}
    data(int a, int b):nod(a), time(b) {}
    bool operator<(const data &x) const
    {
        return time < x.time;
    }
};

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
    int n = 1, tmp;
    graph.assign(105, vpi());
    mp.clear(); ct.clear();
    while(gets( in ))
    {
        if(in[ 0 ] == NULL) break;
        tok = strtok(in, ",");
        if(mp[ tok ] == 0) u = n, name[ n ] = tok, mp[ tok ] = n++;
        else u = mp[ tok ];
        tok = strtok(NULL, ",");
        if(mp[ tok ] == 0) v = n, name[ n ] = tok, mp[ tok ] = n++;
        else v = mp[ tok ];
        tok = strtok(NULL, ",");
        string sk = tok;
        tok = strtok(NULL, ", ");
        tmp = atoi( tok );
        int tm = ct[pi(u, v)];
        if(tm == 0 || tmp < tm)
        {
            route[pi(u, v)] = sk;
            route[pi(v, u)] = sk;
            ct[pi(u, v)] = tmp;
            ct[pi(v, u)] = tmp;
        }
        graph[ u ].pb(pi(v, tmp));
        graph[ v ].pb(pi(u, tmp));
    }

    while(gets( in ))
    {
        tok = strtok(in, ",");
        u = mp[ tok ];
        tok = strtok(NULL, ",");
        v = mp[ tok ];
        for(int i = 1; i < 101; i++) cost[ i ] = INF, par[ i ] = 0;
        Dijkstra(u, v);
        tot = 0;
        puts(""); puts("");
        puts("From                 To                   Route      Miles");
        puts("-------------------- -------------------- ---------- -----");
        print_path(u, v);
        puts("                                                     -----");
        printf("                                          Total      ");
        printf("%5d\n", tot);
    }
}
void Dijkstra(int s, int e)
{
    priority_queue <data> pq;
    cost[ s ] = 0;
    data tmp;
    int nd, tm;
    pq.push(data(s, 0));
    while(!pq.empty())
    {
        tmp = pq.top(); pq.pop();
        nd = tmp.nod; tm = tmp.time;
        if(cost[ nd ] == tm)
        {
            for(int i = 0; i < graph[ nd ].size(); i++)
            {
                pi pr = graph[ nd ][ i ];
                if(cost[ nd ] + pr.second < cost[ pr.first ])
                {
                    par[ pr.first ] = nd;
                    cost[ pr.first ] = cost[ nd ] + pr.second;
                    pq.push(data(pr.first, cost[ pr.first ]));
                }
            }
        }
    }
}
void print_path(int s, int e)
{
    if(par[ e ] != s) print_path(s, par[ e ]);
    u = par[ e ];
    cout << name [ u ];
    for(int i = name[ u ].size(); i < 21; i++) putchar(' ');
    cout << name[ e ];
    for(int i = name[ e ].size(); i < 21; i++) putchar(' ');
    string str = route[ pi(u, e) ];
    cout << str; for(int i = str.size(); i < 11; i++) putchar(' ');
    u = ct[ pi(u, e) ]; printf("%5d\n", u);
    tot += u;
}
