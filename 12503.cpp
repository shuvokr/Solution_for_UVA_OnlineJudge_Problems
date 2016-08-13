#include <stdio.h>
#include <string.h>
#include <ctype.h>

using namespace std;

int main()
{
    int T, n, cou, i, j, k;
    char in[ 100 ][ 15 ], c[ 15 ];
    scanf("%d", &T);
    while(T--)
    {
        cou = 0;
        memset(in, 0, sizeof( in ));
        scanf("%d", &n); getchar();
        for(i = 0; i < n; i++)
        {
            gets( in[ i ] );
            if(strcmp(in[ i ], "LEFT") == 0) cou--;
            else if(strcmp(in[ i ], "RIGHT") == 0) cou++;
            else
            {
                j = 8; k = 0;
                memset(c, 0, sizeof( c ));
                while(isdigit(in[ i ][ j ]))
                {
                    c[ k++ ] = in[ i ][ j++ ];
                }
                sscanf(c, "%d", &k);
                k--;
                strcpy(in[ i ], in[ k ]);
                if(strcmp(in[ k ], "LEFT") == 0) cou--;
                else cou++;
            }
        }
        printf("%d\n", cou);
    }
    return 0;
}

