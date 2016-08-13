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

long long kag, n;

int main()
{
    int T; kag = 0;
    while(sf("%lld", &n) != EOF)
    {
        if(n == 0) return 0;
        procage();
    }
}
void procage()
{
    long long tot, res = 0, i = 1, ck;
    do
    {
        tot = n - i;
        if(tot % 2 != 0)
        {
            tot /= 2;
            res += (tot - i);
        }
        else
        {
            tot = (tot / 2) - 1;
            res += (tot - i);
        }
        i++;
        ck = i + (i + 1) + (i + 2);
    }while(ck <= n);
    pf("Case %lld: %lld\n", ++kag, res);
}
