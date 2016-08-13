#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;


int main()
{
    int i, j, k = 1, L, U;
    bool prime[ 47000 ];

    for(i = 3; i < 47000; i += 2) prime[ i ] = true;
    for(i = 4; i < 47000; i += 2) prime[ i ] = false;

    prime[ 0 ] = prime[ 1 ] = false;
    prime[ 2 ] = true;

    for(i = 3; i < 216; i += 2)
        if(prime[ i ])
            for(j = i * i; j < 47000; j += i + i)
                prime[ j ] = false;


    bool range[ 1000001 ];
    int dif, tmp, fres[ 100000 ], max, min, ll, lu, ul, uu;

    while(~scanf("%d %d", &L, &U))
    {
        dif = U - L + 1;


        for(i = 0; i < dif; i++) range[ i ] = true;

        if(L == 1)
            range[ 0 ] = false;

        k = sqrt( U ) + 1;

        for(i = 2; i < k; i++)
            if(prime[ i ])
            {
                if(L % i == 0) j = L < i * i ? i * i : L;
                else j = L + (i - L % i) < i * i ? i * i : L + (i - L % i);
                for(; j >= L && j <= U; j += i)
                    range[ j - L ] = false;
            }

        k = 0;
        for(i = 0; i < dif; i++)
            if(range[ i ] && i + L <= U) fres[ k++ ] = i + L;

        if(k < 2)
        {
            puts("There are no adjacent primes.");
            continue;
        }
            k--;
            uu = ul = ll = -1;
            lu = 100000000;

            for(i = 0; i < k; i++)
            {
                dif = fres[i + 1] - fres[ i ];
                if(dif < lu - ll)
                {
                    ll = fres[ i ];
                    lu = fres[i + 1];
                }
                if(dif > uu - ul)
                {
                    ul = fres[ i ];
                    uu = fres[i + 1];
                }
            }

            printf("%d,%d are closest, %d,%d are most distant.\n", ll, lu, ul, uu);
    }

    return 0;
}
