#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

void backtracking(int r);
bool isposible(int i, int j);
bool isok(int a, int b);
int x, y;
int chess[ 9 ][ 9 ], col[ 9 ], mark[ 9 ][ 9 ], cou;

struct data
{
    int colum[ 8 ];
}res[ 105 ];

void laxosort();

int main()
{
    //freopen("input.txt", "r", stdin);
    bool space = false;
    int i, j, tmp, T, a, b, kag = 0;
    for(i = 1; i < 9; i++) for(j = 1; j < 9; j++) mark[ i ][ j ] = 0;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d %d", &x, &y);
        if( space ) puts("");
        else space = true;
        mark[ x ][ y ] = 1;
        col[ y ] = x; cou = 0;
        backtracking( 1 );
        mark[ x ][ y ] = 0;
        laxosort();
        puts("SOLN       COLUMN");
        puts(" #      1 2 3 4 5 6 7 8"); puts("");
        kag = 0;
        for(i = 0; i < cou; i++)
        {
            printf("%2d     ", ++kag);
            for(j = 0; j < 8; j++) printf(" %d", res[ i ].colum[ j ]);
            puts("");
        }
    }
    return 0;
}
void backtracking(int r)
{
    if(r == 9)
    {
        for(int i = 0; i < 8; i++) res[cou].colum[ i ] = col[i + 1];
        cou++;

            /*printf("%d ", col[ i ]);
        puts("");*/
    }
    else
    {
        if(r == x) backtracking(r + 1);
        else
        for(int c = 1; c < 9; c++)
        {
            if(c != y)
            {
                if( isposible(r, c) )
                {
                    mark[ r ][ c ] = 1;
                    col[ c ] = r;
                    backtracking(r + 1);
                    mark[ r ][ c ] = 0;
                }
            }
        }
    }
}
bool isposible(int i, int j)
{
    int a, b;
    a = i, b = j;
    while( isok(a, b) )
    {
        if(mark[ a ][ b ]) return false;
        a++, b++;
    }
    a = i, b = j;
    while( isok(a, b) )
    {
        if(mark[ a ][ b ]) return false;
        a--, b--;
    }
    a = i, b = j;
    while( isok(a, b) )
    {
        if(mark[ a ][ b ]) return false;
        a++, b--;
    }
    a = i, b = j;
    while( isok(a, b) )
    {
        if(mark[ a ][ b ]) return false;
        a--, b++;
    }
    for(int k = 1; k < 9; k++) if(mark[ i ][ k ]) return false;
    for(int k = 1; k < 9; k++) if(mark[ k ][ j ]) return false;
    return true;
}
bool isok(int a, int b)
{
    if(a < 1 || a > 8 || b < 1 || b > 8) return false;
    return true;
}
void laxosort()
{
    data tmp;
    for(int i = 0; i < cou - 1; i++)
    {
        for(int j = i + 1; j < cou; j++)
        {
            for(int k = 0; k < 8; k++)
            {
                if(res[i].colum[ k ] < res[j].colum[ k ]) k = 8;
                else if(res[i].colum[ k ] == res[j].colum[k]) continue;
                else
                {
                    tmp = res[ i ];
                    res[ i ] = res[ j ];
                    res[ j ] = tmp;
                    k = 8;
                }
            }
        }
    }
}
