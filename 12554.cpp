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

int main()
{
    char c[ 16 ][ 13 ];
    strcpy(c[ 0 ], ": Happy");
    strcpy(c[ 1 ], ": birthday");
    strcpy(c[ 2 ], ": to");
    strcpy(c[ 3 ], ": you");
    strcpy(c[ 4 ], ": Happy");
    strcpy(c[ 5 ], ": birthday");
    strcpy(c[ 6 ], ": to");
    strcpy(c[ 7 ], ": you");
    strcpy(c[ 8 ], ": Happy");
    strcpy(c[ 9 ], ": birthday");
    strcpy(c[ 10 ], ": to");
    strcpy(c[ 11 ], ": Rujia");
    strcpy(c[ 12 ], ": Happy");
    strcpy(c[ 13 ], ": birthday");
    strcpy(c[ 14 ], ": to");
    strcpy(c[ 15 ], ": you");

    int n, i, j, k;
    char in[ 101 ][ 101 ];
    while(scanf("%d", &n) != EOF)
    {
        getchar();
        for(i = 0; i < n; i++) gets( in[ i ] );
        if(n < 17)
        {
            k = 0;
            for(i = 0; i < 16; i++)
            {
                printf("%s", in[ k++ ]);
                if(k == n) k = 0;
                puts( c[ i ] );
            }
            continue;
        }

        if(n < 33)
        {
            k = 0; j = 0;
            for(i = 0; i < 32; i++)
            {
                printf("%s", in[ k++ ]);
                if(k == n) k = 0;
                puts( c[ j++ ] );
                if(j == 16) j = 0;
            }
            continue;
        }

        if(n < 49)
        {
            k = 0; j = 0;
            for(i = 0; i < 48; i++)
            {
                printf("%s", in[ k++ ]);
                if(k == n) k = 0;
                puts( c[ j++ ] );
                if(j == 16) j = 0;
            }
            continue;
        }

        if(n < 65)
        {
            k = 0; j = 0;
            for(i = 0; i < 64; i++)
            {
                printf("%s", in[ k++ ]);
                if(k == n) k = 0;
                puts( c[ j++ ] );
                if(j == 16) j = 0;
            }
            continue;
        }

        if(n < 81)
        {
            k = 0; j = 0;
            for(i = 0; i < 80; i++)
            {
                printf("%s", in[ k++ ]);
                if(k == n) k = 0;
                puts( c[ j++ ] );
                if(j == 16) j = 0;
            }
            continue;
        }

        if(n < 97)
        {
            k = 0; j = 0;
            for(i = 0; i < 96; i++)
            {
                printf("%s", in[ k++ ]);
                if(k == n) k = 0;
                puts( c[ j++ ] );
                if(j == 16) j = 0;
            }
            continue;
        }

        k = 0; j = 0;
        for(i = 0; i < 112; i++)
        {
            printf("%s", in[ k++ ]);
            if(k == n) k = 0;
            puts( c[ j++ ] );
            if(j == 16) j = 0;
        }
    }

    return 0;
}
