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
#define ll long long

static int res[1000002];
void save();

int main()
{
    save();
    int n;
    while(sf("%d", &n) != EOF)
    {
        if(n == -1) return 0;
        pf("%d\n", res[n]);
    }
}
void save()
{
    int a, b, c;
    double tmp;
    res[0] = 1;
    for(int i = 1; i < 1000001; i++)
    {
        tmp = sqrt(i);
        tmp = floor(i - tmp);
        a = int(tmp);

        tmp = log(i);
        b = int(tmp);

        tmp = sin(i) * sin(i) * i;
        c = int(tmp);

        res[i] = (res[a] + res[b] + res[c]) % 1000000;
    }
}
