#include <stdio.h>
#include <algorithm>
using namespace std;
int in[ 1000020 ], n, k, T, kag, cou;
int main()
{
    kag = 0; long long res, t;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d %d", &n, &k); t = res = 0;
        for(int i = 0; i < n; i++) scanf("%d", &in[ i ]);
        for(int i = 0, tmp; i < n; i++) scanf("%d", &tmp), in[ i ] = tmp - in[ i ], res += in[ i ];
        sort(in, in + n); cou = 0;
        while(in[ cou ] < 0 && k) t += in[ cou ], cou++, k--; res -= t;
        if(res < 1) printf("Case %d: No Profit\n", ++kag);
        else printf("Case %d: %lld\n", ++kag, res);
    }
    return 0;
}
