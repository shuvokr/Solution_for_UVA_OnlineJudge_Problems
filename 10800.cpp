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

void input();
void make_graph();
void print_graph();

char graph[ 102 ][ 55 ], in[ 55 ];
int minX, maxY, currentX;

int main()
{
    input();

    return 0;
}
void input()
{
    int T, i, j, k, tmp, kag = 0;
    sf("%d", &T); getchar();
    while(T--)
    {
        mem(in);
        gets( in );
        mem( graph );

        for(i = 0; i < 102; i++)
        {
            strcpy( graph[ i ], "|                                                   ");
            graph[ i ][ 52 ] = '\0';
        }

        minX = maxY = currentX = 50;
        pf("Case #%d:\n", ++kag);
        make_graph();
        print_graph();

        puts("");
    }
}
void make_graph()
{
    minX = 50; maxY = 50; int i;
    currentX =50;
    bool mark = false;
    //pf("%d\n", strlen(in));
    for(i = 0; i < strlen( in ); i++)
    {
        if( in[ i ] == 'C' )
        {
            mark = true;
            graph[ currentX ][ i+2 ] = '_';
            maxY = max(maxY, currentX);
            minX = min(minX, currentX);
        }
        else if( in[ i ] == 'F' )
        {
            if( mark ) currentX++;
            graph[ currentX ][ i+2 ] = '\\';
            maxY = max(maxY, currentX);
            mark = true;
        }
        else if( in[ i ] == 'R' )
        {
            //if( mark )
            graph[ currentX ][ i+2 ] = '/';
            minX = min(minX, currentX);
            mark = true;
            currentX--;
        }
    }
}
void print_graph()
{
    //pf("%d %d\n", minX, maxY);
    int i, j;
    for(i = minX; i <= maxY; i++)
     {
         for(j = 52; j >= 0; j--)
            if(graph[ i ][ j ] == '_' || graph[ i ][j ] == '/' || graph[ i ][ j ] == '\\')
            {
                graph[ i ][ j+1 ] = '\0';
                break;
            }
            cout << graph[i] << endl;
     }
     pf("+-");
     for(i = 0; i <= strlen( in ); i++) pf("-");
     puts("");
}

