#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define long long lld
#define llu unsigned long long
#define fo(i, n) for(i = 0; i < n; i++)
#define of(i, n) for(i = n - 1; i >= 0; i--)
#define mem(n, v) memset(n, v, sizeof( n ))
#define eps 1e-8
#define INF 5000
#define maxn 32
#define pi 3.141592653589793

void input();

int main()
{
    input();

    return 0;
}
void input()
{
    double x1, x2, x3, y1, y2, y3, perimeter, sperimeter, basardho, circumference, a, b, c, area;
    while(sf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3) != EOF)
    {
        a = sqrt( ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)) );
        b = sqrt( ((x1 - x3) * (x1 - x3)) + ((y1 - y3) * (y1 - y3)) );
        c = sqrt( ((x2 - x3) * (x2 - x3)) + ((y2 - y3) * (y2 - y3)) );

        perimeter = (a + b + c);
        sperimeter = perimeter / 2;

        area = sqrt(sperimeter * (sperimeter - a) * (sperimeter - b) * (sperimeter - c));
        basardho = ( (a * b * c) / ( 4 * area));
        circumference = 2 * pi * basardho;

        pf("%.2lf\n", circumference);
    }
}
