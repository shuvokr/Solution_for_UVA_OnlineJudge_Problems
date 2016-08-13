/*********************************************

    Shuvo
    Problem name : Rank the Languages
    Problem ID   : 10336
    Problem algo : Graph ( DFS )
    Note         : Empty

**********************************************/

#include <stdio.h>
#include <string.h>
using namespace std;
void DFS(int i, int j);
bool isok(int i, int j);
bool vis[ 1010 ][ 1010 ], mark[ 124 ];
char graph[ 1010 ][ 1010 ], ch;
int row, col, res[ 124 ], link[ 30 ];
int diraction1[] = {-1, 0, 0, 1};
int diraction2[] = {0, -1, 1, 0};
int main()
{
    int T, i, j, kag = 0, k, tmp;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d %d", &row, &col); getchar();
        for(i = 0; i < row; i++)
        {
            gets( graph[ i ] );
            for(j = 0; j < col; j++) vis[ i ][ j ] = true;
        }
        for(i = 97; i < 123; i++) res[ i ] = 0, mark[ i ] = true;
        k = 0;
        for(i = 0; i < row; i++)
            for(j = 0; j < col; j++)
            {
                if(vis[ i ][ j ])
                {
                    ch = graph[ i ][ j ];
                    res[ ch ]++;
                    if( mark[ ch ] )
                    {
                        mark[ ch ] = false;
                        link[ k++ ] = ch;
                    }
                    DFS(i, j);
                }
            }
        printf("World #%d\n", ++kag);

        for(i = 0; i < k - 1; i++)
            for(j = i; j < k; j++)
            {
                if( res[ link[ i ] ] < res[ link[ j ] ] )
                {
                    tmp = link[ i ];
                    link[ i ] = link[ j ];
                    link[ j ] = tmp;
                }
                else if( res[ link[ i ] ] == res[ link[ j ] ] )
                {
                    if(link[ i ] > link[ j ])
                    {
                        tmp = link[ i ];
                        link[ i ] = link[ j ];
                        link[ j ] = tmp;
                    }
                }
            }

        for(i = 0; i < k; i++)
                printf("%c: %d\n", link[ i ], res[ link[ i ] ]);
    }
    return 0;
}
void DFS(int i, int j)
{
    vis[ i ][ j ] = false;
    for(int k = 0; k < 4; k++)
    {
        int a = i + diraction1[ k ], b = j + diraction2[ k ];
        if(vis[ a ][ b ]) if( isok(a, b) ) DFS(a, b);
    }
}
bool isok(int i, int j)
{
    if(i < 0 || i >= row || j < 0 || j >= col || graph[ i ][ j ] != ch) return false;
    return true;
}
