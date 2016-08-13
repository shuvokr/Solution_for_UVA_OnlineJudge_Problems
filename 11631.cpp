/**********************************************************************************

    Shuvo
    Problem ID: 1631
    Problem Name: Dark roads
    Problem Algo: Graph ( Kruskal - MST )

*************************************************************************************/

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

int find_repragentative(int n);

struct data
{
    int u, v, cost;
    bool operator < (const data &x) const
    {
        return cost < x.cost;
    }
}tmp[ 200005 ];

int node, edge, u, v, cost, par[ 200005 ];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int len, i, tot, mini, brk;
    while( ~scanf("%d %d", &node, &edge) && (node || edge))
    {
        tot = 0;
        for(i = 0; i < edge; i++)
        {
            scanf("%d %d %d", &tmp[ i ].u, &tmp[ i ].v, &tmp[ i ].cost);
            tot += tmp[ i ].cost;
        }
        sort(tmp, tmp + edge);
        for(i = 0; i < node; i++) par[ i ] = i;
        brk = mini = 0;
        for(i = 0; i < edge; i++)
        {
            int a = tmp[ i ].u, b = tmp[ i ].v;
            u = find_repragentative( a );
            v = find_repragentative( b );
            if(u != v)
            {
                par[ u ] = v;
                mini += tmp[ i ].cost;
                brk++;
                if( brk == node ) break;
            }
        }
        printf("%d\n", tot - mini);
    }
    return 0;
}
int find_repragentative(int n)
{
    if(par[ n ] == n) return n;
    else return par[ n ] = find_repragentative(par[ n ]);
}
