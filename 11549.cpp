#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define LLU unsigned long long
#define Lu unsigned long
#define LLD long long
#define LD long
#define fo(i, n) for(i = 0; i < n; i++)
#define fa(i, n) for(i = 0; i < n - 1; i++)
#define oof(i, n) for(i = n - 1; i >= 0; i--)
#define mx 1000000000+1

void input();
long long make_ndigit(long long n, long long k);

int main()
{
    input();

    return 0;
}
void input()
{
    LLD T, n, k, i, tmp, max;

    sf("%lld", &T);
    while(T--)
    {
        map <LLD, LLD> ck;
        sf("%lld%lld", &n, &k);
        tmp = make_ndigit(n, k);
        ck[tmp]++;
        max = tmp;
        k = tmp;
        while(true)
        {
            k = k * k;
            tmp = make_ndigit(n, k);
            k = tmp;
            if(max < tmp) max = tmp;
            if(ck[tmp] > 0) break;
            ck[tmp]++;
        }
        pf("%lld\n", max);
    }
}
long long make_ndigit(long long n, long long k)
{
    LLD len = log10(k) + 1, tmp, res, sk;
    if(len <= n) return k;

    tmp = len - n;
    sk = 10;
    res = ceil(pow(sk, tmp));
    res = k / res;
    return res;
}
