#include <stdio.h>
int main()
{
    int i, n, m, ti, dp[ 10010 ];
    while(~scanf("%d %d %d", &n, &m, &ti))
    {
        dp[ 0 ] = 0;
        i = n;
        n = n < m ? n : m;
        m = i < m ? m : i;
        for(i = 1; i <= ti; i++)
        {
            dp[ i ] = -1;
            if(i >= n && dp[i - n] != -1) dp[ i ] = 1 + dp[i - n];
            if(i >= m && dp[i - m] != -1) dp[ i ] = 1 + dp[i - m] > dp[ i ] ? 1 + dp[i - m] : dp[ i ];
        }
        if(dp[ ti ] != -1) printf("%d\n", dp[ ti ]);
        else for(i = ti;;i--)
                if(dp[ i ] != -1) {printf("%d %d\n", dp[ i ], ti - i ); break;}
    }
    return 0;
}
