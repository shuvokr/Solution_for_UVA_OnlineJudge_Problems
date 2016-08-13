#include <stdio.h>
#include <string.h>

using namespace std;

void backtracking(int r);
bool isposible(int i, int j);
bool isok(int a, int b);

int col[ 8 ], chess[ 8 ][ 8 ], T, res, mark[ 8 ][ 8 ];

int main()
{
    freopen("input.txt", "r", stdin);
    int n, i, j;
    for(i = 0; i < 8; i++) for(j = 0; j < 8; j++) mark[ i ][ j ] = 0;
    scanf("%d", &T);
    while( T-- )
    {
        for(i = 0; i < 8; i++)
            for(j = 0; j < 8; j++) scanf("%d", &chess[ i ][ j ]);
        res = -1;
        backtracking( 0 );
        printf("%5d\n", res);
    }
    return 0;
}
void backtracking(int r)
{
    if(r == 8)
    {
        int sum = 0;
        for(int k = 0; k < 8; k++) sum += chess[ k ][ col[ k ] ];
        res = res < sum ? sum : res;
    }
    else
    {
        for(int i = 0; i < 8; i++)
        {
            if( isposible(r, i) )
            {
                mark[ r ][ i ] = 1;
                col[ r ] = i;
                backtracking(r + 1);
                mark[ r ][ i ] = 0;
            }
        }
    }
}
bool isposible(int i, int j)
{
    int a = i, b = j;
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
    for(int k = 0; k < 8; k++) if(mark[ i ][ k ]) return false;
    for(int k = 0; k < 8; k++) if(mark[ k ][ j ]) return false;
    return true;
}
bool isok(int a, int b)
{
    if(a < 0 || a > 7 || b < 0 || b > 7) return false;
    return true;
}
