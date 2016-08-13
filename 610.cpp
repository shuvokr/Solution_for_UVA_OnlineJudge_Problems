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
#define fo(i, n) for(i = 1; i <= n; i++)
#define of(i, n) for(i = n - 1; i >= 0; i--)
#define mem(n, v) memset(n, v, sizeof( n ))
#define eps 1e-8
#define INF 5000
#define pb push_back
#define maxn 2000+100

#define white 0
#define black 1

typedef vector <int> vi;

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

//Templet end
void input();
void reset();
void DFS( int u );
void fst_sort();
void snd_sort();

int node, edge, dfs_num[ maxn ], dfs_low[ maxn ], dfs_counter, parents[ maxn ], res_number;
bool mark[ maxn ][ maxn ];
vector < int > graph[ maxn ];
int res[ maxn ][ 2 ];

int main()
{
    //freopen("output.txt", "w", stdout);
    input();

    return 0;
}
void input()
{
    int i, u, v, kag = 0;
    while(sf("%d %d", &node, &edge) != EOF)
    {
        if(!node && !edge) break;
        reset();
        fo(i, edge)
        {
            sf("%d %d", &u, &v);
            graph[ u ].pb( v ); mark[ u ][ v ] = true;
            graph[ v ].pb( u ); mark[ v ][ u ] = true;
        }
        pf("%d\n\n", ++kag);
        fo(i, node)
        {
            if(graph[ i ].size() > 0) DFS( i );
        }
        fst_sort(); snd_sort();
        //pf("      %d\n", res_number);
        for(i = 0; i < res_number; i++)
                pf("%d %d\n", res[ i ][ 0 ], res[ i ][ 1 ]);
        puts("#");
    }
}
void DFS( int u )
{
    dfs_low[ u ] = dfs_num[ u ] = dfs_counter++;
    for(int i = 0; i < graph[ u ].size(); i++)
    {
        int v = graph[ u ][ i ];
        if(mark[ u ][ v ])
        {
            mark[ u ][ v ] = mark[ v ][ u ] = false;
            res[ res_number ][ 0 ] = u;
            res[ res_number ][ 1 ] = v;
            //res[ res_number ].pb( u );
            //res[ res_number ].pb( v );
            res_number++;
            //pf("%d %d\n", u, v);
        }
        if( dfs_num[ v ] == -1 )
        {
            parents[ v ] = u;
            DFS( v );
            if(dfs_num[ u ] < dfs_low[ v ])
            {
                res[ res_number ][ 0 ] = v;
                res[ res_number ][ 1 ] = u;
                //res[ res_number ].pb( v );
                //res[ res_number ].pb( u );
                res_number++;
                //pf(" %d %d\n", v, u);
            }
            dfs_low[ u ] = min(dfs_low[ u ], dfs_low[ v ]);
        }
        else if(parents[ u ] != v)
        {
            dfs_low[ u ] = min(dfs_low[ u ], dfs_num[ v ]);
        }
    }
}
void reset()
{
    int i, j;
    fo(i, node + 2)
    {
        graph[ i ].clear();
        dfs_low[ i ] = -1;
        dfs_num[ i ] = -1;
        parents[ i ] = -1;
        fo(j, node + 2) mark[ i ][ j ] = false;
    }
    mem(res, 0);
    dfs_counter = res_number = 0;
}
void fst_sort()
{
    int i, j, n, nn;
    for(i = 0; i < res_number; i++)
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
    for(i = 0; i < res_number; i++)
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
