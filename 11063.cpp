#include <stdio.h>
#include <map>

using namespace std;

int main()
{
    int n, i, j, tmp, kag = 0;
    bool mark = true;
    while(scanf("%d", &n) != EOF)
    {
        mark = true;
        int in[ 102 ];
        for(i = 0; i < n; i++) scanf("%d", &in[ i ]);
        for(i = 0; i < n - 1; i++)
            if(in[ i ] > in[ i + 1 ] || in[ i ] < 1) {mark = false; i = n;}
        if( mark )
        {
            map <int, int> c;
            c.clear();

            for(i = 0; i < n; i++)
            {
                for(j = i; j < n; j++)
                {
                    if( c[ in[ i ] + in[ j ] ] == 1 )
                    {
                        mark = false;
                        i =  n;
                        j = n;
                    }
                    else c[ in[ i ] + in[ j ] ] = 1;
                }
            }

            if( mark ) printf("Case #%d: It is a B2-Sequence.\n\n", ++kag);
            else printf("Case #%d: It is not a B2-Sequence.\n\n", ++kag);
        }
        else printf("Case #%d: It is not a B2-Sequence.\n\n", ++kag);
    }
    return 0;
}

