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
#define ll long long
#define l long
#define ull unsigned long long
#define ul unsigned long

void CD();
void D();

char a[33], b[33], c[33], d[33];

int main()
{
    int i, tmp, x, y, T, cou;
    memset(a, 0, 33);
    memset(b, 0, 33);
    memset(c, 0, 33);
    memset(d, 0, 33);
    sf("%d", &T);
    bool ck = false;

    while(T--)
    {
        ck = false;
        sf("%s%s", a, b);
        pf("%s %s\n", a, b);
        CD();
        if(d[0] == '1') ck = true;
        if(!ck) D();

        while(1)
        {
            if(ck)
            {
                pf("%s overflow\n", c);
                break;
            }
            else if(strcmp(a, c) == 0 && strcmp(b, d) == 0) break;
            else
            {
                strcpy(a, c);
                strcpy(b, d);
                pf("%s %s\n", c, d);
                CD();
                if(d[0] == '1') ck = true;
                else ck = false;
                if(!ck) D();
            }
        }
        if(T != 0) puts("");
    }
    return 0;
}
void CD()
{
    int i, tmp, x, y, T, cou;
    for(i = 0; i < 31; i++)
    {
        x = a[i] - 48;
        y = b[i] - 48;

        tmp = x ^ y;
        c[i] = tmp + 48;

        tmp = x & y;
        d[i] = tmp + 48;
    }
}
void D()
{
    int tmp, x, i;
    tmp = d[30] - 48;
    d[30] = '0';
    for(i = 29; i >= 0; i--)
    {
        x = d[i] - 48;
        d[i] = tmp + 48;
        tmp = x;
    }
}
