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

long long procage(long long tmp);

int main()
{
    int T;
    long long L, H, result, number, ovuhS;
    sf ("%d", &T);
    while(T--)
    {
        result = 0;
        sf("%lld%lld", &L, &H);
        for(int i = L; i <= H; i++)
        {
            ovuhS = procage(i);
            if(result < ovuhS) result = ovuhS, number = i;
        }

        pf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n", L, H, number, result);
    }
    return 0;
}
long long procage(long long tmp)
{
    long long cou = 1, max = 1;;

    while(tmp % 2 == 0)
    {
        cou++;
        tmp = tmp >> 1;
    }
    max *= cou;
    cou = 1;
    for(int k = 3; k * k <= tmp; k += 2)
    {
        cou = 1;
        while(tmp % k == 0)
        {
            cou++;
            tmp /= k;
        }
        max *= cou;
    }
    if(tmp > 1) max *= 2;

    return max;
}
