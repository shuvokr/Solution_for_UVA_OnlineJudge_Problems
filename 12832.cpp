#include <stdio.h>
long long gcd( long long a, long long b ) { return b == 0 ? a : gcd(b, a % b); }
long long lcm ( long long a, long long b ) { return ( a / gcd ( a, b ) ) * b; }
int main()
{
    long long gd, a, b, h, l;
    int T, kag = 0, n, i;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d %lld %lld", &n, &l, &h);
        gd = gcd(h, l); h /= gd; l /= gd;
        for(i = 1; i < n; i++)
        {
            scanf("%lld %lld", &a, &b);
            gd = gcd(a, b); a /= gd; b /= gd;
            gd = lcm(a, l);
            h *= (gd / l);
            h += b * (gd / a); l = gd;
        }
        gd = gcd(h, l); h /= gd; l /= gd;
        printf("Case %d: %lld/%lld\n", ++kag, h, l);
    }
    return 0;
}
