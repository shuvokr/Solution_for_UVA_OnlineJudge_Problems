#include <stdio.h>
#include <string.h>
int DP(int s, int e, int cnt);
int i, kag, res, in[ 10010 ], n, maxn, T;
int main()
{
    kag = 0;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d %d", &n, &maxn);
        for(i = 0; i < n; i++) scanf("%d", &in[ i ]);
        printf("Case %d: ", ++kag);
        res = DP(0, n - 1, 0);
        if(!res) puts("Too easy");
        else if(res > maxn) puts("Too difficult");
        else printf("%d\n", res);
    }
    return 0;
}
int DP(int s, int e, int cnt)
{
    if(cnt > maxn) return cnt;
    if(s > e) return cnt;
    else if(in[ s ] == in[ e ]) return DP(s + 1, e - 1, cnt);
    else
    {
        int a = DP(s + 1, e, cnt + 1);
        int b = DP(s , e - 1, cnt + 1);
        return a > b ? b : a;
    }
}
