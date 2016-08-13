#include <stdio.h>
#include <string.h>

int DP(int now, int last);

int mamo[ 1010 ][ 2010 ], N;
bool res[ 1001 ];

int main()
{
    memset(mamo, -1, sizeof mamo);
    for(int i = 2; i < 1001; i++)
        res[ i ] = DP(i, i - 1);

    while(scanf("%d", &N) && N)
    {
        puts(res[ N ] ? "Alicia" : "Roberto");
    }
    return 0;
}
int DP(int now, int last)
{
    if(now == 0) return 0;
    if(now < 0) return 1;

    int &ret = mamo[ now ][ last ];
    if(ret != -1) return ret;

    for(int i = 1; i <= last; i++)
        if(DP(now - i, i + i) == 0) return ret = 1;

    return ret = 0;
}

