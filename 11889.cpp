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
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf
template <class T> T power ( T a, T p ) { int res = 1, x = a; while ( p ) { if ( p & 1 ) res = res * x; x = x * x; p >>= 1; } return res;}

int main()
{
    long T, a, b, c, res, temp, i;
    sf("%ld", &T);
    while(T--)
    {
        res = 1; temp = 0;
        sf("%ld%ld", &a, &c);
        temp = a;
        if(c % a) puts("NO SOLUTION");
        else
        {
            int len = sqrt( c ) + 1, x = 0, y = 0;
            for(int i = 2; i < len; i++)
            {
                x = y = 0;
                while(c % i == 0)
                {
                    c /= i;
                    if(a % i == 0) a /= i, x++;
                    y++;
                }
                if(x < y)
                    res *= power(i, y);
            }
            if(c && (a % c)) res *= c;
            printf("%d\n", res);
        }
    }
    return 0;
}
