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
#define foo(i, n) for(i = 1; i <= n; i++)
#define fa(i, n) for(i = 0; i < n - 1; i++)
#define oof(i, n) for(i = n - 1; i >= 0; i--)
#define max 100000000000000+1

void input();

int main()
{
    input();

    return 0;
}
void input()
{
    LD Q_sqr[10001], i, in, lim, div, a, b, res;
    fo(i, 10001) Q_sqr[i] = i * i;
    while(sf("%ld", &in) != EOF)
    {
        if(in == 2) lim = 99, div = 10;
        else if(in == 4) lim = 9999, div = 100;
        else if(in == 6) lim = 999999, div = 1000;
        else if(in == 8) lim = 99999999, div = 10000;

        for(i = 0; Q_sqr[i] <= lim; i++)
        {
            a = Q_sqr[i] / div;
            b = Q_sqr[i] % div;
            res = a + b;
            if(res * res == Q_sqr[i])
            {
                cout.width(in);
                cout.fill('0');
                cout << Q_sqr[i];
                puts("");
            }
        }
    }
}
