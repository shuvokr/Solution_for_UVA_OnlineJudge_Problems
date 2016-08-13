#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>

using namespace std;

#define sf scanf
#define pf printf

void procage();
void bigmod();

long long n, m, res, k;

int main()
{
    long long T;
    sf("%lld", &T);
    while(T--) procage();
    return 0;
}

void procage()
{
    long long y;

    sf("%lld%lld", &n, &m);
    bool ck = false;
    if(n == 0 && m > 0) puts("000...000"), ck = true;
    else if(n < 100 && m < 4)
    {
        long long temp = 1, sk = m;
        while(sk > 0)
        {
            temp *= n;
            sk--;
        }
        if(temp < 100)
        {
            ck = true;
            if(temp < 10) pf("00%lld...00%lld\n", temp, temp);
            else pf("0%lld...0%lld\n", temp, temp);
        }
    }
    if(ck) return;
    double x = m * log10(n);
    bigmod();

    y = x;
    x -= y;
    x = pow(10, x);
    long long sk = x * 100;

    if(sk < 10) pf("00%lld...", sk);
    else if(sk < 100) pf("0%lld...", sk);
    else pf("%lld...", sk);

    if(res < 10) pf("00%lld\n", res);
    else if(res < 100) pf("0%lld\n", res);
    else pf("%lld\n", res);
}
void bigmod()
{
    res = 1;
    while(m > 0)
    {
        if(m % 2 == 1)
        {
            res = (res * n) % 1000;
        }
        m = m >> 1;
        n = ((n % 1000) * (n % 1000)) % 1000;
    }
}
