#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define sf scanf
#define pf printf
long long memo[55] = {0};

int main()
{
    long long n, T, z = 0, i;

    memo[1] = 2; memo[2] = 3;
    for(i = 3; i <= 51; i++)
        memo[i] = memo[i-1] + memo[i-2];

    sf("%lld", &T);
    while(T--)
    {
        sf("%lld", &n);
        pf("Scenario #%lld:\n%lld\n\n", ++z, memo[n]);
    }

    return 0;
}

