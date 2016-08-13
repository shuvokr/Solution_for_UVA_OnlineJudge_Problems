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
    int T, n, i, k, activ, inactiv, noprocag, tim, kag = 0;
    sf("%d", &T);

    while(T--)
    {
        sf("%d%d%d", &n, &i, &k);
        activ = 0; inactiv = 0; noprocag = 0;

        while(n--)
        {
            sf("%d", &tim);
            if(tim < activ) noprocag++;
            else if(tim >= activ + i)
            {
                inactiv++;
                activ = tim + k;
            }

            if(activ < tim) activ = tim;
        }
        pf("Case %d: %d %d\n", ++kag, inactiv, noprocag);
    }
}
