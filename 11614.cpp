#include <stdio.h>

using namespace std;

long long fun(long long x)
{
    long long tmp;
    if( !(x % 2) )
    {
        tmp = x >> 1; x++;
        return tmp * x;
    }
    else
    {
        tmp = (x + 1) >> 1;
        return tmp * x;
    }
}

int main()
{
    long long T, n, tmp, i, cou, low, high, mid, lown, highn;
    scanf("%lld", &T);
    while( T-- )
    {
        scanf("%lld", &n);
        if( !n )
        {
            puts("0");
            continue;
        }
        low = 1; high = 14142135162;
        while( true )
        {
            mid = low + high;
            mid /= 2;
            lown = fun( low ); highn = fun( high );
            if(fun ( mid ) > n) high = mid;
            else low = mid;
            if(high - low == 1) break;
        }
        printf("%lld\n", low);
    }

    return 0;
}
