/*************************
    Shuvo
    Problem ID: 908
    Problem algo: Graph MST ( Kruskal )
**************************/
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

int find_parent(int child);

struct data
{
    int cost, u, v;
    bool operator < (const data &x) const
    {
        return cost < x.cost;
    }
}take;

data graph[ 1000020 ];
int par[ 1000020 ], a, b, m, k, i, u, v, n, tot, res, cst, cnt;

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    bool space = false;
    while( ~scanf("%d", &n) )
    {
        if( space ) puts("");
        else space = true;
        tot = 0;
        for(i = 1; i < n; i++) scanf("%d %d %d", &u, &v, &cst), tot += cst;
        scanf("%d", &k);
        for(i = 0; i < k; i++)
        {
            scanf("%d %d %d", &graph[ i ].u, &graph[ i ].v, &graph[ i ].cost);
            par[ i ] = i;
        }
        scanf("%d", &m); m = k + m;
        for(i = k; i < m; i++)
        {
            par[ i ] = i;
            scanf("%d %d %d", &graph[ i ].u, &graph[ i ].v, &graph[ i ].cost);
        }
        sort(graph, graph + m);
        res = cnt = 0;
        for(i = 0; i < m; i++)
        {
            a = find_parent(graph[ i ].u);
            b = find_parent(graph[ i ].v);
            if(a != b)
            {
                par[ a ] = b;
                res += graph[ i ].cost;
                cnt++;
                if(cnt == n - 1) break;
            }
        }
        printf("%d\n%d\n", tot, res);
    }
    return 0;
}
int find_parent(int child)
{
    if(par[ child ] == child) return child;
    else return par[ child ] = find_parent(par[ child ]);
}
