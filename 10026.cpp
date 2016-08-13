#include <stdio.h>
#include <algorithm>
using namespace std;
struct data
{
    int ind;
    double value;
}in[ 1010 ];
bool cmp(const data &x, const data &y)
{
    if(x.value > y.value) return true;
    return false;
}
int main()
{
    int T, n, i;
    double a, b;
    bool space = false;
    scanf("%d", &T);
    while( T-- )
    {
        if( space ) puts("");
        else space = true;
        scanf("%d", &n);
        for(i = 0; i < n; i++) scanf("%lf %lf", &a, &b), in[ i ].ind = i + 1, in[ i ].value = b / a;
        sort(in, in + n, cmp); printf("%d", in[ 0 ].ind);
        for(i = 1; i < n; i++) printf(" %d", in[ i ].ind);
        puts("");
    }
    return 0;
}
