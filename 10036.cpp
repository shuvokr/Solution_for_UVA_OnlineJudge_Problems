/*******************************************************
    Shuvo
    Problem algo: normal DP
********************************************************/
#include <stdio.h>
#include <string.h>
int dp(int pos, int mod);
int n, value[ 10010 ], k, mamo[ 10010 ][ 110 ];
int main()
{
    freopen("input.txt", "r", stdin);
    int T, i, j;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d %d",&n, &k);
        for(i = 0; i < n; i++) scanf("%d", value + i);
        memset(mamo, -1, sizeof mamo);
        puts( dp(1, value[ 0 ] % k) ? "Divisible" : "Not divisible" );
    }
    return 0;
}
int dp(int pos, int mod)
{
    if(pos == n)
    {
        if( !mod ) return 1;
        return 0;
    }
    else if(mamo[ pos ][ mod ] != -1) return mamo[ pos ][ mod ];
    else return mamo[ pos ][ mod ] = dp(pos + 1, (mod + ((value[ pos ]) % k)) % k) || dp(pos + 1, (mod + (-1 * (value[ pos ]) % k)) % k);
}
