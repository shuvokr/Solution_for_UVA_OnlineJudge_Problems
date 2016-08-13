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
    int T, k, len, i, j, in1[ 10010 ], in2[ 10010 ];
    char ch[ 10010 ];
    scanf("%d", &T); getchar();
    while(T--)
    {
        gets( ch );
        len = strlen( ch );
        if(ch[ 0 ] == 'W' || ch[len - 1] == 'B')
        {
            puts("IMPOSSIBLE");
            continue;
        }
        else
        {
            CLR(in1, 0); CLR(in2, 0);
            in1[ 0 ] = 1; i = 1; j = 0;
            for(int k = 1; k < len - 1; k++)
            {
                if(ch[ k ] == 'W') in1[ i++ ] = k + 1;
                else in2[ j++ ] = k + 1;
            }
            if(i + 1 == len)
            {
                in1[ i++ ] = len;
            }
            else in2[ j++ ] = len;
            if(in1[ 1 ] != 0 && in2[ 0 ] != 0)
            {
                puts("2");
                printf("%d", i);
                for(k = 0; k < i; k++) printf(" %d", in1[ k ]); puts("");
                printf("%d", j);
                for(k = 0; k < j; k++) printf(" %d", in2[ k ]); puts("");
            }
            else if(in1[ 1 ] != 0)
            {
                puts("1");
                printf("%d", i);
                for(k = 0; k < i; k++) printf(" %d", in1[ k ]); puts("");
            }
            else
            {
                puts("1");
                printf("%d", j);
                for(k = 0; k < j; k++) printf(" %d", in2[ k ]); puts("");
            }
        }
    }
}

