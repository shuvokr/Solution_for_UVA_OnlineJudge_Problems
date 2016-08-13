#include <stdio.h>
#include <string.h>
#include <ctype.h>

using namespace std;

char graph[ 63 ][ 63 ], instraction[ 10000 ];

int main()
{
    freopen("input.txt", "r", stdin);
    int T, len, row, col, i, j, r, c, R, L, dik;
    bool mark, space = false;
    scanf("%d", &T);
    while( T-- )
    {
        if( space ) puts("");
        else space = true;
        scanf("%d %d", &row, &col); getchar();
        for(i = 0; i < row; i++) gets( graph[ i ] );
        scanf("%d %d", &r, &c); R = L = 12;
        r--; c--; getchar(); mark = false; dik = 12;
        while( gets( instraction ) )
        {
            if(mark) break;
            len = strlen( instraction );
            for(i = 0; i < len; i++)
            {
                if( isupper(instraction[ i ]) )
                {
                    if(instraction[ i ] == 'R')
                    {
                        R = R == 12 ? 3 : R == 3 ? 6 : R == 6 ? 9 : 12;
                        L = dik = R;
                    }
                    else if(instraction[ i ] == 'L')
                    {
                        L = L == 12 ? 9 : L == 9 ? 6 : L == 6 ? 3 : 12;
                        R = dik = L;
                    }
                    else if(instraction[ i ] == 'F')
                        dik == 12 ? graph[r - 1][ c ] != '*' ? r-- : r : dik == 3 ? graph[ r ][c + 1] != '*' ? c++ : c : dik == 6 ? graph[r + 1][ c ] != '*' ? r++ : r : graph[ r ][c - 1] != '*' ? c-- : c;
                    else i = len, mark = true;
                }
            }
        }
        printf("%d %d ", r + 1, c + 1);
        puts(dik == 12 ? "N" : dik == 3 ? "E" : dik == 6 ? "S" : "W");
    }
    return 0;
}
