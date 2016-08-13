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

int main()
{
    input();

    return 0;
}
void input()
{
    LLD T, kag, x1, y1, x2, y2, n, a, b;
    sf("%lld", &T);

    while(T--)
    {
        sf("%lld%lld", &kag, &n);
        while(kag--)
        {
            sf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
            if(x2 > n || y2 > n)
            {
                puts("no move"); continue;
            }
            if(x1 == x2 && y1 == y2)
            {
                puts("0"); continue;
            }
            a = abs(x1 - x2);
            b = abs(y1 - y2);
            if((x1 + y1) % 2 == 0 && (x2 + y2) % 2 != 0)
            {
                puts("no move"); continue;
            }
            if((x1 + y1) % 2 != 0 && (x2 + y2) % 2 == 0)
            {
                puts("no move"); continue;
            }
            if(a == b)
            {
                puts("1"); continue;
            }
            puts("2");

        }
    }
}
