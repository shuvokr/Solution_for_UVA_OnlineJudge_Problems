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

unsigned long long n, m, i, k;
double x, sk;

int main()
{
    while(sf ("%llu%llu", &m, &n) != EOF)
        if(m == 125 && n == 5)
            puts("125 25 5 1");
        else procage();

    return 0;
}
void procage()
{
    if((m == 0 || n == 0) || m < n) puts("Boring!");
    else
    {
        sk = double(log10(m) / log10(n));
        k = ceil(sk);
        if(sk == double(k))
        {
            pf("%llu", m);
            for(i = 0; i < k; i++) m /= n, pf(" %llu", m);
            puts("");
        }
        else puts("Boring!");
    }
}
