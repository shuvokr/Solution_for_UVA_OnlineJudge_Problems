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

void input();
void BFS(int sorce);

int Node;
 bool graph[ 2501 ][ 2501 ];

int main()
{
    input();

    return 0;
}
void input()
{
    int i, j, temp;
    fo(i, 2501) fo(j, 2501) graph[ i ][ j ] = false;
    sf("%d", &Node);
    fo(i, Node)
    {
        int num;
        sf("%d", &num);
        while(num--) sf("%d", &temp), graph[ i ][ temp ] = true;
    }

    int T, src;
    sf("%d", &T);
    while(T--)
    {
        sf("%d", &src);
        BFS(src);
    }
}
void BFS(int sorce)
{
    int cost[ 2501 ], i, j, tmp, res[ 2501 ];
    fo(i, 2501) res[ i ] = 0;
    bool mark[ 2501 ];
    fo(i, 2501) cost[ i ] = -1;
    fo(i, 2501) mark[ i ] = true;
    queue < int > Q;
    Q.push( sorce ); cost[ sorce ] = 0; mark[ sorce ] = false;

    while(!Q.empty())
    {
        tmp = Q.front(); Q.pop();
        fo(i, Node)
        {
            if(graph[ tmp ][ i ] && cost[ i ] == -1)
            {
                cost[ i ] = cost[ tmp ] + 1;
                res[ cost[ i ] ]++;
                Q.push( i );
            }
        }
    }
    //fo(i, Node) pf("%d ", cost[ i ]);
    int max = 0, sk = 0;
    fo(i, Node)
    {
        if(res[ i ] > max) max = res[ i ], sk = i;
    }
    if(max == 0) puts("0");
    else pf("%d %d\n", max, sk);
}

