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
long long N;

int main()
{
    while(sf("%lld", &N) != EOF) procage();
    return 0;
}

void procage()
{
    long long res = 1, counter, limit = N / 2;

    for(int i = 2; i <= N / i; i++)
    {
        if(N % i == 0)
        {
            counter = 1;
            while(N % i == 0) N /= i, counter *= i;
            res *= counter - (counter / i);
        }
    }
    if(N > 1)
        res *= N - 1;
    res = (res + 1) / 2;
    pf("%lld\n", res);
}


