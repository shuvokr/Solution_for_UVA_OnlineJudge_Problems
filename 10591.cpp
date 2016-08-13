#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define sf scanf
#define pf printf
int main()
{
    long long N, T, i, j, len, res, temp, z = 0, tmp, k = 0, ckarray[1000] = {0}, x;
    sf("%lld", &T);
    while(T--)
    {
        sf("%lld", &N);
        k = 0;
        temp = N;
        tmp = pow(N, 2);
        ckarray[k] = N; k++;
        while(1)
        {
            len = log10(N) + 1;
            res = 0;
            for(i = 0; i < len; i++)
            {
                j = N % 10;
                N /= 10;
                res += pow(j, 2);
            }
            N = res;
            ckarray[k] = N; k++;
            if(N == 1)
            {
                pf("Case #%lld: %lld is a Happy number.\n", ++z, temp);
                break;
            }
            else
            {
                int xx = 0;
                for(x = k - 2; x >= 0; x--)
                {
                    if(N == ckarray[x])
                    {
                        xx = 1;
                        pf("Case #%lld: %lld is an Unhappy number.\n", ++z, temp);
                    }
                    if(xx == 1) break;
                }
                if(xx == 1) break;
            }
        }
    }
    return 0;
}
