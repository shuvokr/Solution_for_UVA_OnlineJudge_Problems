#include <stdio.h>
int main()
{
    long long n;
    int T;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%lld", &n);
        printf("%lld\n", n / 2);
    }
    return 0;
}

