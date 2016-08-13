#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int DP(int s, int e);
int mamo[ 1010 ][ 1010 ];
char in[ 1010 ];

int main()
{
    int T, kag = 0;
    scanf("%d", &T); getchar();
    while ( T-- )
    {
        gets( in ); memset(mamo, -1, sizeof mamo);
        printf("Case %d: %d\n", ++kag, DP(0, strlen( in ) - 1));
    }
    return 0;
}
int DP(int s, int e)
{
    if(s >= e) return 0;
    if(mamo[ s ][ e ] != -1) return mamo[ s ][ e ];
    int ret;
    if(in[ s ] == in[ e ]) ret = DP(s + 1, e - 1);
    else ret = min(1 + DP(s + 1, e - 1), min(1 + DP(s + 1, e), 1 + DP(s, e - 1)));
    return mamo[ s ][ e ] = ret;
}
