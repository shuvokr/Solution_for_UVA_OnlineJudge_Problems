#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
    int tmp1, tmp2, gcd;
    while(scanf("%d", &tmp1) && tmp1)
    {
        gcd = 0; tmp2 = tmp1;
        while(scanf("%d", &tmp1) && tmp1)
        {
            tmp2 = tmp2 - tmp1;
            gcd = gcd && tmp2 ? __gcd(gcd, tmp2) : gcd;
            gcd = !gcd ? tmp2 : gcd;
            tmp2 = tmp1;
        }
        gcd *= gcd < 0 ? -1 : 1;
        printf("%d\n", gcd);
    }
    return 0;

}
