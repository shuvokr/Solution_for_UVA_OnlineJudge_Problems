#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    char in[ 100 ], tmp[ 100 ], match[ 100 ];
    int len, res, t, T;
    bool space = false;
    scanf("%d", &T);
    while( T-- )
    {
        if(space) puts("");
        else space = true;
        scanf("%s", in);
        res = strlen( in ); t = res;
        len = res >> 1; len++;
        for(int i = 0; i < len; i++)
        {
            if(!(t % (i + 1)))
            {
                int k = 0;
                for(int j = 0; j <= i; j++) match[ k++ ] = in[ j ]; match[ k ] = NULL;
                //printf("%d\n", k);
                int last = 0, cou = 0;
                for(int j = k - 1; j < t; j += k)
                {
                    int p = 0;
                    for(int ii = last; ii <= j; ii++) tmp[ p++ ] = in[ ii ]; tmp[ p ] = NULL;
                    if(strcmp(match, tmp) == 0) cou++;
                    last = j + 1;
                }
                if(cou == t / (i + 1))
                {
                    res = i + 1;
                    i = len;
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
