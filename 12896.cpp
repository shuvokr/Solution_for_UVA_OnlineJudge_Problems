#include <stdio.h>
#include <string.h>

int T, L, k, a[ 110 ], b[ 110 ];
char mobile[ 10 ][ 5 ], out[ 410 ];

int main()
{
    strcpy(mobile[ 1 ], ".,?\"");
    strcpy(mobile[ 2 ], "abc");
    strcpy(mobile[ 3 ], "def");
    strcpy(mobile[ 4 ], "ghi");
    strcpy(mobile[ 5 ], "jkl");
    strcpy(mobile[ 6 ], "mno");
    strcpy(mobile[ 7 ], "pqrs");
    strcpy(mobile[ 8 ], "tuv");
    strcpy(mobile[ 9 ], "wxyz");
    strcpy(mobile[ 0 ], "    ");

    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d", &L); k = 0;
        for(int i = 0; i < L; i++) scanf("%d", &a[ i ]);
        for(int i = 0; i < L; i++) scanf("%d", &b[ i ]);

        for(int i = 0; i < L; i++)
        {
            out[ k++ ] = mobile[ a[ i ] ][b[i] - 1];
        }
        out[ k ] = NULL; puts( out );
    }
    return 0;
}
