#include <stdio.h>
#include <math.h>
int main()
{
    long long x, k, p, q, a, b, i, T;
    while( ~scanf("%lld", &T) )
    {
        while( T-- )
        {
            scanf("%lld %lld", &x,  &k);
            a = floor((double) x / k);
            b = ceil((double) x / k);
            for(p = 0; p * a <= x; p++)
            {
                if((x - p * a) % b == 0)
                {
                    printf("%lld %lld\n", p, (x - p * a) / b);
                    break;
                }
            }
        }
    }
    return 0;
}
