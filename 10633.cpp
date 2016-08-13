#include<stdio.h>
#include<math.h>
#define lu unsigned long long int
#define sf scanf
#define pf printf
int main()
{
    lu n, res, ck;
    while(sf("%llu",&n) != EOF)
    {
        if(n == 0) return 0;
        ck = n % 9;
        res = n * 10;
        res /= 9;
        if(ck == 0)
            pf("%llu %llu\n",res-1, res);
        else
            pf("%llu\n",res);
    }
    return 0;
}
