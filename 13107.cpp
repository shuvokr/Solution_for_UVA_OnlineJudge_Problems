#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ID, ind, mark[ 26 ], len, tag;
    char in[ 100010 ], ans[ 100010 ];

    while( gets( in ) )
    {
        ID = 1; ind = 0;
        memset(mark, 0, sizeof mark);
        len = strlen( in );
        for(int i = 0; i < len; i++)
        {
            tag = in[i] - 'a';
            if(!mark[ tag ])
            {
                mark[ tag ] = ID++;

                if(mark[ tag ] < 10)
                {
                    if(mark[ tag ] == 2) mark[ tag ] = 5;
                    else if(mark[ tag ] == 5) mark[ tag ] = 2;
                    else if(mark[ tag ] == 6) mark[ tag ] = 9;
                    else if(mark[ tag ] == 9) mark[ tag ] = 6;
                }
                else
                {
                    if(mark[ tag ] == 12) mark[ tag ] = 15;
                    else if(mark[ tag ] == 15) mark[ tag ] = 12;
                    else if(mark[ tag ] == 16) mark[ tag ] = 19;
                    else if(mark[ tag ] == 19) mark[ tag ] = 16;
                    else if(mark[ tag ] == 20) mark[ tag ] = 50;
                    else if(mark[ tag ] == 21) mark[ tag ] = 51;
                    else if(mark[ tag ] == 22) mark[ tag ] = 55;
                    else if(mark[ tag ] == 23) mark[ tag ] = 53;
                    else if(mark[ tag ] == 24) mark[ tag ] = 54;
                    else if(mark[ tag ] == 25) mark[ tag ] = 52;
                    else if(mark[ tag ] == 26) mark[ tag ] = 59;
                }
                printf("%d", mark[ tag ]);
            }
            else printf("%d", mark[ tag ]);
        }
        puts("");
    }

    return 0;
}
