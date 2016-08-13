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
bool chaking(char a[], char b[]);
void BFS(int sorce, int end);

char inpu[ 202 ][ 12 ];
int in[ 202 ][ 202 ], cou, cost[ 201 ];

int main()
{
    input();

    return 0;
}
void input()
{
    int T, i, j;
    char from[ 12 ], to[ 12 ], tot[30];
    map <string, int> m;
    bool cheak;
    sf("%d", &T);
    getchar(); getchar();
    while(T--)
    {
        cou = -1;
        while(gets(inpu[++cou]))
        {
            if(inpu[ cou ][ 0 ] == '*') break;
            m[ inpu[ cou ] ] = cou;
        }
        //puts("ok");
        mem( in ); cheak = true;
        for(i = 0; i < cou - 1; i++)
        {
            for(j = i + 1; j < cou; j++)
            {
                cheak = chaking(inpu[ i ], inpu[ j ]);
                if(cheak)
                {
                    in[ m[ inpu[i] ] ][ m[ inpu[j] ] ] = 1;
                    in[ m[ inpu[j] ] ][ m[ inpu[i] ] ] = 1;
                }
            }
        }

        while(gets(tot))
        {
            if(tot[ 0 ] == 0) break;
            int len = strlen( tot ); mem( from ); mem( to );
            int k = 0;
            fo(i, len)
            {
                if(tot[ i ] == ' ') break;
                from[k++] = tot[ i ];
            }
            k = 0;
            for(j = i + 1; j < len; j++) to[ k++ ] = tot[ j ];
           // puts(from); puts(to); pf("......\n");
            i = m[ from ];
            j = m [ to ];
            pf("%s %s ", from, to);
            BFS(i, j);
        }
        if(T > 0) puts("");
    }
}
bool chaking(char a[], char b[])
{
    int i, j, len1, len2, count = 0, len;
    len1 = strlen(a); len2 = strlen(b);
    if(len1 > len2 + 1 || len2 > len1 + 1) return false;
    if(len1 == len1)
    fo(i, len1)
    {
        if(a[ i ] == b[ i ]) count++;
    }
    if(count == len1 - 1) return true;

    len = min(len1, len2);
    count = 0;
    fo(i, len) if(a[ i ] == b[ i ]) count++;
    if(count == len) return true;

    return false;
}
void BFS(int sorce, int end)
{
    int i, j, tmp1;
    fo(i, 201) cost[ i ] = -1;
    bool mark[202];
    fo(i, 201) mark[ i ] = true;
    queue < int > Q;
    Q.push( sorce );
    cost[ sorce ] = 0;
    mark[ sorce ] = false;
    while(!Q.empty())
    {
        tmp1 = Q.front(); Q.pop();
        fo(i, cou)
        {
            if(in[ tmp1 ][ i ] == 1 && mark[ i ])
            {
                mark[ i ] = false;
                cost[ i ] = cost[ tmp1 ] + 1;
                Q.push( i );
            }
        }
    }
    pf("%d\n", cost[ end ]);
}

