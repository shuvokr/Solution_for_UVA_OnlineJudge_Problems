#include <stdio.h>
using namespace std;
int main()
{
    //freopen("out.txt", "w", stdout);
    long long int rem, m, n, i, tmp, two, digit;
    while(~scanf("%lld %lld", &m, &n))
    {
        if(!n)
        {
            puts("1");
            continue;
        }
        i = m - n + 1; m++;
        two = 0; digit = 1;
        for(; i < m; i++)
        {
            tmp = i;
            rem = tmp % 2;
            while( !rem )
            {
                two++;
                tmp = tmp >> 1;
                rem = tmp % 2;
            }
            rem = tmp % 5;
            while( !rem )
            {
                two--;
                tmp = tmp / 5;
                rem = tmp % 5;
            }
            digit = (tmp * digit) % 10;
        }
        if(two < 0) puts("5");
        else
        {
            for(i = 0; i < two; i++) digit = (digit << 1) % 10;
            printf("%lld\n", digit);
        }
    }
    return 0;
}
