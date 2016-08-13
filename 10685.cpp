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
#define maxn 200000+2

#define white 0
#define black 1

typedef vector <int> vi;

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

//Templet end
void input();
void BFS(int u);

int node, edge, cou;
map <string, int> m;
bool graph[ 5002 ][ 5002 ], mark[ 5002 ];

int main()
{
    input();

    return 0;
}
void input()
{
    int i, j, k, res;
    char in[ 32 ], in2[ 32 ];
    while(sf("%d %d", &node, &edge) != EOF)
    {
        if(!node && !edge) break;
        fo(i, node)
        {
            mark[ i ] = true;
            fo(j, node) graph[ i ][ j ] = false;
        }
        k = 1; getchar();
        fo(i, node)
        {
            gets( in );
            m [ in ] = k++;
        }
        fo(j, edge)
        {
            sf("%s %s", in, in2);
            //puts( in ); puts( in2 );
            graph[ m[ in ] ][ m[ in2 ] ] = true;
            graph[ m[ in2 ] ][ m[ in ] ] = true;
        }
        res = -1;
        fo(i, node)
            fo(j, node)
            {
                if(graph[ i ][ j ])
                {
                    BFS( i );
                    res = max(cou, res);
                }
            }
        pf("%d\n", res);
    }
}
void BFS( int u )
{
    //pf("(%d)\n", u);
    int i, j, tmp;
    cou = 0;
    queue <int> Q;
    Q.push( u );

    while(!Q.empty())
    {
        tmp = Q.front(); Q.pop();
        //pf(">>%d\n", tmp);
        fo(i, node)
        {
            if(graph[ tmp ][ i ])
            {
                if(mark[ tmp ]) mark[ tmp ] = false, cou++;
                if(mark[ i ]) mark[ i ] = false, cou++;
                graph[ tmp ][ i ] = false;
                graph[ i ][ tmp ] = false;
                Q.push( i );
            }
        }
    }
    //pf(" %d\n", cou);
}
