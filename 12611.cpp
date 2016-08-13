#include <stdio.h>
int main()
{
    int kag = 0, T;
    double r, k, l, m;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%lf", &r);
        printf("Case %d:\n", ++kag);
        k = r * 1.5; l = 2.25 * r; m = 2.75 * r;
        printf("-%.0lf %.0lf\n%.0lf %.0lf\n%.0lf -%.0lf\n-%.0lf -%.0lf\n", l, k, m, k, m, k, l, k);
    }
    return 0;
}
