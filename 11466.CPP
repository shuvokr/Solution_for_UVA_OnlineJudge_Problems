#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define LLD long long
#define LD long
#define fo(i, n) for(i = 0; i < n; i++)
#define of(i, n) for(i = n - 1; i >= 0; i--)

void input();

int main()
{
    input();

    return 0;
}
void input()
{
    long long in, max = 0, res, sk, i, ck;
    while(sf("%lld", &in) != EOF)
    {
        if(in == 0) break;

        sk = abs(in);
        in = sk;
        ck = 0;

        for(i = 2; i * i <= sk; i++)
        {
            bool cheak = true;
            while(in % i == 0)
            {
                if(cheak)
                {
                    ck++;
                    cheak = false;
                }
                res = i;
                in /= i;
            }
        }
        if(in != 1 && in != sk) ck++, res = in;
        if(ck > 1) pf("%lld\n", res);
        else puts("-1");
    }
}

