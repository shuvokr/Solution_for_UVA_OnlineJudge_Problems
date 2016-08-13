#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define lu unsigned long long int
#define sf scanf
#define pf printf

int main()
{
    lu n,sum;
    while (sf("%llu",&n) != EOF)
    {
        sum = ( (n * (n+2) ) / 2 ) * 3 - 6;
        pf("%llu\n",sum);
    }
    return 0;
}
