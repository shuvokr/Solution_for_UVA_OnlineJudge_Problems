#include <stdio.h>
using namespace std;
int main()
{
    int n, res, i, tmp, tot;
    while(~scanf("%d", &n) && n)
    {
        res = tot= 0;
        for(i = 0; i < n; i++)
        {
            scanf("%d", &tmp);
            tot += tmp;
            res = res < tot ? tot : res;
            tot = tot < 1 ? 0 : tot;
        }
        ( !res ) ? puts("Losing streak.") : printf("The maximum winning streak is %d.\n", res);
    }
    return 0;
}
