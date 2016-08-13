#include <stdio.h>
int main()
{
    int n, tmp, res;
    while(scanf("%d", &n) && n)
    {
        res = 0;
        while(n--)
        {
            scanf("%d", &tmp);
            res ^= tmp;
        }
        puts(res ? "Yes" : "No");
    }
    return 0;
}
