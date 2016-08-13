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
#define maxn 8+2

int diraction1[] = {1, -1, 0, 0, 1, -1, -1, 1};
int diraction2[] = {0, 0, -1, 1, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

//**********************************************************************
void input();
void DFS( int x, int y, int po);

map <int, string> m;
char graph[ maxn ][ maxn ], path[ 11 ];
int row, col, cou, last, pos, kk;
bool mark[ maxn ][ maxn ], foundhas;
stack <int> res;

int main()
{
    strcpy(path, "IEHOVA#");
    m[ 0 ] = "forth";
    m[ 1 ] = "forth";
    m[ 2 ] = "left";
    m[ 3 ] = "right";

    input();

    return 0;
}
void input()
{
    int i, j, r, c, T;
    sf("%d", &T);
    while(T--)
    {
        sf("%d %d", &row, &col);
        //Reset all**************************
        getchar(); mem(graph, 0);
        foundhas = false;
        fo(i, row) gets(graph[ i ]); // scan input
        pos = cou = 0;
        kk = 6; mem(mark, true);
        //***********************************

        fo(i, row) // In this part for call DFS function
        {
            fo(j, col)
            {
                if(graph[ i ][ j ] == '@')
                {
                    DFS(i, j, 0);
                    i = row, j = col;
                }
            }
        }

        // print result start**************************
        cout << m[res.top()];
        res.pop();
        while(!res.empty())
        {
            cout << " " << m[res.top()]; res.pop();
        }
        puts("");
        // result print end******************************
    }
}
void DFS( int x, int y, int po)
{
    //int po is the position of path[] =  "IEHOVA#", i mean (if po = 0, its I, if po = 1 its E.....)
    if(graph[ x ][ y ] == '#') foundhas = true; // when found # then foundhas is true else false
    int j = 0, i;
    for(i = 1; i < 4; i++)
    {
        int a, b;
        a = x + diraction1[ i ];
        b = y + diraction2[ i ];
        if(graph[ a ][ b ] == path[ po ] && mark[ a ][ b ])
        {
            mark[ a ][ b ] = false; // This path is visited
            DFS(a, b, po + 1);
            if(graph[ a ][ b ] == path[ kk ] && kk >= 0) // here feast path[kk] = "#", cause when we found
                                                         // # then we save result up to I. # >> A >> V >> O >> H >> E >> I
            {
                res.push( i );
                kk--;
            }
            if(foundhas) i = 4; // If i found # then when its return that time not need to sarch anythings in grid
                                // cause # is our Dastination
        }
    }
}
// If any where is wrong please say me why, For this code give me tha right answer, but i dont subbmit this code cause uva problem is not open.
