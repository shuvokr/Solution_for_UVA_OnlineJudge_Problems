#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define sf scanf
#define pf printf
int main()
{
    long i, j, step, mod, counter, seed;
    while(sf("%ld %ld", &step, &mod) != EOF)
    {
        i = 0;
        seed = step % mod;
        counter = 1;
        while(1)
        {
            seed += step;
            seed %= mod;
            if(seed == 0) { counter++; break; }
            else counter++;
        }
        if(counter == mod) pf("%10ld%10ld    Good Choice\n\n",step, mod);
        else pf("%10ld%10ld    Bad Choice\n\n",step, mod);
    }
    return 0;
}
