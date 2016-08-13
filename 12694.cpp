#include <stdio.h>
#include <algorithm>
using namespace std;
struct data
{
    int s, e;
    bool operator < (const data k) const
    {
        return e < k.e;
    }
};
int main()
{
    int T, res, i, tmp;
    data in[ 22 ];
    scanf("%d", &T);
    while(T--)
    {
        res = i = 0;
        while(~scanf("%d %d", &in[i].s, &in[i].e) && (in[i].s || in[i].e)) i++;
        sort(in, in + i);
        tmp = in[0].e; res++;
        for(int j = 1; j < i; j++)
            (tmp <= in[j].s) ? res++, tmp = in[j].e : 0;
        printf("%d\n", res);
    }
    return 0;
}
