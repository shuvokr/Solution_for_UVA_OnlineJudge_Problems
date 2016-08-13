#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
void save();
long long zero(long long num, long long base);
long long digit(int num, int base);
void savep();
bool mark[ 800 ];
int prime[ 150 ], ind;
char in[ 100 ];
double save_res[ 1048577 ];
int main()
{
    save();
    savep();
    int base, x;
    long long num;
    while(~scanf("%d %d", &x, &base))
    {
        printf("%lld %lld\n", zero(x, base), digit(x, base));
    }
    return 0;
}
void save()
{
    int i;
    double tmp = 0;
    save_res[0] = 0.0;
    save_res[1] = 0.0;
    for(i = 2; i < 1048577; i++)
    {
        tmp += log10(i);
        save_res[i] = tmp;
    }
}
void savep()
{
    for(int i = 2; i < 800; i += 2) mark[ i ] = false;
    for(int i = 3; i < 800; i += 2) mark[ i ] = true;
    for(int i = 3; i < 29; i += 2)
        if(mark[ i ])
            for(int j = i + i; j < 800; j += i) mark[ j ] = false;
    prime[ 0 ] = 2; ind = 1;
    for(int i = 3; i < 1025; i += 2)
        if(mark[ i ]) prime[ ind++ ] = i;
    mark[ 1 ] = false;
}
long long zero(long long num, long long base)
{
    long long st = num, s = num, ret = 1 << 29;
    int cou, i = 0, last = 0;
    while( base > 1 && i < ind )
    {
        cou = 0;
        while(base % prime[ i ] == 0) cou++, base /= prime[ i ];
        i++;
        if( cou )
        {
            last = prime[ i - 1 ];
            long long tmp = last, tot = 0;
            st = s;
            while(st >= tmp)
            {
                tot += (st / tmp);
                tmp *= last;
            }
            tot = tot / cou;
            ret = ret < tot ? ret : tot;
        }
        if(mark[ base ])
        {
            if(last < base)
            {
                long long tmp = base, tot = 0;
                st = num;
                while(st >= tmp)
                {
                    tot += (st / tmp);
                    tmp *= base;
                }
                ret = ret < tot ? ret : tot;
            }
            base = 1;
            break;
        }
    }
    return ret;
}
long long digit(int num, int base)
{
    double res = 0;
    res = save_res[ num ] / log10( base );
    long long ret = (int)floor(res + 1.00);
    return ret;
}
