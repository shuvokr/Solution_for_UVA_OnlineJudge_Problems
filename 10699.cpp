#include <stdio.h>
using namespace std;
int main()
{
    int i, j, n, m;
    bool prime[ 1000001 ];
    prime[ 0 ] = prime[ 1 ] = false;
    for(i = 4; i < 1000000; i += 2) prime[ i ] = false;
    prime[ 2 ] = true;
    for(i = 3; i < 1000000; i += 2) prime[ i ] = true;

    for(i = 3; i < 1001; i += 2)
        for(j = i * i; j < 1000000; j += i)
            prime[ j ] = false;


    while(~scanf("%d", &n))
    {
        if(!n) return 0;
        if(prime[ n ]) printf("%d : 1\n", n);
        else
        {
            m = 0;
            for(i = 2; i < n; i++)
                if(prime[ i ])
                    if(n % i == 0) m++;
            printf("%d : %d\n", n, m);
        }

    }

    return 0;
}
