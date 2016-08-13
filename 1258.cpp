#include <stdio.h>
#include <string.h>

long long DP(int ind);

long long p, ar[ 91 ], mamo[ 91 ], mark, a[ 91 ], b[ 91 ], n;

int main()
{
    int i;
    ar[ 1 ] = 1; ar[ 2 ] = 2;
    for(i = 3; i < 91; i++) ar[ i ] = ar[i - 1] + ar[i - 2];
    while(~scanf("%lld", &n))
    {
        printf("%lld\n", n);
        mark = p = 0;
        memset(mamo, -1, sizeof mamo);
        long long tmp = DP( 1 );


        for(i = 0; i < p; i++) printf("%lld ", a[ i ]); puts("");
        for(i = 0; i < p; i++) printf("%lld ", b[ i ]);
        puts("");
        puts("");
    }
    return 0;
}
long long DP(int ind)
{
    if( mark ) return 0;
    if(ind > 90) return 0;
    if(mamo[ ind ] != -1) return mamo[ ind ];
    long long ret = 0, nn = 0;

    ret = DP(ind + 1);
    if(ret == n)
    {
        mark = 1;
        return 0;
    }
    if( mark ) return 0;
    if(ret + ar[ ind ] <= n)
    {
        a[ p ] = ind; b[ p ] = ar[ ind ];p++;
        ret = ar[ ind ] + DP(ind + 1);
        if(ret == n)
        {
            mark = 1;
            return 0;
        }
    }
    if( mark ) return 0;
    return mamo[ ind ] = ret;
}
