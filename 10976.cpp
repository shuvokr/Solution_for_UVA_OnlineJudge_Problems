#include <cstdio>
#include <cmath>

using namespace std;

long mamo[ 1000 ][ 2 ], len, k, x, y, count;

int main()
{
    while( ~scanf("%ld", &k) )
    {
        count = 0; len = 2 * k + 1;
        for(x = k + 1; x < len; x++)
            if(!((x * k) % (x - k))) mamo[ count ][ 0 ] = (x * k) / (x - k), mamo[ count ][ 1 ] = x, count++;
        printf("%d\n", count);
        for(x = 0; x < count; x++) printf("1/%ld = 1/%ld + 1/%ld\n", k, mamo[ x ][ 0 ], mamo[ x ][ 1 ]);
    }
    return 0;
}
