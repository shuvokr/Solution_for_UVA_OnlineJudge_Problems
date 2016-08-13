/*****************************************************/
/*            Shuvo Kr                               */
/*            CS & E                                 */
/*            Daffodil International Univeraity      */
/*****************************************************/

#pragma comment(linker, "/stack:64000000")

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
#include <deque>
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
#define pb push_back
#define lim(v) v.begin(), v.end()
#define sz(v) ((int)v,size())
#define equals(a, b) (fabs(a-b)<eps)
#define si1(a) scanf("%d", &a)
#define pi1(a) printf("%d\n", a)
#define si2(a, b) scanf("%d %d", &a, &b)
#define pi2(a, b) printf("%d %d\n", a, b)
#define si3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define pi3(a, b, c) printf("%d %d %d\n", a, b, c)

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
template <class T> T power ( T a, T p ) { T res = 1, x = a; while ( p ) { if ( p & 1 ) res = res * x; x = x * x; p >>= 1; } return res;}
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

/*
#define M 1000005
int phi[M];

void calculatePhi()
{
    for (int i = 1; i < M; i++) phi[i] = i;
    for (int p = 2; p < M; p++)
        if (phi[p] == p) // p is a prime
            for (int k = p; k < M; k += p) phi[k] -= phi[k] / p;
}
*/

/*
const int pr = 500001;
int prime[ 41539 ], ind;
bool mark[ pr ];
void primelist()
{
    for(int i = 4; i < pr; i += 2) mark[ i ] = false;
    for(int i = 3; i < pr; i += 2) mark[ i ] = true; mark[ 2 ] = true;
    for(int i = 3, sq = sqrt( pr ); i < sq; i += 2)
        if(mark[ i ])
            for(int j = i * i; j < pr; j += i + i) mark[ j ] = false;
    prime[ 0 ] = 2; ind = 1;
    for(int i = 3; i < pr; i += 2)
        if(mark[ i ]) ind++; printf("%d\n", ind);
}
*/

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

#define check(n, pos) (n & (1<<(pos)))
#define biton(n, pos) (n | (1<<(pos)))
#define bitoff(n, pos) (n & ~(1<<(pos)))

void Input();
const int INF = 2147483647;
const long long LINF = 9223372036854775807ll;
/**************************Templet end*********************************/

lld Ta, Td, H, tmp;
vector <lld> in;

int main()
{
    //#ifdef monkey
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    //#endif
    Input();

    return 0;
    /// Not use cin/cout without necessity. This a causes of TLE :p
}
void Input()
{
    int T, n, kag = 0; si1( T );
    while( T-- )
    {
        sf("%d %lld %lld %lld", &n, &H, &Ta, &Td);
        in.clear();
        for(int i = 0; i < n; i++)
        {
            scanf("%lld", &tmp);
            in.push_back( tmp );
        }
        sort(in.begin(), in.end());
        lld ans = 0;
        while( in.size() )
        {
            if(in.size() == 1)
            {
                ans += Ta;
                in.clear();
            }
            else
            {

                if(Td >= Ta * 2) ans = in.size() * Ta, in.clear();
                else
                {
                    lld x = in[ in.size() - 1 ];
                    if(in[ 0 ] + x < H)
                    {
                        lld cou = 1; tmp = 0;
                        if(in.size() && x + in[ 0 ] < H)
                        {
                            in.erase(in.begin() + in.size() - 1);
                            lld b = 0, e = in.size() - 1, mid;
                            while(e - b > 1)
                            {
                                mid = (e + b) / 2;
                                if(in[ mid ] + x >= H) e = mid;
                                else b = mid;
                            }
                            if(in[ e ] + x < H)
                            {
                                x += in[ e ];
                                in.erase(in.begin() + e);
                                ans += Td;
                            }
                            else
                            {
                                x += in[ b ];
                                in.erase(in.begin() + b);
                                ans += Td;
                            }
                        }
                    }
                    else
                    {
                        ans += Ta;
                        in.erase(in.begin() + in.size() - 1);
                    }
                }
            }
        }
        printf("Case %d: %lld\n", ++kag, ans);
    }
}
