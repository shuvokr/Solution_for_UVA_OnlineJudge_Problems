#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define sf scanf
#define pf printf
int main()
{
    long long Inpary, i = 0, j, k, sqr, sum, save;
    puts("PERFECTION OUTPUT");
    while(sf("%lld", &Inpary) == 1)
    {
        if(Inpary == 0) break;
        sum = 0;
        sqr = Inpary / 2;
        for(k = 1; k <= sqr; k++)
            if(Inpary % k == 0)
                sum += k;
        if(sum == Inpary) pf("%5lld  PERFECT\n", Inpary);
        else if(sum > Inpary) pf("%5lld  ABUNDANT\n", Inpary);
        else pf("%5lld  DEFICIENT\n", Inpary);
    }
    puts("END OF OUTPUT");
    return 0;
}
