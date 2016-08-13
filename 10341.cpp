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
#define E 2.7182818284

void input();
double cheaker(double ck);
double f(double x);

int p, q, r, s, t, u, i;

int main()
{
    input();

    return 0;
}
void input()
{
    double low, high, mid;
    while(sf("%d%d%d%d%d%d", &p, &q, &r, &s, &t, &u) != EOF)
    {
        if(f(1) * f(0) > 0) puts("No solution");
        else
        {
            high = 1, low = 0;
            if(f(1) < f(0)) high = 0, low = 1;

            while(cheaker(high - low) > 1e-9)
            {
                mid = (high + low) / 2.00;
                if(f(mid) < 0) low = mid;
                else high = mid;
            }
            pf("%.4lf\n", high + low);
            //printf("%.10lf\n", f(0.7071));

        }
    }
}
double cheaker(double ck)
{
    if(ck < 0) return -ck;
    return ck;
}
double f(double x) {return p*pow(E,-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;}
