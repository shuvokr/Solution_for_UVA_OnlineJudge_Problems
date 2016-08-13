#include <stdio.h>
using namespace std;
int main()
{
    int in[ 100010 ], n, maxv, maxr, tmp, put, T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        maxr = -1000000000;
        scanf("%d", &maxv);
        for(int i = 1; i < n; i++)
        {
            scanf("%d", &tmp);
            put = maxv - tmp;
            maxv = maxv < tmp ? tmp : maxv;
            maxr = maxr < put ? put : maxr;
        }
        printf("%d\n", maxr);
    }
    return 0;
}
