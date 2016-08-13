#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

#define lu unsigned long int
#define ld long int
#define sf scanf
#define pf printf

int main()
{
    ld N, ar[1001], res, a, b, i, j, k, z = 0;
    while(sf("%ld",&N) != EOF)
    {
        ld count = 0;
        if(N == 0) return 0;
        for(i = 0; i < N; i++)
        {
            sf("%ld",&ar[i]);
            if(ar[i] == 0) count++;
        }
        res = N - count;
        res -=count;
        pf("Case %ld: %ld\n",++z, res);
    }
    return 0;
}
