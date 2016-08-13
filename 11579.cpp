#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
    int n, T;
    double in[ 10010 ], s, res, x;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%lf", &in[ i ]);
        sort(in, in + n); res = 0.0;
        for(int i = n - 3; i >= 0; i--)
        {
            if(in[ i ] + in[i + 1] >= in[i + 2])
            {
                s = (in[ i ] + in[i + 1] + in[i + 2]) / 2;
                x = sqrt(s*(s-in[i])*(s-in[i+1])*(s-in[i+2]));
                res = res > x ? res : x;
            }
        }
        printf("%.2lf\n", res);
    }
    return 0;
}


