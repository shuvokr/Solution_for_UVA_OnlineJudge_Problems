//NlogK for find lis lenth

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

const int inf = 2000000000; // a large value as infinity

int n; // the number of items in the sequence
int Sequence[ 62505 ], mkk[ 62505 ]; // the sequence of integers
int L[ 62505 ]; // L[] as described in the algorithm
int I[ 62505 ]; // I[] as described in the algorithm.. the longest incriging sequence =D

void takeInput()
{
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    CLR(mkk, 0);
    for(int i = 1, tmp; i <= y + 1; i++) scanf("%d", &tmp), mkk[ tmp ] = i;
    n = 0;
    //scanf("%d", &n); // how many numbers in the sequence ?
    for( int i = 0, tmp; i <= z; i++ ) // take the sequence
    {
        scanf("%d", &tmp);
        if( mkk[ tmp ] ) Sequence[ n++ ] = mkk[ tmp ];
    }
}

int LisNlogK()
{ // which runs the NlogK LIS algorithm
    int i; // auxilary variable for iteration

    I[0] = -inf; // I[0] = -infinite
    for( i = 1; i <= n; i++ ) // observe that i <= n are given
        I[i] = inf; // I[1 to n] = infinite

    int LisLength = 0; // keeps the maximum position where a data is inserted

    for( i = 0; i < n; i++ ) { // iterate left to right
        int low, high, mid; // variables to perform binary search
        low = 0; // minimum position where we to put data in I[]
        high = LisLength; // the maximum position

        while( low <= high )
        { // binary search to find the correct position
            mid = ( low + high ) / 2;
            if( I[mid] < Sequence[i] )
                low = mid + 1;
            else
                high = mid - 1;
        }
        // observe the binary search carefully, when the binary search ends
        // low > high and we put our item in I[low]
        I[low] = Sequence[i];
        if( LisLength < low ) // LisLength contains the maximum position
            LisLength = low;
    }

    return LisLength; // return the result
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T, kag = 0;
    scanf("%d", &T);
    while( T-- )
    {
        takeInput();
        int result = LisNlogK();
        printf("Case %d: %d\n", ++kag, result);
        //for(int i = 1; i <= result; i++) printf("%d\n", I[ i ]);
    }
    return 0;
}
