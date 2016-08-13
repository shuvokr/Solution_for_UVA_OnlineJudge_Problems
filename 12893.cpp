#include <stdio.h>
long long f(long long x);
int main()
{
    long long res, n, T;
    scanf("%lld", &T);
    while( T-- )
    {
        scanf("%lld", &n);
        printf("%lld\n", f(n));
    }
    return 0;
}
long long f(long long x)
{
    if(x == 0) return 0;
    if(x == 1) return 1;
    return f(x / 2) + (x % 2);
}

