#include <cstdio>
#include <cmath>

void sieve();

const int MAX = 10005;

bool mark[ MAX ];
int prime[ 1230 ], res[ MAX ];

int main()
{
    sieve();
    int n;
    while( ~scanf("%d", &n) && n ) printf("%d\n", res[ n ]);
    return 0;
}
void sieve()
{
    mark[ 2 ] = true;
    mark[ 0 ] = mark[ 1 ] = false;

    for(int i = 4; i < MAX; i += 2) mark[ i ] = false;
    for(int i = 3; i < MAX; i += 2) mark[ i ] = true;

    int srt = (int)sqrt( MAX );

    for(int i  = 3; i < srt; i += 2)
        if(mark[ i ])
            for(int j = i << 1; j < MAX; j += i) mark[ j ] = false;

    prime[ 0 ] = 2;
    int pos = 1;

    for(int i = 3; i < MAX; i += 2)
        if(mark[ i ]) prime [ pos++ ] = i;

    /*******************************************************/

    for(int i = 0; i < pos; i++)
    {
        int tmp = prime[ i ];
        res[ tmp ]++;
        for(int j = i + 1; j < pos; j++)
        {
            tmp += prime[ j ];
            if(tmp > 10000) j = pos;
            else res[ tmp ]++;
        }
    }
}
