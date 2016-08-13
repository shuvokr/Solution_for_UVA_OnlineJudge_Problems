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

vector <int> prime;
bool mark[ 1000010 ];
int res[ 1000010 ];

int main()
{
    mark[ 0 ] = mark[ 1 ] = false;
    for(int i = 4; i < 1000001; i += 2) mark[ i ] = false;
    for(int i = 3; i < 1000001; i += 2) mark[ i ] = true; mark[ 2 ] = true;
    for(int i = 3; i < 1001; i += 2)
        if(mark[ i ])
            for(int j = i + i; j < 1000001; j += i) mark[ j ] = false;
    prime.pb( 2 );
    for(int i = 3; i < 1000001; i += 2)
        if(mark[ i ]) prime.pb( i );
    prime.pb( 1000000000 );
    //#ifdef localhost
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    //#endif
    input();

    return 0;
}
void input()
{
    //for(int i = 0; i < 100; i++) printf("%d ", prime[ i ]); puts("");
    int L, H, T, low, high, mid, a, b;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &L, &H);
        if(L >= H)
        {
            puts("No jumping champion");
            continue;
        }
        low = 0; high = prime.size() - 1;
        while(high - low > 1)
        {
            mid = (low + high) / 2;
            if(prime[ mid ] > L) high = mid;
            else low = mid;
        }
        if(prime[ low ] < L) low++;
        low++; int i = 0;
        //for(int j = low; prime[ j ] <= H; j++) printf("*%d ", prime[ j ]); puts("");
        CLR(res, 0);
        while(prime[ low ] <= H)
        {
            res[ i++ ] = prime[ low ] - prime[low - 1];
            low++;
        }
        sort(res, res + i);
        int dif = 0, ans = 0;
        for(int j = 0; j < i;)
        {
            int tmp = res[ j ], cou = 0;
            while(res[ j ] == tmp)
            {
                cou++;
                j++;
            }
            if(dif < cou)
            {
                dif = cou;
                ans = tmp;
            }
            else if(dif == cou) ans = -1;
        }
        if(ans == -1 || !dif) puts("No jumping champion");
        else printf("The jumping champion is %d\n", ans);
    }
}

