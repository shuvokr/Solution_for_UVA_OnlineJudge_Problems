#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int dp(int pos, int taka);
int coin[] = {5, 10, 20, 50, 100, 200}, target, ca[ 6 ], ans[ 1005 ] = {0};
int main()
{
    int j, i;
    for(i = 0; i < 1005; i++) ans[ i ] = 1 << 25;
	ans[ 0 ] = 0;
    for(i = 0; i < 6; i++)
		for(j = coin[ i ]; j < 1005; j++)
			ans[ j ] = min(ans[ j ], 1 + ans[j - coin[i]]);

    int tmp, a, b;
    while(~scanf("%d %d %d %d %d %d", &ca[ 0 ], &ca[ 1 ], &ca[ 2 ], &ca[ 3 ], &ca[ 4 ], &ca[ 5 ]) &&
          (ca[ 0 ] || ca[ 1 ] || ca[ 2 ] || ca[ 3 ] || ca[ 4 ] || ca[ 5 ]))
    {
        scanf("%d.%d", &a, &b);
        target = a * 100 + b;
        int res = dp(0, target);
        printf("%3d\n", res);
    }
    return 0;
}
int dp(int pos, int taka)
{
    int a, b;
    if((pos >= 6 && taka > 0) || taka > 500 || taka < -500) return 1 << 25;
    if(taka <= 0) return ans[ -taka ];

    if(!ca[ pos ]) return dp(pos + 1, taka);
    else
    {
        ca[ pos ]--;
        a = 1 + dp(pos, taka - coin[ pos ]);
        ca[ pos ]++;
        b = dp(pos + 1, taka);
        int ret = a < b ? a : b;
        return ret;
    }
}
