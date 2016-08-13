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


bool EndOF();

char board[ 15 ][ 15 ];
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
    int kag = 0, fuckW, fuckB;
    while( true )
    {
        fuckW = fuckB = 0;
        for(int i = 0; i < 8; i++) cin >> board[ i ];
        if(EndOF()) return;
        int i, j;
        for(i = 0; i < 8; i++)
        {
            for(j = 0; j < 8; j++)
            {
                //if(board[ i ][ j ] == '.' || board[ i ][ j ] == 'k' || board[ i ][ j ] == 'K') continue;
                if(board[ i ][ j ] == 'P' && (board[i - 1][j - 1] == 'k' || board[i - 1][j + 1] == 'k')) fuckB = 1;
                else if(board[ i ][ j ] == 'p' && (board[i + 1][j - 1] == 'K' || board[i + 1][j + 1] == 'K')) fuckW = 1;
                else if(board[ i ][ j ] == 'n')
                {
                    for(int k = 0; k < 8; k++)
                    {
                        int a = i + horsed1[ k ];
                        int b = j + horsed2[ k ];
                        if(board[ a ][ b ] == 'K') fuckW = 1;
                    }
                }
                else if(board[ i ][ j ] == 'N')
                {
                    for(int k = 0; k < 8; k++)
                    {
                        int a = i + horsed1[ k ];
                        int b = j + horsed2[ k ];
                        if(board[ a ][ b ] == 'k') fuckB = 1;
                    }
                }
                else if(board[ i ][ j ] == 'K')
                {
                    int k = j + 1;
                    while(k < 8 && board[ i ][ k ] == '.') {k++;} if(k < 8 && board[ i ][ k ] != 'k' && (board[ i ][ k ] == 'q' || board[ i ][ k ] == 'r')) fuckW = 1;
                    k = j - 1;
                    while(k > -1 && board[ i ][ k ] == '.') {k--;} if(k > -1 && board[ i ][ k ] != 'k' && (board[ i ][ k ] == 'q' || board[ i ][ k ] == 'r')) fuckW = 1;
                    k = i + 1;
                    while(k < 8 && board[ k ][ j ] == '.') {k++;} if(k < 8 && board[ k ][ j ] != 'k' && (board[ k ][ j ] == 'q' || board[ k ][ j ] == 'r')) fuckW = 1;
                    k = i - 1;
                    while(k > -1 && board[ k ][ j ] == '.') {k--;} if(k > -1 && board[ k ][ j ] != 'k' && (board[ k ][ j ] == 'q' || board[ k ][ j ] == 'r')) fuckW = 1;
                    int a = i - 1, b = j - 1;
                    while(a > -1 && b > -1 && board[ a ][ b ] == '.') {a--; b--;} if(a > -1 && b > -1 && board[ a ][ b ] != 'k' && (board[ a ][ b ] == 'q' || board[ a ][ b ] == 'b')) fuckW = 1;
                    a = i + 1; b = j - 1;
                    while(a < 8 && b > -1 && board[ a ][ b ] == '.') {a++; b--;} if(a < 8 && b > -1 && board[ a ][ b ] != 'k' && (board[ a ][ b ] == 'q' || board[ a ][ b ] == 'b')) fuckW = 1;
                    a = i - 1, b = j + 1;
                    while(a > -1 && b < 8 && board[ a ][ b ] == '.') {a--; b++;} if(b < 8 && a > -1 && board[ a ][ b ] != 'k' && (board[ a ][ b ] == 'q' || board[ a ][ b ] == 'b')) fuckW = 1;
                    a = i + 1, b = j + 1;
                    while(a < 8 && b < 8 && board[ a ][ b ] == '.') {a++; b++;} if(a < 8 && b < 8 && board[ a ][ b ] != 'k' && (board[ a ][ b ] == 'q' || board[ a ][ b ] == 'b')) fuckW = 1;
                }
                else if(board[ i ][ j ] == 'k')
                {
                    int k = j + 1;
                    while(k < 8 && board[ i ][ k ] == '.') {k++;} if(k < 8 && board[ i ][ k ] != 'K' && (board[ i ][ k ] == 'Q' || board[ i ][ k ] == 'R')) fuckB = 1;
                    k = j - 1;
                    while(k > -1 && board[ i ][ k ] == '.') {k--;} if(k > -1 && board[ i ][ k ] != 'K' && (board[ i ][ k ] == 'Q' || board[ i ][ k ] == 'R')) fuckB = 1;
                    k = i + 1;
                    while(k < 8 && board[ k ][ j ] == '.') {k++;} if(k < 8 && board[ k ][ j ] != 'K' && (board[ k ][ j ] == 'Q' || board[ k ][ j ] == 'R')) fuckB = 1;
                    k = i - 1;
                    while(k > -1 && board[ k ][ j ] == '.') {k--;} if(k > -1 && board[ k ][ j ] != 'K' && (board[ k ][ j ] == 'Q' || board[ k ][ j ] == 'R')) fuckB = 1;
                    int a = i - 1, b = j - 1;
                    while(a > -1 && b > -1 && board[ a ][ b ] == '.') {a--; b--;} if(a > -1 && b > -1 && board[ a ][ b ] != 'K' && (board[ a ][ b ] == 'Q' || board[ a ][ b ] == 'B')) fuckB = 1;
                    a = i + 1, b = j - 1;
                    while(a < 8 && b > -1 && board[ a ][ b ] == '.') {a++; b--;} if(a < 8 && b > -1 && board[ a ][ b ] != 'K' && (board[ a ][ b ] == 'Q' || board[ a ][ b ] == 'B')) fuckB = 1;
                    a = i - 1, b = j + 1;
                    while(a > -1 && b < 8 && board[ a ][ b ] == '.') {a--; b++;} if(b < 8 && a > -1 && board[ a ][ b ] != 'K' && (board[ a ][ b ] == 'Q' || board[ a ][ b ] == 'B')) fuckB = 1;
                    a = i + 1, b = j + 1;
                    while(a < 8 && b < 8 && board[ a ][ b ] == '.') {a++; b++;} if(a < 8 && b < 8 && board[ a ][ b ] != 'K' && (board[ a ][ b ] == 'Q' || board[ a ][ b ] == 'B')) fuckB = 1;
                }
            }
        }
        if(fuckB && fuckW) pf("Game #%d: white king is in check.\n", ++kag);
        else if( fuckB ) pf("Game #%d: black king is in check.\n", ++kag);
        else if( fuckW ) pf("Game #%d: white king is in check.\n", ++kag);
        else pf("Game #%d: no king is in check.\n", ++kag);
    }
}
bool EndOF()
{
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++) if(board[ i ][ j ] != '.') return false;
    return true;
}
