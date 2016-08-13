#include <stdio.h>
#include <math.h>
int main()
{
    double radius, side;
    while(~scanf("%lf %lf", &radius, &side))
    {
        printf("%.3lf\n", 0.5 * radius * radius * side * sin(2 * 3.1415926535897932384626433832795 / side) );
    }
    return 0;
}
