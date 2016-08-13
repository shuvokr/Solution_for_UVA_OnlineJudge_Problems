#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define LL unsigned long long
#define L long long

const int pr = 5002;
int prime[ 675 ], ind;
bool mark[ pr ];
void primelist()
{
    for(int i = 4; i < pr; i += 2) mark[ i ] = false;
    for(int i = 3; i < pr; i += 2) mark[ i ] = true; mark[ 2 ] = true;
    for(int i = 3, sq = sqrt( pr ); i < sq; i += 2)
        if(mark[ i ])
            for(int j = i << 1; j < pr; j += i) mark[ j ] = false;
    prime[ 0 ] = 2; ind = 1;
    for(int i = 3; i < pr; i += 2)
        if(mark[ i ]) prime[ ind++ ] = i; //printf("%d\n", ind);
}

int main()
{
    primelist();
    long long T, n, m, sum, res, minn, Z = 0, kag = 0;
    sf("%lld", &T);
    while(T--)
    {
        scanf("%lld %lld", &m, &n);
        printf("Case %lld:\n", ++kag);
        minn = 1 << 29;
        if(n == 1)
        {
            puts("0");
            continue;
        }
        res = 1 << 29;
        for(int i = 0; i < ind && prime[ i ] <= m; i++)
        {
            sum = 0;
            while(m % prime[ i ] == 0)
            {
                sum++;
                m /= prime[ i ];
            }
            if( sum )
            {
                //puts("ok");
                long long tmp = prime[ i ], tot = 0;
                while(tmp <= n)
                {
                    tot += (n / tmp);
                    tmp *= prime[ i ];
                }
                tot = tot / sum;
                res = 0;
                //printf("  %d %d\n", tot, prime[ i ]);
                if(tot == 0) {res = 1 << 29; break;}
                minn = min(minn, tot);
            }
        }
        if(!res && m > 1)
        {
            sum = 1;
            long long tmp = m, tot = 0;
            while(tmp <= n)
            {
                tot += (n / tmp);
                tmp *= m;
            }
            res = 0;
            tot = tot / sum;
            if(tot == 0) res = 1 << 29;
            minn = min(minn, tot);
        }
        if(res == 1 << 29) puts("Impossible to divide");
        else printf("%lld\n", minn);
    }
    return 0;
}
