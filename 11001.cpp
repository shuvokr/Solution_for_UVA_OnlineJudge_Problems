#include <stdio.h>
#include <math.h>
int main()
{
    int i, p, n, m; double max = 0.0, x, sum;
    while(scanf("%d %d", &n, &m) && n)
    {
        max = 0.0;
        for(i = 0; i < n; i++)
        {
            x = n * 1.0 / i - m;
            if(x < 0.0) break;
            sum = 0.3 * sqrt(x) * i;
            if(fabs(max - sum) <= 1e-10) p = 0;
            else if(sum > max) max = sum, p = i;
        }
        printf("%d\n", p);
    }
    return 0;
}
