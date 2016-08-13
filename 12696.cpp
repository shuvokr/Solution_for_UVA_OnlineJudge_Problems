#include<stdio.h>
int main()
{
    int t = 0, T;
    float len, wid, dep, tot, wgt;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%f %f %f %f", &len, &wid, &dep, &wgt);
        tot = len + wid + dep;
        wgt > 7.00 || tot > 126.000 || (tot > 125.00 && (len > 56.00 || wid > 45.00 || dep > 25.00)) ? printf("0\n") :
                printf("1\n", t++);
    }
    printf("%d\n", t);
    return 0;
}
