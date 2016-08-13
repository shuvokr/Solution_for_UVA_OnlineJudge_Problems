#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

void make_res();
void find_max();

char in[ 10000 ], in2[ 10000 ], c, cc, cou, res[ 10000 ], garbaj[ 10 ];
int len, fin[ 124 ], fin2[ 124 ], len2, maxx, maxc;

int main()
{
    int T, i, j, tmp;
    bool mark = false;
    scanf("%d", &T);
    gets(garbaj);
    while(T--)
    {
        if(mark) puts("");
        else mark = true;

        gets(garbaj);
        gets( in ); gets( in2 );

        for(i = 65; i < 91; i++)
        {
            fin[ i ] = 0;
            fin2[ i ] = 0;
        }
        for(i = 97; i < 123; i++)
        {
            fin[ i ] = 0;
            fin2[ i ] = 0;
        }
        len = strlen( in );
        for(i = 0; i < len; i++)
        {
            fin[ in[ i ] ]++;
        }
        len2 = strlen( in2 );
        for(i = 0; i < len2; i++)
        {
            fin2[ in2[ i ] ]++;
        }

        //printf("  %d %d\n", len, len2);

        maxx =  maxc = cou = 0;
        find_max();
        while(maxx && maxc)
        {
            make_res();
            maxx =  maxc = 0;
            find_max();
        }
        puts( res );
        memset(res, 0, 10000);
    }
    return 0;
}
void make_res()
{
    int i = 0;
    while(in2[ i ] != cc)
    {
        i++;
    }
    while(in2[ i ] == cc)
    {
        res[ i ] = c;
        i++;
    }
}
void find_max()
{
    int i;
    for(i = 0; i < len; i++)
        if(maxx < fin[ in[ i ] ]) maxx = fin[ in[ i ] ], c = in[ i ];
    for(i = 0; i < len2; i++)
        if(maxc < fin2[ in2[ i ] ]) maxc = fin2[ in2[ i ] ], cc = in2[ i ];
    fin[ c ] = fin2[ cc ] = 0;
}
