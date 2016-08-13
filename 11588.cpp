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

using namespace std;

#define sf scanf
#define pf printf
#define LLD long long
#define LD long
#define fo(i, n) for(i = 0; i < n; i++)
#define of(i, n) for(i = n - 1; i >= 0; i--)
#define mem(n) memset(n, 0, sizeof(n))

void input();

int main()
{
    input();

    return 0;
}
void input()
{
    long T, r, c, mx, mi, res, i, j, k, max, tot, kag = 0, cou;
    char in[21][21], ch;
    map <char, int> m;
    bool ck[130];

    sf("%ld", &T);
    while(T--)
    {
        sf("%ld%ld%ld%ld", &r, &c, &mx, &mi);
        getchar();
        mem(in);
        cou = 0;
        fo(i, r) gets(in[i]);
        max = 0;
        m.clear();
        memset(ck, false, 130);
        fo(i, r)
            fo(j, c)
            {
                m[in[i][j]]++;
                if(max < m[in[i][j]]) max = m[in[i][j]];
                ck[in[i][j]] = true;
            }
            cou = 0;
        for(i = 'A'; i <= 'Z'; i++)
            if(ck[i])
                {
                    if(m[i] == max) cou++;
                }
        max *= cou;
        tot = r * c;
        res = (max * mx) + ((abs(max - tot)) * mi);
        pf("Case %ld: %ld\n", ++kag, res);
    }
}
