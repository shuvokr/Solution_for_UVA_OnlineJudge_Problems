#include <stdio.h>
int in[ 500010 ], L[ 500010 ], R[ 500010 ], Li, Ri;
long long ans;
void marge_sort(int left, int right);
void marge(int left, int mid, int right);
int main()
{
    int n, i;
    while(~scanf("%d", &n) && n)
    {
        for(i = 0; i < n; i++) scanf("%d", &in[ i ]); ans = 0;
        marge_sort(0, n - 1);
        printf("%lld\n", ans);
    }
    return 0;
}
void marge_sort(int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) >> 1;
        marge_sort(left, mid);
        marge_sort(mid + 1, right);
        marge(left, mid, right);
    }
}
void marge(int left, int mid, int right)
{
    int i = left, j = mid + 1, k = left;
    Li = Ri = 1; mid++;
    for(;i < mid; i++) L[ Li++ ] = in[ i ]; right++;
    for(;j < right; j++) R[ Ri++ ] = in[ j ];
    L[ Li ] = R[ Ri ] = 1 << 30;
    i = j = 1;
    for(;k < right; k++)
    {
        if(L[ i ] > R[ j ])
        {
            ans += Li - i;
            in[ k ] = R[ j++ ];
        }
        else in[ k ] = L[ i++ ];
    }
}
