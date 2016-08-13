/*
        Shuvo
        Problem catagori: Basic Number Theory
        Problem ID: 11970
        Problem name: Lucky Numbers
*/
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
    long long T, i, tmp, in, ck, kag = 0, flag, n, res[ 32000 ];
    scanf("%lld", &T);
    while(T--)
    {
        scanf("%lld", &n);
        tmp = 1; flag = 1; i = 0;
        do
        {
            flag = tmp * tmp;
            ck = n - flag;
            if(ck % tmp == 0)
            {
                res[ i++ ] = ck;
            }
            tmp++;
        }while(tmp * tmp < n);

        sort(res, res + i);
        printf("Case %lld: %lld", ++kag, res[ 0 ]);
        for(tmp = 1; tmp < i; tmp++)
        {
            printf(" %d", res[ tmp ] );
        }
        printf("\n");
    }
    return 0;
}
