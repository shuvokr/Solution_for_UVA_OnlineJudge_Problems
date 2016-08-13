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

const int pr = 10000001;
int prime[ 664580 ], ind;
bool mark[ pr ];
void primelist()
{
    for(int i = 4; i < pr; i += 2) mark[ i ] = false;
    for(int i = 3; i < pr; i += 2) mark[ i ] = true; mark[ 2 ] = true;
    for(int i = 3, sq = sqrt( pr ); i < sq; i += 2)
        if(mark[ i ])
            for(int j = i << 1; j < pr; j += i) mark[ j ] = false;
    prime[ 0 ] = 2; ind = 1;
    for(int i = 3; i < pr; i += 2)
        if(mark[ i ]) prime[ ind++ ] = i; //printf("%d\n", ind);
}

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

void input();

/**************************Templet end*********************************/

void save_result();
bool isok(int n);
bool fuck_you(char num[]);

int k, data[ ] = {2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97, 113, 131, 199, 311, 337, 373, 733, 919, 991};

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
    //primelist();
    //save_result();
    int n;
    while(sf("%d", &n) && n)
    {
        n++;
        if(data[ 21 ] < n) puts("0");
        else
        {
            bool ma = true;
            int i, p = 1, len = log10(n);
            while(power(10, p) < n && p < 10) p++;
            p = power(10, p);
            //printf("  %d\n", p);
            for(i = 0; i < 22 && data[ i ] <= p; i++)
                if(data[ i ] >= n) ma = false, printf("%d\n", data[ i ]), i = 100;
            if(ma) puts("0");
        }
    }
}
void save_result()
{
    k = 0;
    for(int i = 0; i < ind; i++)
    {
        if( isok( prime[ i ] ) )  printf("%d, ", prime[ i ]), data[ k++ ] = prime[ i ];
    }
    //printf("%d\n", k);
}
bool isok(int n)
{
    if(n == 2) return true;
    char num[ 12 ];
    int len = log10( n ), s = len + 1; num[len + 1] = NULL;

    bool mark[ 12 ];

    while( n )
    {
        int tt = n % 10 + 48;
        if(!(n & 1)) return false;
        num[ len-- ] = n % 10 + 48;
        n /= 10;
    }

    if(!fuck_you( num )) return false;
    return true;
}
bool fuck_you(char num[])
{
    int len = strlen( num );
    sort(num, num + len);
    do
    {
        int n = atoi( num );
        if(mark[ n ] == false) return false;
    }while( std::next_permutation(num, num + len) );
    return true;
}
