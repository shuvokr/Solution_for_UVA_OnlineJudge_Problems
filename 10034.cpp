/*******************************
    Shuvo
    Problem ID: 10034
    Problem algo: Graph MST ( Kruskal )
********************************/
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
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define long long lld
#define llu unsigned long long
#define fo(i, n) for(i = 0; i < n; i++)
#define of(i, n) for(i = n - 1; i >= 0; i--)
#define mem(n, v) memset(n, v, sizeof( n ))
#define eps 1e-8
#define INF 5000
#define pb push_back
#define maxn 200+2

#define white 0
#define black 1

typedef pair<int, int> pii;
typedef  vector<int> vi;
typedef vector<pii> vii;


int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

/**************************Templet end*********************************/

int find_parent(int n);

double a, b, cst, X[ 105 ], Y[ 105 ];
int n, T, i, j, u, v, pos, par[ 105 ];

struct data
{
    int u, v;
    double cost;
    bool operator < (const data &x) const
    {
        return cost < x.cost;
    }
}in[ 10005 ];

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    bool space = false;
    scanf("%d", &T);
    while( T-- )
    {
        if( space ) puts("");
        else space = true;
        scanf("%d", &n);
        for(i = 0; i < n; i++) scanf("%lf %lf", &X[ i ], &Y[ i ]), par[ i ] = i;
        pos = 0;
        for(i = 0; i < n; i++)
            for(j = i + 1; j < n; j++)
            {
                a = (X[ i ] - X[ j ]); a *= a;
                b = (Y[ i ] - Y[ j ]); b *= b;
                cst = sqrt( a + b );
                in[ pos ].u = i;
                in[ pos ].v = j;
                in[ pos ].cost = cst;
                pos++;
            }
        sort(in, in + pos);
        cst = 0.0; j = 0;
        for(i = 0; i < pos; i++)
        {
            u = find_parent( in[ i ].u );
            v = find_parent( in[ i ].v );
            if(u != v)
            {
                par[ u ] = v;
                cst += in[ i ].cost;
                j++;
                if(j == n - 1) break;
            }
        }
        printf("%.2lf\n", cst);
    }
    return 0;
}
int find_parent(int n)
{
    if(par[ n ] == n) return n;
    else return par[ n ] = find_parent( par[ n ] );
}
