#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
    int i, div[] = {9,8,7,6,5,4,3,2}, T, num, k;
    char ans[ 102 ];
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d", &num);
        if( !num || num == 1)
        {
            printf("%d\n", num);
            continue;
        }
        k = 0;
        for(i = 0; i < 8; i++)
        {
            while( !(num % div[ i ]) )
            {
                num /= div[ i ];
                ans[ k++ ] = div[ i ] + 48;
            }
        }
        sort(ans, ans + k); ans[ k ] = NULL;
        puts( num != 1 ? "-1" : ans );
    }
    return 0;
}
