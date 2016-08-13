#include <stdio.h>
long long f(long long n) { return n * (n + 1) / 2; }
int main()
{
    long long n, tmp;
    while( ~scanf("%lld", &n) )
    {
        if(n == 1)
        {
            puts("1/1");
            continue;
        }
        long long low = 1, high = 10000000, mid = (low + high) / 2, last;
        while( high - low > 1 )
        {
            tmp = f( mid );
            if(tmp < n) low = mid;
            else high = mid;
            mid = (low + high) / 2;
        }
        low++;
        printf("%lld/%lld\n", f( low ) - n + 1, n - f(low - 1));
    }
    return 0;
}
