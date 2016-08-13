#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int i, len, k;
    char in[ 1000 ], rev[ 3 ], n[ 1000 ];
    while(gets( n ))
    {
        len = strlen( n );

        memset(in, 0, 1000); k = 0;
        for(i = len - 1; i > -1; i--)
            in[ k++ ] = n[ i ];

        for(i = 0; i < len; i++)
        {
            if(!isdigit(in [ i ]))
            {
                k = in[ i ];
                while(k)
                {
                    printf("%d", k % 10);
                    k /= 10;
                }
            }
            else
            {
                rev[ 0 ] = rev[ 1 ] = rev[ 2 ] = 0;
                rev[ 0 ] = in[ i++ ];
                rev[ 1 ] = in[ i++ ];
                k = atoi( rev );
                if(k > 31)
                {
                    printf("%c", k);
                }
                else
                {
                    rev[ 2 ] = in[ i++ ];
                    k = atoi( rev );
                    printf("%c", k);
                }
                i--;
            }
        }
        puts("");
    }
    return 0;
}
