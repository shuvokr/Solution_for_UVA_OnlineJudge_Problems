#include <stdio.h>

int n, in[ 100010 ], target;

int main ()
{
    while(~scanf("%d %d", &n, &target))
    {
        in[ 0 ] = 0; int i;
        for(i = 1; i <= n; i++) scanf("%d", &in[ i ]), in[ i ] += in[i - 1];
        int ind = 1, cou = 0, res = 1 << 30;
        for(i = 1; i <= n; i++)
        {
            if(in[ i ] - in[ind - 1] >= target)
            {
                int k = ind;
                while(in[ i ] - in[k - 1] >= target && k <= i)
                {
                    k++;
                }
                ind = --k;
                k = i - ind + 1;
                res = res < k ? res : k;
            }
        }
        if(res == 1 << 30) res = 0;
        printf("%d\n", res);
    }
    return 0;
}

