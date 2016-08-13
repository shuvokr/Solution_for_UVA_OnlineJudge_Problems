#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define LLD long long
#define LD long
#define fo(i, n) for(i = 0; i < n; i++)
#define of(i, n) for(i = n - 1; i >= 0; i--)
#define mem(n) memset(n, 0, sizeof(n))

#define white 1
#define red 2
#define NIL -1

void input();
void BFS(int sorce, int end);
void print_path(int sorce, int end);

int graph[ 28 ][ 28 ], parents[ 28 ], k;
char ans[ 100 ];

int main()
{
    input();

    return 0;
}
void input()
{
    int T, edge, kag, r, c, s, e;
    char in1[ 100 ], in2[ 100 ];
    sf("%d", &T);
    while(T--)
    {
        sf("%d %d", &edge, &kag);
        mem( graph );
        while(edge--)
        {
            sf("%s%s", in1, in2);
            r = in1[ 0 ] - 'A';
            c = in2[ 0 ] - 'A';
            graph[ r ][ c ] = 1;
            graph[ c ][ r ] = 1;
        }
        while(kag--)
        {
            sf("%s%s", in1, in2);
            s = in1[ 0 ] - 'A';
            e = in2[ 0 ] - 'A';
            BFS(s, e);
        }
        if(T > 0) puts("");
    }
}
void BFS(int sorce, int end)
{
    int i, j, tmp;
    mem( parents );
    queue < int > Q;
    bool mark[ 28 ][ 28 ];
    fo(i, 28) fo(j, 28) mark[ i ][ j ] = true;

    parents[ sorce ] = NIL;
    //mark[ sorce ] = false;
    Q.push( sorce );

    while(!Q.empty())
    {
        tmp = Q.front(); Q.pop();
        for(i = 0; i < 28; i++)
        {
            if(mark[ tmp ][ i ] && graph[ tmp ][ i ] == 1)
            {
                mark[ tmp ][ i ] = false;
                mark[ i ][ tmp ] = false;
                parents[ i ] = tmp;
                Q.push( i );
            }
        }
    }
    k = 0; mem( ans );
    print_path( sorce, end );
}
void print_path(int sorce, int end)
{
    if(parents[ end ] == NIL)
    {
        pf("%c", sorce + 'A');
        reverse(ans, ans + k);
        puts( ans );
        return;
    }

    ans[ k++ ] = end  + 'A';
   // pf("%c", parents[ end ] + 'A');
    print_path( sorce, parents[ end ]);
}

