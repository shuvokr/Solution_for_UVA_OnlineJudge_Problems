#include <stdio.h>
#include <map>

using namespace std;

int main()
{
    long long n, a, b, mod, x, res, tmp;
    map <long long, int> mp;
    while(~scanf("%lld", &n) && n)
    {
        scanf("%lld %lld", &a, &b);
        tmp = x = 0ll; mod = n; mp.clear();
        while( mp[ x ] !=3 )
        {
            x = ((a * ( (x * x) % mod )) % mod + b) % mod;
            mp[ x ] ++; if(mp[ x ] == 2) tmp++;
        }
        printf("%lld\n", n - tmp);
    }
    return 0;
}

