#include <stdio.h>
long long int memo[ 55 ][ 55 ];
int n, k, m;
long long ways(int v, int i)
{
    int j = 0; long long int ans=0;
    if(i == k && v == n) return 1;
    if(v > n || i > k) return 0;
    if(memo[ v ][ i ] != -1) return memo[ v ][ i ];
    for(j = 1; j <= m; j++)
        ans += ways(v + j, i + 1);
    return memo[ v ][ i ] = ans;
}
int main()
{
    int i, j;
    while(~scanf("%d %d %d",&n, &k, &m))
    {
        for(i = 0; i < n + 1; i++)
            for(j = 0; j < k + 1; j++)
                memo[ i ][ j ] = -1;
        printf("%lld\n", ways(0, 0));
    }
    return 0;
}
/*
#include <stdio.h>
long long i, j, point, min, mamo[ 51 ][ 51 ], n, k, m;
int main()
{
    while(~scanf("%lld %lld %lld", &n, &k, &m))
    {
        n++; k++;
        for(i = 0; i < n; i++)
            for(j = 0; j < k; j++) mamo[ i ][ j ] = 0;
        mamo[ 0 ][ 0 ] = 1;
        for(i = 0; i < n; i++)
            for(j = 1; j < k; j++)
            {
                min = i < m ? i + 1 : m + 1;
                for(point = 1; point < min; point++) mamo[ i ][ j ] += mamo[i - point][j - 1];
            }
        printf("%lld\n", mamo[n - 1][k - 1]);
    }
    return 0;
}

*/
