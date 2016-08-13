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
//const int pr = 500001;
//int prime[ 41539 ], ind;
//bool mark[ pr ];
//void primelist()
//{
//    for(int i = 4; i < pr; i += 2) mark[ i ] = false;
//    for(int i = 3; i < pr; i += 2) mark[ i ] = true; mark[ 2 ] = true;
//    for(int i = 3, sq = sqrt( pr ); i < sq; i += 2)
//        if(mark[ i ])
//            for(int j = i << 1; j < pr; j += i) mark[ j ] = false;
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

void DFS(int i, int j, int move);
bool isok();
bool boder(int i, int j);

int res;
char graph[ 6 ][ 10 ];

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
        int s, e;
        for(int i = 0; i < 5; i++)
        {
            gets( graph[ i ] );
            if(graph[ i ][ 0 ] == NULL)
            {
                i--;
                continue;
            }
            for(int j = 0; j < 5; j++)
            {
                if(graph[ i ][ j ] == ' ') s = i, e = j;
            }
        }

        if(isok())
        {
            printf("Solvable in 0 move(s).\n");
            continue;
        }

        res = 1 << 29;
        DFS(s, e, 0);
        if(res < 11) printf("Solvable in %d move(s).\n", res);
        else puts("Unsolvable in less than 11 move(s).");
    }
}
void DFS(int i, int j, int move)
{
    if(move > 10) return;
    if(isok())
    {
        res = move < res ? move : res;
    }
    for(int k = 0; k < 8; k++)
    {
        int a = i + horsed1[ k ];
        int b = j + horsed2[ k ];
        if(boder(a, b))
        {
            graph[ i ][ j ] = graph[ a ][ b ];
            graph[ a ][ b ] = ' ';

            DFS(a, b, move + 1);

            graph[ a ][ b ] = graph[ i ][ j ];
            graph[ i ][ j ] = ' ';
        }
    }
}
bool isok()
{
    if(graph[ 0 ][ 0 ] == '0' || graph[ 0 ][ 1 ] == '0' || graph[ 0 ][ 2 ] == '0' || graph[ 0 ][ 3 ] == '0' || graph[ 0 ][ 4 ] == '0') return false;
    if(graph[ 1 ][ 0 ] == '1' || graph[ 1 ][ 1 ] == '0' || graph[ 1 ][ 2 ] == '0' || graph[ 1 ][ 3 ] == '0' || graph[ 1 ][ 4 ] == '0') return false;
    if(graph[ 2 ][ 0 ] == '1' || graph[ 2 ][ 1 ] == '1' || graph[ 2 ][ 2 ] != ' ' || graph[ 2 ][ 3 ] == '0' || graph[ 2 ][ 4 ] == '0') return false;
    if(graph[ 3 ][ 0 ] == '1' || graph[ 3 ][ 1 ] == '1' || graph[ 3 ][ 2 ] == '1' || graph[ 3 ][ 3 ] == '1' || graph[ 3 ][ 4 ] == '0') return false;
    if(graph[ 4 ][ 0 ] == '1' || graph[ 4 ][ 1 ] == '1' || graph[ 4 ][ 2 ] == '1' || graph[ 4 ][ 3 ] == '1' || graph[ 4 ][ 4 ] == '1') return false;
    //if(graph[ 2 ][ 2 ] == ' ') {for(int i = 0; i < 5; i++) puts( graph[ i ] ); puts("");}
    return true;
}
bool boder(int i, int j)
{
    if(i < 0 || j < 0 || i > 4 || j > 4) return false;
    return true;
}
