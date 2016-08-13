#include<stdio.h>
#include<math.h>
int main()
{
    int T = 0;
    double L = 0, circle = 0, rect =0 , w = 0, r = 0, *ci, *re;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf",&L);
        w =  L * 0.6;
        r = L * 0.2;
        circle = 3.1415926535897932384626433832795 * pow(r,2);
        rect = L * w - circle;
        ci = &circle; re = &rect;
        printf("%.2lf %.2lf\n",*ci,*re);
        w = 0; r = 0;
    }
    return 0;
}
