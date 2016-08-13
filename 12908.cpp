#include <stdio.h>

int main()
{
    int stor[ 20000 ];
    stor[ 0 ] = 0; stor[ 1 ] = 2;
    int k = 1;
    for(int i = 3; i < 20001; i++)
    {
        int x = i + stor[ k++ ];
        stor[ k ] = x;
    }
    int n, len = 19999;
    while(scanf("%d", &n) && n)
    {
        int low = 0, high = len, mid;
        while(high - low > 1)
        {
            mid = (low + high) >> 1;
            if(stor[ mid ] < n) low = mid;
            else high = mid;
        }
        printf("%d %d\n", stor[ high ] - n + 1, high + 1);
    }

    return 0;
}

