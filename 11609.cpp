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
#define max 100000000000000+1

void input();
long long big_mod(long long q);

int main()
{
    input();

    return 0;
}
void input()
{
    LLD T, n, mod = 1000000007, res, kag = 0;
    sf("%lld", &T);

    while(T--)
    {
        sf("%lld", &n);
        res = ((n % mod) * (big_mod(n - 1) % mod)) % mod;
        pf("Case #%lld: %lld\n", ++kag, res);
    }
}
long long big_mod(long long q)
{
    LLD mod = 1000000007, p = 2, res = 1;
    while(q > 0)
    {
        if(q % 2 != 0) res = (res * p) % mod;
        q /= 2;
        p = ((p % mod) * (p % mod)) % mod;
    }
    return res;
}
