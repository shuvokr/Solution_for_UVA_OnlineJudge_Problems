#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <stack>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define lu unsigned long int
#define llu unsigned long long int
#define lld long long int
#define sf scanf
#define pf printf
#define fo(i, n) for(i = 0; i < n; i++)
#define mem(n) memset(n, -1, sizeof(n))

void input();
void BFS(int fst, int snd);

int i, j, row, col, pos, mark[ 12 ][ 12 ], cou, lop;
char in[ 12 ][ 12 ], ch;

int main()
{
    input();

    return 0;
}
void input()
{
    int res;
    while(sf("%d %d %d", &row, &col, &pos) != EOF)
    {
        if(!row && !col && !pos) break;
        getchar(); lop = -1;
        fo(i, row) gets(in[ i ]);
        fo(i, row) fo(j, col) mark[ i ][ j ] = -1;
        pos--; BFS(0, pos);
        if(lop == -1) pf("%d step(s) to exit\n", cou);
        else pf("%d step(s) before a loop of %d step(s)\n", lop, cou);
    }
}
void BFS(int fst, int snd)
{
    int tmp1, tmp2, ck; cou = 0;
    queue < int > Q;
    bool chk = true;
    Q.push( fst ); Q.push( snd );
    while(chk)
    {
        tmp1 = Q.front(); Q.pop();
        tmp2 = Q.front(); Q.pop();

        mark[ tmp1 ][ tmp2 ] = cou++;
        ch = in[ tmp1 ][ tmp2 ];

        if(ch == 'W') fst = tmp1, snd = tmp2 - 1;
        else if(ch == 'E') fst = tmp1, snd = tmp2 + 1;
        else if(ch == 'N') fst = tmp1 - 1, snd = tmp2;
        else if(ch == 'S') fst = tmp1 + 1, snd = tmp2;

        if(fst == row || fst < 0 || snd == col || snd < 0)
        {
            chk = false;
        }
        else if(mark[ fst ][ snd ] != -1)
        {
            chk = false;
            cou -= mark[ fst ][ snd ];
            lop = mark[ fst ][ snd ];
        }
        Q.push( fst ); Q.push( snd );
    }
}

