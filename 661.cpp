#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#define sf scanf
#define pf printf

int main()
{
    int i = 0, n = 0, m = 0, c = 0, nary[22], mary[1000], tmp = 0, sum = 0, max = 0, z = 0;
    bool ck[1000];
    while(sf("%d%d%d", &n, &m, &c) != 0)
    {
        max = 0;
        sum = 0;
        if(n == 0 && m == 0 && c == 0) return 0;
        for(i = 1; i <= n; i++)
        {
            sf("%d", nary + i);
            ck[i] = true;
        }
        for(i = 0; i < m; i++)
        {
            sf("%d", &tmp);
            if(ck[tmp]) sum += nary[tmp], ck[tmp] = false;
            else sum -= nary[tmp], ck[tmp] = true;
            if(sum > max) max = sum;
        }
        if(max > c) pf("Sequence %d\n", ++z), puts("Fuse was blown."), puts("");
        else pf("Sequence %d\n", ++z), puts("Fuse was not blown."), pf("Maximal power consumption was %d amperes.\n\n", max);
    }
}
