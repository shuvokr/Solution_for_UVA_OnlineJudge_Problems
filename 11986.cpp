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
long long kag, T;

int main()
{
    kag = 0;
    sf("%lld", &T);

    while(T--) procage();
    return 0;
}
void procage()
{
    long long n, count = 0;
    sf("%lld", &n);

    while(n > 0) n /= 2, count++;

    pf("Case %lld: %lld\n", ++kag, count);
}

