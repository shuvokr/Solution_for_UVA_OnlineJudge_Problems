#include <stdio.h>
int main()
{
    int T,N,H[10000],W,i,j,kag=0,dp[10000],dp1[10000],A,B;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        for(i = 0;i<N;++i) scanf("%d",&H[i]);
        A = B = 0;
        for(i = 0;i<N;++i)
        {
            scanf("%d",&W);
            dp[i] = dp1[i] = W;
            for(j = 0;j<i;++j)
            {
                dp[i]=H[j]<H[i] && W+dp[j]>dp[i]?W+dp[j]:dp[i];
                dp1[i]=H[j]>H[i] && W+dp1[j]>dp1[i]?W+dp1[j]:dp1[i];
            }
            A=dp[i]>dp[A]?i:A;
            B=dp1[i]>dp1[B]?i:B;
        }
        A = dp[A]; B=dp1[B];
        if(A>=B) printf("Case %d. Increasing (%d). Decreasing (%d).\n",++kag,A,B);
        else printf("Case %d. Decreasing (%d). Increasing (%d).\n",++kag,B,A);
    }
    return 0;
}
