#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int T, kag = 0;
    scanf("%d", &T);

    long long res, x1, y1, x2, y2;

    while( T-- )
    {
        scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);

        if(x1 == x2 && y1 == y2)
        {
            printf("Case %d: 0\n", ++kag);
            continue;
        }

        res = 0ll;

        long long a, b, level;

        a = x1 + y1;
        b = x2 + y2;

        level = b - a;

        a = (a * (a - 1)) / 2;
        b = (b * (b - 1)) / 2;

        res = b - a;
        res = res - x1 + x2 + level;

        printf("Case %d: %lld\n", ++kag, res);
    }

    return 0;
}
