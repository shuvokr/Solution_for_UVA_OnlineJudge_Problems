#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

struct data
{
    int first, second;
}in[ 45 ];

int dp(int pos, int x, int y);

int m, s, mamo[ 41 ][ 301 ][ 301 ], min_res;

int main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d %d", &m, &s);
        for(int i = 0; i < m; i++) scanf("%d %d", &in[i].first, &in[i].second);
        memset(mamo, -1, sizeof mamo);
        int res = -1;
        res = dp(0, 0, 0);
        if(res == -1 || res == 1 << 29) puts("not possible");
        else printf("%d\n", res);
    }
    return 0;
}
int dp(int pos, int x, int y)
{
    double value = sqrt(x * x + y * y);
    //printf("  %.5lf\n", value);
    if(value > (double)s) return 1 << 29;
    if(value == (double)s) return 0;
    if(pos == m) return 1 << 29;
    if(mamo[ pos ][ x ][ y ] != -1) return mamo[ pos ][ x ][ y ];

    int a = 0, b = 0, c = 0, d = 0;
    if(in[pos].first || in[pos].second)
    a = min(1 + dp(pos, x + in[pos].first, y + in[pos].second), 1 + dp(pos + 1, x + in[pos].first, y + in[pos].second));
    d = dp(pos + 1, x, y);
    int ret = 1 << 29;
    if(a) ret = min(a, ret);
    if(d) ret = min(d, ret);
    return mamo[ pos ][ x ][ y ] = ret;
}
