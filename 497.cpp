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
const int maxn = 100000;
class element { public: int value; int index;};
element a[maxn],lis[maxn];
int trace[maxn],ans[maxn];
int n;
int BSearch(int i, int j, int x) {
 int l,r,m;
 l = i; r = j;
 if (r<l) return(-1);
 do
 {
  m = (l+r)/2;
  if (lis[m].value>=x) r = m;
  else l = m;
 } while (r-l>1);
 if (lis[l].value>=x) return(l);
 else if (lis[r].value>=x) return(r);
 else return(-1);
}
int solve() {
 int result = 0;
 for (int i=1; i<=n; i++)
 {
  int pos = BSearch(1,result,a[i].value);
  if (pos!=-1)
  {
   lis[pos] = a[i];
   if (pos==1) trace[i] = -1;
   else trace[i] = lis[pos-1].index;
  }
  else
  {
   lis[++result] = a[i];
   if (result==1) trace[i] = -1;
   else trace[i] = lis[result-1].index;
  }
 }
 int cnt = 0, x = lis[result].index;
 while (trace[x]!=-1)
 {
  ans[++cnt] = a[x].value;
  x = trace[x];
 }
 ans[++cnt] = a[x].value;
 return(result);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int T; bool space = false;
    scanf("%d", &T); getchar(); getchar();
    while( T-- )
    {
        if(space) puts("");
        else space = true;
         n = 0;
         int result;
         char num[ 40 ];
         while (gets( num ) && strlen( num ) > 0)
         {
            a[ ++n ].value = atoi( num );
            a[n].index = n;
         }
         result = solve();
         printf("Max hits: %d\n", result);
         for (int i=result; i>=1; i--) printf("%d\n", ans[ i ]);
    }
 return 0;
}
