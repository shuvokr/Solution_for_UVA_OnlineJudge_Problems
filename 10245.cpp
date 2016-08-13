#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
template <class T> T sq(T x) {return x * x;}
struct data
{
    double a, b;
}in[ 10010 ];
bool cmp(const data &a, const data &b)
{
    return (a.a < b.a);
}
double dis(data a, data b)
{
  return sq(a.a - b.a) + sq(a.b - b.b);
}
int main()
{
    int n;
    double min;
    while(scanf("%d", &n) && n)
    {
        for(int i = 0; i < n; i++) scanf("%lf %lf", &in[ i ].a, &in[ i ].b);
        if(n == 1) { puts("INFINITY"); continue; }
        sort(in, in + n, cmp);
        min = dis(in[ 0 ], in[ 1 ]);
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n && sq(in[ j ].a - in[ i ].a) < min; j++)
                if (dis(in[ j ], in[ i ]) < min) min = dis(in[ j ], in[ i ]);
        min = sqrt( min );
        if (min > 10000.0 || fabs(min - 10000.0) < 0.00001) puts("INFINITY");
        else printf("%.4lf\n", min);
    }
    return 0;
}
