#include <stdio.h>
const int x = 1299710;
int ind, prime[ 100005 ];
bool mark[ x ];
int main()
{
    int i, j, n;
    for(i = 4; i < x; i += 2) mark[ i ] = false;
    for(i = 3; i < x; i += 2) mark[ i ] = true;

     for(i = 3; i < 1140; i += 2)
        if(mark[ i ])
            for(int j = i << 1; j < x; j += i) mark[ j ] = false;
    prime[ 0 ] = 2;
    ind = 1; mark[ 2 ] = true;
    for(i = 3; i < x; i += 2)
        if(mark[ i ]) prime[ ind++ ] = i;

    int left, right, mid;
    while(scanf("%d", &n) && n)
    {
        if(mark[ n ] || n == 1) puts("0");
        else
        {
            left = 0; right = ind - 1;
            while(right - left > 1)
            {
                mid = (left + right) >> 1;
                if(prime[ mid ] < n) left = mid;
                else right = mid;
            }
            printf("%d\n", prime[ right ] - prime[right - 1]);
        }
    }
    return 0;
}
