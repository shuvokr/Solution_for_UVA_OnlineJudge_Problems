#include<stdio.h>
int main()
{
    int T, n, k, x, kag = 0;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d %d", &n, &k, &x); x--; k += x;
        n = n * (n + 1) >> 1;
        k = k * (k + 1) >> 1;
        x = x * (x + 1) >> 1;
        printf("Case %d: %d\n", ++kag, n - k + x);
    }
    return 0;
}
