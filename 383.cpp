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

void input();
void BFS(int sorce);

int node, edge, p;
int graph[ 32 ][ 32 ];
int cost[ 440 ];

int main()
{
    input();

    return 0;
}
void input()
{
    int T, i, j, cou, k, taka, S, E, kag = 0;
    char in[ 3 ] , ch[ 3 ];
    bool mark = true;
    map < string, int > m;
    sf("%d", &T);
    while(T--)
    {
        if( mark )
        {
            puts("SHIPPING ROUTES OUTPUT");
            puts("");
            mark = false;
        }
        pf("DATA SET  %d\n\n", ++kag);
        mem(graph, 0);
        sf("%d%d%d", &node, &edge, &p);
        cou = 0;
        fo(i, node)
        {
            mem(ch, 0);
            sf("%s", ch);
            m[ ch ] = i;
        }
        fo(i, edge)
        {
            mem(in, 0); mem(ch, 0);
            sf("%s%s", in, ch);
            graph[ m[ in ] ][ m[ ch ] ] = 1;
            graph[ m[ ch ] ][ m[ in ] ] = 1;
        }
        fo(k, p)
        {
            sf("%d %s%s", &taka, in, ch);
            S = m[ in ];
            E = m [ ch ];
            fo(i, 440) cost[ i ] = 500;
            BFS( S );

            if(cost[ E ] == 500) puts("NO SHIPMENT POSSIBLE");
            else pf("$%d\n", cost[ E ] * 100 * taka);
        }
        puts("");
        if(T == 0) puts("END OF OUTPUT");
    }
}
void BFS(int sorce)
{
    int i, j, tmp;
    queue < int > Q;
    bool mark[ 32 ][ 32 ];
    fo(i, 32) fo(j , 32) mark[ i ][ j ] = true;
    cost[ sorce ] = 0;
    Q.push( sorce );

    while(!Q.empty())
    {
        tmp = Q.front(); Q.pop();
        fo(i, 31)
        {
            if(graph[ tmp ][ i ] == 1 && mark[ tmp ][ i ])
            {
                mark[ tmp ][ i ] = false;
                mark[ i ][ tmp ] = false;
                if(cost[ i ] == 500)
                    cost[ i ] = cost[ tmp ] + 1;
                Q.push( i );
            }
        }
    }
}

