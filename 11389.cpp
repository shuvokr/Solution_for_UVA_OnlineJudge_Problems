#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, d, r, tmp, tot, mind[ 102 ], minn[ 102 ], i, a, b;
    while(~scanf("%d %d %d", &n, &d, &r) && (n || d || r))
    {
        for(i = 0; i < n; i++) scanf("%d", &mind[ i ]);
        for(i = 0; i < n; i++) scanf("%d", &minn[ i ]);
        sort(mind, mind + n);
        sort(minn, minn + n);
        a = 0; b = n - 1; tot = 0;
        for(i = 0; i < n; i++)
        {
            tmp = mind[ a ] + minn[ b ];
            if(tmp > d) tot += ((tmp - d) * r);
            a++; b--;
        }
        printf("%d\n", tot);
    }
    return 0;
}
