#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define lu unsigned long int
#define sf scanf
#define pf printf
int main()
{
    double a, b, c, r;
    while(sf("%lf%lf%lf",&a,&b,&c) != EOF)
    {
        if(a == 0 || b == 0 || c == 0) pf("The radius of the round table is: 0.000\n");
        else{
        r = (a + b + c) / 2.000;
        if(r >= 0){
            r = (r-a) * (r-b) * (r-c) / r;
            r = sqrt(r);
            pf("The radius of the round table is: %.3lf\n", r);
        }
        else
            pf("The radius of the round table is: 0.000\n");
        }
    }
    return 0;
}
