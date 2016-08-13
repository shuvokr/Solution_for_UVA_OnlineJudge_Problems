#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <string>
#include <sstream>
#include <iostream>
#include <stack>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define LLD long long
#define LD long
#define fo(i, n) for(i = 0; i < n; i++)
#define of(i, n) for(i = n - 1; i >= 0; i--)

void input();

int main()
{
    input();

    return 0;
}
void input()
{
    int n, len, tmp, i, res;
    stack <int> s;
    while(sf("%d", &n) != EOF)
    {
        if(n == 0) break;
        sf("%d%d", &len, &tmp);
        s.push(tmp); res = 0;
        for(i = 1; i < len; i++)
        {
            sf("%d", &tmp);
            if(tmp == s.top()) continue;
            else if(tmp < s.top()) s.pop(), s.push(tmp);
            else res += (tmp - s.top()), s.pop(); s.push(tmp);
        }
        res += (n - s.top());
        pf("%d\n", res);
    }
}
