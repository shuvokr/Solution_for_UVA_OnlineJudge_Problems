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
void backtrack(int pos, int wait);
bool isok(int r);

int n, target, in[ 15 ], res;
int row, pres[ 100000 ][ 15 ];
int pus[ 15 ], inde;

int main()
{
    input();

    return 0;
}
void input()
{
    while(sf("%d %d", &target, &n) && (target || n))
    {
        for(int i = 0; i < n; i++) sf("%d", &in[ i ]);
        inde = row = 0; res = 0;
        backtrack(0, 0);
        pf("Sums of %d:\n", target);
        if( !row ) puts("NONE");
        else
        {
            for(int i = row - 1; i > -1; i--)
            {
                pf("%d", pres[ i ][ 0 ]);
                int k = 1;
                while(pres[ i ][ k ] != -1)
                    pf("+%d", pres[ i ][ k++ ]);
                puts("");
            }
        }
    }
}
void backtrack(int pos, int wait)
{
    if(pos > n) return;
    if(wait > target) return;
    if(wait == target)
    {
        res++; pus[ inde ] = -1;
        if(isok(row - 1))
        {
            for(int i = 0; i < inde; i++) pres[ row ][ i ] = pus[ i ];
            pres[ row ][ inde ] = -1; row++;
        }
        return;
    }

    backtrack(pos + 1, wait);
    pus[ inde ] = in[ pos ]; inde++;
    backtrack(pos + 1, wait + in[ pos ]);
    inde--;
}
bool isok(int r)
{
    if(r < 0) return true;
    bool mark;
    for(; r >= 0; r--)
    {
        mark = false;
        for(int i = 0; pus[ i ] != -1; i++)
        {
            if(!mark)
                if(pus[ i ] != pres[ r ][ i ]) mark = true;
        }
        if(pres[ r ][ inde ] == -1 && !mark) return false;
    }
    return true;
}
