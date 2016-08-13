#include <stdio.h>
using namespace std;
int main()
{
    int tmp, i, st, start, end, T, n, kag = 0, tot, mx;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d", &n);
        tot = mx = 0;
        st = start = 1; end = -1;
        for(i = 1; i < n; i++)
        {
            scanf("%d", &tmp);
            tot += tmp;
            tot < 0 ? tot = 0, st = i + 1 : true;
            tot > mx || (tot == mx && i - st > end - start) ? mx = tot, start = st, end = i : true;
        }
        !mx ? printf("Route %d has no nice parts\n", ++kag) :
            printf("The nicest part of route %d is between stops %d and %d\n", ++kag, start, end + 1);
    }
    return 0;
}
