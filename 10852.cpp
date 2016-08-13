#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<assert.h>
#define lu unsigned long int
#define sf scanf
#define pf printf
int N = 5555;

int main()
{
    lu status[5555] = {0}, i, j, sqrtN, prime[5000];
    sqrtN = sqrt(N);
    for( i = 3; i <= sqrtN; i += 2 )
    {
        if( status[i] == 0 )
        {
            for( j = i * i; j <= N; j += i + i )
                status[j] = 1;
        }
    }
    prime[0] = 2;
    j = 1;
    for( i = 3; i <= N; i += 2 )
    {
        if( status[i] == 0 )
        {
            prime[j] = i;
            j++;
        }
    }

    int T;
    sf("%d",&T);
    while(T--)
    {
        lu n, a, b, ck = 0;
        sf("%lu",&n);
        n = n / 2;
        i = 0;
        while(prime[i] <= n)
        {
            i++;
            a = i;
        }
        printf("%lu\n",prime[a]);
    }
    return 0;
}
