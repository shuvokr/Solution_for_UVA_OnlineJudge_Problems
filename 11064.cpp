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
const int MAX = 46341;

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

void calculateprime();
int phi(int n);
int div(int n);

int prlim;
bool mark[ 1000010 ];
vector <int> prime;

int main()
{
    calculateprime();
    //#ifdef localhost
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    //#endif
    input();

    return 0;
}
void input()
{
    int n;
    while(~scanf("%d", &n))
    {
        if(n == 1)
        {
            puts("0");
            continue;
        }
        printf("%d\n", n - phi(n) - div(n));
    }
}
void calculateprime()
{
    mark[ 0 ] = false; mark[ 1 ] = mark[ 2 ] = true;
    for(int i = 4; i < MAX; i += 2) mark[ i ] = false;
    for(int i = 3; i < MAX; i += 2) mark[ i ] = true;
    int srt = sqrt( MAX ) + 1;
    for(int i = 3; i < srt; i += 2)
        if(mark[ i ])
            for(int j = i << 1; j < MAX; j += i) mark[ j ] = false;
    prime.pb( 2 );
    for(int i = 3; i < MAX; i += 2)
        if(mark[ i ]) prime.pb( i );
    prlim = prime.size();
}
int phi(int n)
{
    int res = n;
    for(int i = 0; i < prlim; i++)
    {
        if(!(n % prime[ i ]))
        {
            while(!(n % prime[ i ])) n /= prime[ i ];
            res -= res / prime[ i ];
        }
        if(n == 1 || (n < MAX && mark[ n ])) break;
    }
    if(n > 1) res -= res / n;
    return res;
}
int div(int n)
{
    long long i = 2;
    int res = 1;
    for(; i * i < n; i++)
    {
        if(!(n % i)) res += 2;
    }
    res += i * i == n ? 1 : 0;
    return res;
}

