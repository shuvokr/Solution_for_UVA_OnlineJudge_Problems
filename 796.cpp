/*
        Shuvo
        Problem algo: Bridge find(DFS)
        Problem ID: 796
        Problem name: Critical Links
*/
//Templet start
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
#define gray 1
#define black 2

typedef vector <int> vi;
typedef pair<int, int> pi;

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

//Templet end

void input();
void reset();
void DFS( int u );
int make_n();
void fst_sort();
void snd_sort();

int dfs_num[ maxn ], dfs_low[ maxn ], parents[ maxn ], dfs_counter, node, res_number;
vector <int> graph[ maxn ];
char c[ 8 ], cc [ 8 ];
vector <int> res[ maxn ];

int main()
{
    input();

    return 0;
}
void input()
{
    int i, j, u, n, v, T, k = 0, kag = 0;

    while(~sf("%d", &node))
    {
        reset();
        fo(i, node)
        {
            sf("%d", &u);
            mem(c, 0); mem(cc, 0);
            sf("%s", c);
            n = make_n();
            fo(j, n)
            {
                sf("%d", &v);
                graph[ u ].push_back( v );
            }
        }
        dfs_counter = res_number = 0;
        fo(i, node)
        {
            if(graph[ i ].size() > 0)
            {
                DFS( i );
            }
        }

        pf("%d critical links\n", res_number);
        if(res_number > 0)
        {
            fst_sort();
            snd_sort();
            fo(i, res_number)
                pf("%d - %d\n", res[ i ][ 0 ], res[ i ][ 1 ]);
        }
        puts("");
    }
}

void reset()
{
    int i;
    fo(i, node)
    {
        graph[ i ].clear();
        res[ i ].clear();
        parents[ i ] = -1;
        dfs_low[ i ] = 0;
        dfs_num[ i ] = -1;
    }
}

int make_n()
{
    int k = 0, n, j;
    while(!isdigit(c[ k ])) k++;
    j = 0;
    while(isdigit(c[ k++ ])) cc[ j++ ] = c[ k - 1 ];
    sscanf(cc, "%d", &n);
    return n;
}

void DFS(int u)
{
    dfs_low[ u ] = dfs_counter;
    dfs_num[ u ] = dfs_counter;
    dfs_counter++;
    int i;
    fo(i, graph[ u ].size())
    {
        int v = graph[ u ][ i ];
        if( dfs_num[ v ] == -1 )
        {
            parents[ v ] = u;
            DFS( v );
            if(dfs_num[ u ] < dfs_low[ v ])
            {
                if(u < v)
                {
                    res[ res_number ].push_back( u );
                    res[ res_number ].push_back( v );
                }
                else
                {
                    res[ res_number ].push_back( v );
                    res[ res_number ].push_back( u );
                }
                res_number++;
            }
            dfs_low[ u ] = min(dfs_low[ u ], dfs_low[ v ]);
        }
        else if(parents[ u ] != v)
        {
            dfs_low[ u ] = min(dfs_low[ u ], dfs_num[ v ]);
        }
    }
}
void fst_sort()
{
    int i, j, n, nn;
    fo(i, res_number - 1)
    {
        for(j = i + 1; j < res_number; j++)
        {
            if(res[ i ][ 0 ] > res[ j ][ 0 ])
            {
                n = res[ i ][ 0 ];
                nn = res[ i ][ 1 ];
                res[ i ][ 0 ] = res[ j ][ 0 ];
                res[ i ][ 1 ] = res[ j ][ 1 ];
                res[ j ][ 0 ] = n;
                res[ j ][ 1 ] = nn;
            }
        }
    }
}
void snd_sort()
{
    int i, j, n, nn;
    fo(i, res_number - 1)
    {
        for(j = i + 1; j < res_number; j++)
        {
            if(res[ i ][ 1 ] > res[ j ][ 1 ] && res[ i ][ 0 ] == res[ j ][ 0 ])
            {
                n = res[ i ][ 0 ];
                nn = res[ i ][ 1 ];
                res[ i ][ 0 ] = res[ j ][ 0 ];
                res[ i ][ 1 ] = res[ j ][ 1 ];
                res[ j ][ 0 ] = n;
                res[ j ][ 1 ] = nn;
            }
        }
    }
}
