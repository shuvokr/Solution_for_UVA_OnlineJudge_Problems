/*
                                        Shuvo
                                        10162
*/
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
typedef long long ll;

ll Bigmod(ll p, ll q);
ll convertCtoN();

char num[202];

int main()
{
    ll n, res, i;
    while(gets(num))
    {
        if(num[0] == '0') return 0;
        n = convertCtoN();
        res = 0;
        for(i = 1; i <= n; i++)
        {
            res = (res + Bigmod(i, i)) % 10;
        }
        pf("%lld\n", res);
    }
}
ll convertCtoN()
{
    char ch[4];
    ll n, len = strlen(num);
    if(len == 1) n = num[0] - 48;
    else if(len == 2) n = ((num[0] - 48) * 10) + (num[1] - 48);
    else if(len > 2)
    {
        ch[0] = num[len - 3];
        ch[1] = num[len - 2];
        ch[2] = num[len - 1];
        sscanf(ch, "%lld", &n);
    }
    return n;
}

ll Bigmod(ll p, ll q)
{
    ll res = 1;
    while(q > 0)
    {
        if(q % 2 == 1)
            res = (res * p) % 10;
        q = q >> 1;
        p = ((p % 10) * (p % 10)) % 10;
    }
    return res;
}
