#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define lu unsigned long int
#define llu unsigned long long int
#define lld long int
#define sf scanf
#define pf printf
int main()
{
    lld i, j, n, ar[10003], ck,  a, b, d;
    while(sf("%ld", &n) != EOF)
    {
        d = 200000000;
        for(i = 0; i < n; i++)
            sf("%ld", &ar[i]);
        sf("%ld", &ck);

        for(i = 0; i < n; i++)
        {
            int k = 0;
            for(j = 1; j < n; j++)
            {
                if(ar[i] + ar[j] == ck)
                {
                    if(ar[i] > ar[j])
                    {
                        if(ar[i] - ar[j] < d)
                        {
                            d = ar[i] - ar[j];
                            a = i;
                            b = j; k = 1;
                        }
                    }
                    else
                    {
                        if(ar[j] - ar[i] < d)
                        {
                            d = ar[j] - ar[i];
                            b = i;
                            a = j; k = 1;
                        }
                    }
                }
                if(k == 1) break;
            }
        }
        pf("Peter should buy books whose prices are %ld and %ld.\n\n", ar[b], ar[a]);

    }
    return 0;
}

