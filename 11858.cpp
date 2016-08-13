/***********************************
    Shuvo
    Problem ID   : 11858
    Problem algo : Just Marge sort
************************************/
#include <stdio.h>
int in[ 1000010 ], R[ 1000010 ], L[ 1000010 ];
int Li, Ri;
long long ans;
void marge_sort(int left, int right);
void marge(int left, int mid, int right);
int main()
{
    int n, i;
    while(~scanf("%d", &n))
    {
        for(i = 0; i < n; i++) scanf("%d", &in[ i ]);
        ans = 0; marge_sort(0, n - 1);
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
    int i = 0, j = 0, k = 0;
    Li = Ri = 1; mid++;
    for(i = left; i < mid; i++) L[ Li++ ] = in[ i ]; right++;
    for(j = mid; j < right; j++) R[ Ri++ ] = in[ j ];
    L[ Li ] = R[ Ri ] = 1 << 30;
    i = j = 1;
    for(k = left; k < right; k++)
    {
        if(L[ i ] > R[ j ])
        {
            ans += Li - i;
            in[ k ] = R[ j++ ];
        }
        else in[ k ] = L[ i++ ];
    }
}
