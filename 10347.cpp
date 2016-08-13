#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

#define lu unsigned long int
#define llu unsigned long long int
#define sf scanf
#define pf printf
int main()
{
    double med1, med2, med3, med_s, area, a;
    while(sf("%lf %lf %lf", &med1, &med2, &med3) == 3)
    {
        med_s = (med1 + med2 + med3) / 2;
        area = med_s * (med_s - med1) * (med_s - med2) * (med_s - med3);
        area = sqrt( area );
        area *= 4.0 / 3.0;
        if( area > 0)
            pf("%.3lf\n", area);
        else
        {   area = -1;
            pf("%.3lf\n", area);
        }
    }
    return 0;
}
