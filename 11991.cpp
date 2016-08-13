#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define ll long long

struct data
{
    vector <long long> v;
}res[1000002];

int main()
{
    ll n , m, x, y, i, j, cou;
    while(sf("%lld%lld", &n, &m) != EOF)
    {
        for(i = 0; i < 1000001; i++) res[i].v.clear();
        for(i = 1; i <= n; i++)
        {
            sf("%lld", &x);
            res[x].v.push_back(i);
        }

        for(i = 0; i < m; i++)
        {
            sf("%lld%lld", &x, &y);
            if(res[y].v.size() < x) puts("0");
            else pf("%lld\n", res[y].v[x - 1]);
        }
    }
    return 0;
}
