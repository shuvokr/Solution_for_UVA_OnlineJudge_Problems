#include <stdio.h>
#include <string.h>
int sub, mark, pass, max, mamo[ 100 ][ 100 ], ans;
int dp(int spos, int tot);
int main()
{
    int T;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d %d %d", &sub, &mark, &pass);
        max = mark - (pass * sub) + pass;
        memset(mamo, -1, sizeof mamo); ans = 0;
        ans = dp(0, 0);
        printf("%d\n", ans);
    }
    return 0;
}
int dp(int spos, int tot)
{
    if(spos == sub && tot == mark) return 1;
    if(spos >= sub || tot > mark) return 0;
    if(mamo[ spos ][ tot ] != -1) return mamo[ spos ][ tot ];

    int ret = 0;
    for(int i = pass; i <= max; i++) ret += dp(spos + 1, tot + i);
    return mamo[ spos ][ tot ] = ret;
}
