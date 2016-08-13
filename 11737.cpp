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
#define LLD long long
#define fo(i, n) for(i = 0; i < n; ++i)

void input();

int main()
{
    input();

    return 0;
}
void input()
{
    int i, j , n, T, a, b, min = 10000000, kag = 0, tmp1, tmp2;
    vector <int> w;
    vector <int> h;
    bool ck;
    while(sf("%d", &T) != EOF)
    {
        w.clear();
        h.clear();
        ck = true; min = 10000000;
        fo(i, T)
        {
            sf("%d%d", &a, &b);
            tmp1 = abs(a - b);
            if(a == b) ck = false;
            if(tmp1 < min) min = tmp1;
            fo(j, i)
            {
                tmp1 = abs(a - h[j]);
                tmp2 = abs(b - w[j]);
                if(tmp1 < min) min = tmp1;
                if(tmp2 < min) min = tmp2;
            }
            w.push_back(a);
            h.push_back(b);
        }
        if(ck) min += min == 0;
        min++;
        min >>= 1;
        pf("Case %d : %d\n", ++kag, min);
    }
}
