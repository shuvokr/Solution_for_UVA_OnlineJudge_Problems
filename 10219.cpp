#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    long long n, r;
    double res;
    while(~scanf("%lld %lld", &n, &r))
    {
        if(r > n) puts("0");
        else if(n == r) puts("1");
        else
        {
            res = 0.0;
            while(r > 1)
            {
                res += log10((double)n / (double)r);
                n--; r--;
            }
            res += log10( n );
            printf("%.0lf\n", floor(res) + 1.0);
        }
    }

    return 0;
}
