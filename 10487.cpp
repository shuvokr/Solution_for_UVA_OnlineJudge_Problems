#include <stdio.h>

using namespace std;

int main()
{
    int set[ 1002 ], n, q, i, j, kag = 0, query, k, res, tmp, abs_different, a;
    while(~scanf("%d", &n) && n)
    {
        for(i = 0; i < n; i++) scanf("%d", &set[ i ]);
        scanf("%d", &q); abs_different = 1e8; res = 0;
        printf("Case %d:\n", ++kag);
        for(k = 0; k < q; k++)
        {
            scanf("%d", &query);
            for(i = 0; i < n - 1; i++)
                for(j = i + 1; j < n; j++)
                {
                    tmp = set[ i ] + set[ j ];
                    a = tmp > query ? tmp - query : query - tmp;
                    (a < abs_different) ? res = tmp, abs_different = a : res = res;
                }
            printf("Closest sum to %d is %d.\n", query, res);
            abs_different = 1e8; res = 0;
        }
    }
    return 0;
}
