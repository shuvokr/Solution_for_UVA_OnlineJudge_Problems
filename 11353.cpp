#include <stdio.h>
#include <algorithm>
using namespace std;
struct data
{
    int val, index;
}in[ 2000001 ];
int factor(int n);
const int pr = 2000001;
int prime[ 148935 ], ind;
bool mark[ pr ];
void primelist()
{
    for(int i = 4; i < pr; i += 2) mark[ i ] = false;
    for(int i = 3; i < pr; i += 2) mark[ i ] = true; mark[ 2 ] = true;
    for(int i = 3; i < 1415; i += 2)
        if(mark[ i ])
            for(int j = i << 1; j < pr; j += i) mark[ j ] = false;
    prime[ 0 ] = 2; ind = 1;
    for(int i = 3; i < pr; i += 2)
        if(mark[ i ]) prime[ ind++ ] = i; //printf("%d\n", ind);
}
bool cmp(const data &x, const data &y)
{
    if(x.val < y.val) return true;
    else if(x.val == y.val)
    {
        if(x.index < y.index) return true;
        return false;
    }
    return false;
}
int main()
{
    primelist();
    in[ 1 ].val = in[ 2 ].val = 1;
    in[ 1 ].index = 1; in[ 2 ].index = 2;
    for(int i = 3; i < 2000001; i++)
    {
        in[ i ].index = i;
        in[ i ].val = factor( i );
    }
    sort(in, in + 2000001, cmp);
    int n, kag = 0;
    while(scanf("%d", &n) && n)
    {
        printf("Case %d: %d\n", ++kag, in[ n ].index);
    }
    return 0;
}
int factor(int n)
{
    if(mark[ n ]) return 1;
    int ret = 0, i = 0, tmp = prime[ i ] * prime[ i ] - 1;
    while(n > tmp)
    {
        while(n % prime[ i ] == 0)
        {
            ret++;
            n /= prime[ i ];
        }
        i++;
        if(mark[ n ])
        {
            return ret + 1;
        }
        if(n == 1 || i == ind) return ret;
        tmp = prime[ i ] * prime[ i ] - 1;
    }
    return ret;
}
