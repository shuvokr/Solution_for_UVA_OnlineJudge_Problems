#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <list>
#include <algorithm>
#include <assert.h>

using namespace std;

#define sf scanf
#define pf printf
#define LLD long long
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
    LLD n, i, tmp;
    vector <LLD> in;
    in.clear();
    sf("%lld", &n);
    fo(i, n) sf("%lld", &tmp), in.push_back(tmp);
    //sort(in.begin(), in.end());
    LLD Q, Qin, p1, p2;
    vector <LLD> :: iterator low,up;
    sf("%lld", &Q);

    while(Q--)
    {
        sf("%lld", &Qin);
        low = lower_bound(in.begin(), in.end(), Qin);
        up = upper_bound(in.begin(), in.end(), Qin);
        p1 = low - in.begin();
        p2 = up - in.begin();

        if(p1 - 1 >= 0 && p1 - 1 < in.size()) pf("%lld ", in[p1 - 1]);
        else pf("X ");

        if(p2 >= 0 && p2 < in.size()) pf("%lld\n", in[p2]);
        else pf("X\n");
    }
}

