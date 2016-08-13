#include <stdio.h>
int main()
{
    int n, ans;
    while(scanf("%d", &n) && n)
    {
        n--;
        ans = n * (2 + (n - 1) * 2);
        ans >>= 1; ans += n - 1;
        printf("%d\n", ans);
    }
    return 0;
}
