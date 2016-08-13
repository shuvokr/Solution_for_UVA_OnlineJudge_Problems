#include <stdio.h>
int main()
{
    int T;
    double tmp, ax, ay, bx, by, cx, cy, a, b, c, AREA, ta, aa, bb, cc, s;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%lf %lf %lf %lf %lf %lf", &ax, &ay, &bx, &by, &cx, &cy);
        tmp = (ax*by+bx*cy+cx*ay-ay*bx-by*cx-cy*ax) / 14.0;
        if(tmp < 0.0) tmp = -tmp;
        printf("%.0lf\n", tmp);
    }
    return 0;
}
