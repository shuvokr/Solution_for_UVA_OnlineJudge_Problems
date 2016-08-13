#include <stdio.h>
#include <math.h>
#define pi 2*acos(0.0)
int main()
{
     int T, i;
     double a, b, m, distanceBetweenFoci, rope;
     scanf("%d\n", &T);
     while( T-- )
     {
         scanf("%lf %lf", &distanceBetweenFoci, &rope);
         a = rope / 2;
         b = sqrt(((rope / 2) * (rope / 2)) - ((distanceBetweenFoci / 2) * (distanceBetweenFoci / 2)));
         printf("%.3lf\n", pi * a * b);
     }
    return 0;
}

