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

int convertnumber();
char m[103], n[103];
int lenm, lenn;

int main()
{
    int p, q, i, cn;
    while(sf("%s%s", m, n) != EOF)
    {
        if(m[0] == '0' && n[0] == '0') return 0;
        lenm = strlen(m);
        lenn = strlen(n);
        p = m[lenm - 1] - 48;
        if(p == 0) puts("0");
        else if(p == 1) puts("1");
        else if(p == 5) puts("5");
        else if(p == 6) puts("6");
        else if(p == 9)
        {
            q = n[lenn - 1] - 48;
            if(q % 2 == 0) puts("1");
            else puts("9");
        }
        else if(p == 4)
        {
            q = n[lenn - 1] - 48;
            if(q % 2 == 0) puts("6");
            else puts("4");
        }
        else
        {
            if(p == 7)
            {
                cn = convertnumber();
                cn %= 4;
                if(cn == 0) puts("1");
                else if(cn == 1) puts("7");
                else if(cn == 2) puts("9");
                else if(cn == 3) puts("3");
            }
            else if(p == 2)
            {
                cn = convertnumber();
                cn %= 4;
                if(cn == 0) puts("6");
                else if(cn == 1) puts("2");
                else if(cn == 2) puts("4");
                else if(cn == 3) puts("8");
            }
            else if(p == 3)
            {
                cn = convertnumber();
                cn %= 4;
                if(cn == 0) puts("1");
                else if(cn == 1) puts("3");
                else if(cn == 2) puts("9");
                else if(cn == 3) puts("7");
            }
            if(p == 8)
            {
                cn = convertnumber();
                cn %= 4;
                if(cn == 0) puts("6");
                else if(cn == 1) puts("8");
                else if(cn == 2) puts("4");
                else if(cn == 3) puts("2");
            }
        }
    }
}

int convertnumber()
{
    char num[3];
    int ber;
    if(lenn > 1)
    {
        num[0] = n[lenn - 2];
        num[1] = n[lenn - 1];
    }
    else num[0] = n[0];
    sscanf(num, "%d", &ber);
    return ber;
}

